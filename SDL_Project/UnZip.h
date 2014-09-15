#include <unzip.h>
#include <boost/filesystem.hpp>
#include <vector>
#include <fstream>

class UnZip
{
public:
	typedef std::vector<unsigned char> Buffer;

	class InnerFile;
	friend InnerFile;

	class InnerFile
	{
	public:
		InnerFile();

		InnerFile(UnZip* zip_file, const boost::filesystem::path& file, size_t compressed_size, size_t uncompressed_size);

		boost::filesystem::path GetPath() const;

		size_t GetUncompressedSize() const;

		size_t GetCompressedSize() const;

		bool GetContent(Buffer* buffer);

		bool Extract(const boost::filesystem::path& where);

		bool IsDir()
		{
			std::string path_string = path_.string();
			char last_symbol = path_string[path_string.length() - 1];

			return (last_symbol == '\\' || last_symbol == '/');
		}

		bool IsFile()
		{
			return !IsDir();
		}

		operator bool();

	private:
		size_t compressed_size_;
		size_t uncompressed_size_;
		UnZip* zip_file_;
		boost::filesystem::path path_;
		bool is_dir_;
	};

public:

	UnZip(const boost::filesystem::path& zip_path);

	~UnZip();

	InnerFile GetNextFile();

	InnerFile GetFile(const boost::filesystem::path& file);

private:
	InnerFile GetFile();

	bool GoToFile(const boost::filesystem::path& file);

	bool GoToNextFile();

	void ReadFile(const boost::filesystem::path& file, Buffer* buffer);

	void ExtractFile(const boost::filesystem::path& file_name, const boost::filesystem::path& where);

private:
	size_t file_index_;
	unzFile zip_file_;
	boost::filesystem::path zip_path_;
};