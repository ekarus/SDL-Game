#include <zip.h>
#include <boost/filesystem.hpp>

class Zip
{
public:
	Zip(const boost::filesystem::path& zip_path);

	~Zip();

	void Close();

	void WriteFile(const boost::filesystem::path& file_path);

private:
	boost::filesystem::path Difference(const boost::filesystem::path& path, const boost::filesystem::path& root_path);

private:
	zipFile zip_file_;
	boost::filesystem::path zip_path_;
};