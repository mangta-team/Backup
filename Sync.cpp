#include "Sync.hpp"

using namespace std;

// 1. "dest/root.relative_path()" 이 없으면 copy
// 2. root의 하위 디렉토리, 파일을 각각 조사
// 3. 하위 폴더가 있으면 sync(하위폴더, dest/root.filename()) 호출 (하위 폴더 반복)
// 4. 하위 폴더가 더이상 없으면 파일들 복사
void Sync::sync(bfs::path root, bfs::path dest)
{
	// 1. dest/root.filename()이 존재하지 않으면 생성
	if (!bfs::exists(dest += root.filename()))
		bfs::create_directory(dest += root.filename());

	// 2. root 하위 디렉토리, 파일 조사
	vector<bfs::path> directories;
	vector<bfs::path> files;

	// 3. 하위 폴더에 재귀함수로 sync 호출
	if (!directories.empty())
	{
		for (int index = 0; index < directories.size(); index++)
		{

			sync(directories[index], dest += directories[index].relative_path());
		}

	}

	// 4. 파일 복사
	if (!files.empty())
	{
		bfs::path file_path;
		for (int index = 0; index < files.size(); index++)
		{
			
		}
	}

}

std::string Sync::get_dir_name(boost::filesystem::path& path)
{
	string dir_name = path.string();
	dir_name = dir_name.substr(dir_name.find_last_of("/") + 1);

	return dir_name;
}
