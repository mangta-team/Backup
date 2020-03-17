#include "Sync.hpp"

using namespace std;

// 1. "dest/root.relative_path()" 이 없으면 copy
// 2. root의 하위 디렉토리, 파일을 각각 조사
// 3. 하위 폴더가 있으면 sync(하위폴더, dest/root.filename()) 호출 (하위 폴더 반복)
// 4. 하위 폴더가 더이상 없으면 파일들 복사
void backup::sync::sync(const bfs::path& root, const bfs::path& dest)
{
	// 1. dest/root.filename()이 존재하지 않으면 생성
	bfs::path tmp_root = root.generic_path();
	bfs::path tmp_dest = dest.generic_path();
	if (!bfs::exists(tmp_dest /= root.filename()))
		bfs::create_directory(tmp_dest.generic_path());

	// 2. root 하위 디렉토리, 파일 조사
	vector<bfs::path> directories;
	vector<bfs::path> files;
	BOOST_FOREACH(const bfs::path & path, make_pair(bfs::directory_iterator(root), bfs::directory_iterator()))
	{
		if (bfs::is_directory(path.generic_path()))
			directories.push_back(path.generic_path());

		else
			files.push_back(path.generic_path());
	}

	// 3. 하위 폴더에 재귀함수로 sync 호출
	if (!directories.empty())
	{
		for (int index = 0; index < directories.size(); index++)
		{
			tmp_dest = dest; tmp_dest /= root.filename();
			sync(directories[index], tmp_dest);
		}

	}

	// 4. 파일 복사
	if (!files.empty())
	{
		for (int index = 0; index < files.size(); index++)
		{
			tmp_dest = dest;
			tmp_dest /= root.filename() /= files[index].filename();
			bfs::copy_file(files[index], tmp_dest, bfs::copy_option::overwrite_if_exists);
		}
	}

}