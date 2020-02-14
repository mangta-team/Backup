#include "Sync.hpp"

using namespace std;

void Sync::play_sync(boost::filesystem::path& root, boost::filesystem::path& dest)
{
	if (boost::filesystem::is_directory(dest))
	get_dir_name(root);

}

std::string Sync::get_dir_name(boost::filesystem::path& path)
{
	string dir_name = path.string();
	dir_name = dir_name.substr(dir_name.find_last_of("/") + 1);

	return dir_name;
}
