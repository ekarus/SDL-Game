#include "UnZip.h"
#include <boost/shared_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include <string>



void UnZip::ExtractFile( const boost::filesystem::path& file_name, const boost::filesystem::path& where )
{
	Buffer buffer;

	ReadFile(file_name, &buffer);

	boost::system::error_code error_code;
	boost::filesystem::create_directories(where.parent_path(), error_code);

	std::ofstream out(where.string(), std::ios::out | std::ios::binary);

	boost::shared_ptr<std::ofstream> file_guard(&out, [](std::ofstream* file)
	{
		if(file->is_open())
			file->close();
	});

	out.write(reinterpret_cast<const char*>(&buffer[0]), buffer.size());
}

void UnZip::ReadFile( const boost::filesystem::path& file, Buffer* buffer )
{
	if (!GoToFile(file))
		BOOST_THROW_EXCEPTION(std::exception("Couldn't locale file in zip."));

	const int buffer_size = 256;
	int read_size = 0;

	Buffer::value_type temp_buffer[buffer_size];

	if (unzOpenCurrentFile(zip_file_) != UNZ_OK)
		BOOST_THROW_EXCEPTION(std::exception("Couldn't open file in zip."));

	boost::shared_ptr<void> current_file_guard(nullptr, [this](void*)
	{
		unzCloseCurrentFile(zip_file_);
	});

	while ((read_size = unzReadCurrentFile(zip_file_, temp_buffer, buffer_size)) > 0)
	{
		buffer->insert(buffer->end(), temp_buffer, temp_buffer + read_size);
	}
}

bool UnZip::GoToNextFile()
{
	return unzGoToNextFile(zip_file_) == UNZ_OK;
}

bool UnZip::GoToFile( const boost::filesystem::path& file )
{
	return unzLocateFile(zip_file_, file.string().c_str(), 1) == UNZ_OK;
}

UnZip::InnerFile UnZip::GetFile()
{
	unz_file_info_s file_info = {0};

	std::string file_name;
	file_name.resize(256);

	if (unzGetCurrentFileInfo(zip_file_, &file_info, &file_name[0], static_cast<unsigned long>(file_name.size()), NULL, 0, NULL, 0) != UNZ_OK)
		BOOST_THROW_EXCEPTION(std::exception("Couldn't get current file info."));

	size_t length = file_name.find_first_of('\0');
	if(length != std::string::npos)
		file_name = file_name.substr(0, length);

	InnerFile file(this, file_name, file_info.compressed_size, file_info.uncompressed_size);

	return file;
}

UnZip::InnerFile UnZip::GetFile( const boost::filesystem::path& file )
{
	if(GoToFile(file))
		return GetFile();
	else
		BOOST_THROW_EXCEPTION(std::exception("Couldn't locale file in zip."));
}

UnZip::InnerFile UnZip::GetNextFile()
{
	if (0 != file_index_)
	{
		if (!GoToNextFile())
			return InnerFile();
	}

	InnerFile file = GetFile();

	++file_index_;

	return file;
}

UnZip::~UnZip()
{
	if (zip_file_)
		unzClose(zip_file_);
}

UnZip::UnZip( const boost::filesystem::path& zip_path ) : file_index_(0)
{
	zip_path_ = zip_path;

	zip_file_ = unzOpen(zip_path.string().c_str());

	if (!zip_file_)
		BOOST_THROW_EXCEPTION(std::exception("Couldn't open zip file."));

	if (unzGoToFirstFile(zip_file_) != UNZ_OK)
		BOOST_THROW_EXCEPTION(std::exception("Couldn't find first file in zip."));
}

UnZip::InnerFile::operator bool()
{
	return zip_file_ != nullptr;
}

bool UnZip::InnerFile::Extract( const boost::filesystem::path& where )
{
	if (zip_file_)
	{
		InnerFile prev_file = zip_file_->GetFile();

		zip_file_->GoToFile(path_);
		zip_file_->ExtractFile(path_, where);
		zip_file_->GoToFile(prev_file.GetPath());

		return true;
	}

	return false;
}

bool UnZip::InnerFile::GetContent( Buffer* buffer )
{
	if (zip_file_)
	{
		InnerFile prev_file = zip_file_->GetFile();

		zip_file_->ReadFile(path_, buffer);
		zip_file_->GoToFile(prev_file.GetPath());

		return true;
	}

	return false;
}

size_t UnZip::InnerFile::GetCompressedSize() const
{
	return compressed_size_;
}

size_t UnZip::InnerFile::GetUncompressedSize() const
{
	return uncompressed_size_;
}

boost::filesystem::path UnZip::InnerFile::GetPath() const
{
	return path_;
}

UnZip::InnerFile::InnerFile( UnZip* zip_file, const boost::filesystem::path& file, size_t compressed_size, size_t uncompressed_size ) :
	zip_file_(zip_file),
	path_(file),
	compressed_size_(compressed_size),
	uncompressed_size_(uncompressed_size)
{

}

UnZip::InnerFile::InnerFile() : 
	zip_file_(nullptr),
	path_(),
	compressed_size_(0),
	uncompressed_size_(0)
{

}
