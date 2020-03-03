#include "Sync.hpp"

using namespace std;

// 1. "dest/root.relative_path()" �� ������ copy
// 2. root�� ���� ���丮, ������ ���� ����
// 3. ���� ������ ������ sync(��������, dest/root.filename()) ȣ�� (���� ���� �ݺ�)
// 4. ���� ������ ���̻� ������ ���ϵ� ����
void Sync::sync(bfs::path root, bfs::path dest)
{
	// 1. dest/root.filename()�� �������� ������ ����
	if (!bfs::exists(dest += root.filename()))
		bfs::create_directory(dest += root.filename());

	// 2. root ���� ���丮, ���� ����
	vector<bfs::path> directories;
	vector<bfs::path> files;

	// 3. ���� ������ ����Լ��� sync ȣ��
	if (!directories.empty())
	{
		for (int index = 0; index < directories.size(); index++)
		{

			sync(directories[index], dest += directories[index].relative_path());
		}

	}

	// 4. ���� ����
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
