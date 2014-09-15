#include "Zip.h"
#include <Windows.h>
#include <string>
#include <boost/shared_ptr.hpp>

Zip::Zip( const boost::filesystem::path& zip_path )
{
	zip_path_ = zip_path;

	zip_file_ = zipOpen(zip_path.string().c_str(), 0);

	if(!zip_file_)
		BOOST_THROW_EXCEPTION(std::exception("Couldn't open zip file."));
}

/*
boost::filesystem::path Zip::Difference( const boost::filesystem::path& path, const boost::filesystem::path& root_path )
{
	boost::filesystem::path difference;

	boost::filesystem::path temp_path(path);
	while (temp_path.has_parent_path() && !boost::filesystem::equivalent(temp_path, root_path))
	{
		difference = temp_path.filename() / difference;
		temp_path = temp_path.parent_path();
	}

	return difference;
}
*/

void Zip::WriteFile( const boost::filesystem::path& file_path )
{
	HANDLE file = ::CreateFile(file_path.wstring().c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (file == INVALID_HANDLE_VALUE)
		BOOST_THROW_EXCEPTION(std::exception("Couldn't open file."));

	//boost::filesystem::path difference = Difference(file_path, zip_path_);

	boost::shared_ptr<void> file_guard(file, [](HANDLE handle)
	{
		CloseHandle(handle);
	});

	int result = zipOpenNewFileInZip(zip_file_, file_path.string().c_str(), NULL, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_DEFAULT_COMPRESSION);
	if (ZIP_OK != result)
		BOOST_THROW_EXCEPTION(std::exception("Couldn't create file in zip."));

	boost::shared_ptr<void> zip_close_guard(nullptr, [=](void*)
	{
		zipCloseFileInZip(zip_file_);
	});

	const DWORD buffer_size = 256;
	char buffer[buffer_size];
	DWORD bytes_read = 0;

	while ((ZIP_OK == result) && ::ReadFile(file, buffer, buffer_size, &bytes_read, NULL) && bytes_read)
		result = zipWriteInFileInZip(zip_file_, buffer, bytes_read);
}

void Zip::Close()
{
	if(zip_file_)
		zipClose(zip_file_, 0);

	zip_file_ = nullptr;
}

Zip::~Zip()
{
	/*if(zip_file_)
		zipClose(zip_file_, 0);*/
	Close();
}
