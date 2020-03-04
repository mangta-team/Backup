#include "Sync.hpp"

using namespace std;

// 1. "dest/root.relative_path()" 이 없으면 copy
// 2. root의 하위 디렉토리, 파일을 각각 조사
// 3. 하위 폴더가 있으면 sync(하위폴더, dest/root.filename()) 호출 (하위 폴더 반복)
// 4. 하위 폴더가 더이상 없으면 파일들 복사
void Sync::sync(const bfs::path& root, const bfs::path& dest)
{
	// 1. dest/root.filename()이 존재하지 않으면 생성
	bfs::path tmp_root = root;
	bfs::path tmp_dest = dest;
	if (!bfs::exists(tmp_dest /= root.filename()))
		bfs::create_directory(tmp_dest);

	// 2. root 하위 디렉토리, 파일 조사
	vector<bfs::path> directories;
	vector<bfs::path> files;
	BOOST_FOREACH(const bfs::path & path, make_pair(bfs::directory_iterator(root), bfs::directory_iterator()))
	{
		if (bfs::is_directory(path))
			directories.push_back(path);

		else
			files.push_back(path);
	}

	// 3. 하위 폴더에 재귀함수로 sync 호출
	if (!directories.empty())
	{
		for (int index = 0; index < directories.size(); index++)
		{
			tmp_dest = dest;
			sync(directories[index], tmp_dest /= root.filename() /= directories[index].filename());
		}

	}

	// 4. 파일 복사
	if (!files.empty())
	{
		for (int index = 0; index < files.size(); index++)
		{
			tmp_dest /= root.filename() /= files[index].filename();
			bfs::copy_file(files[index], tmp_dest, bfs::copy_option::overwrite_if_exists);
		}
	}

}

std::string Sync::get_dir_name(boost::filesystem::path& path)
{
	string dir_name = path.string();
	dir_name = dir_name.substr(dir_name.find_last_of("/") + 1);

	return dir_name;
}

void Sync::test(const bfs::path& root, const bfs::path& dest)
{
	vector<bfs::path> directories;
	bfs::path tmp_dest = dest;

	// directories 초기화
	directories.push_back("c:/AA");
	directories.push_back("c:/AB");
	directories.push_back("c:/AC");

	for (int index = 0; index < directories.size(); index++)
	{
		tmp_dest = dest;
	}
}
