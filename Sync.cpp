#include "Sync.hpp"

using namespace std;

// 1. "dest/root.relative_path()" �� ������ copy
// 2. root�� ���� ���丮, ������ ���� ����
// 3. ���� ������ ������ sync(��������, dest/root.filename()) ȣ�� (���� ���� �ݺ�)
// 4. ���� ������ ���̻� ������ ���ϵ� ����
void backup::sync::sync(const bfs::path& root, const bfs::path& dest)
{
	// 1. dest/root.filename()�� �������� ������ ����
	bfs::path tmp_root = root.generic_path();
	bfs::path tmp_dest = dest.generic_path();
	if (!bfs::exists(tmp_dest /= root.filename()))
		bfs::create_directory(tmp_dest.generic_path());

	// 2. root ���� ���丮, ���� ����
	vector<bfs::path> directories;
	vector<bfs::path> files;
	BOOST_FOREACH(const bfs::path & path, make_pair(bfs::directory_iterator(root), bfs::directory_iterator()))
	{
		if (bfs::is_directory(path.generic_path()))
			directories.push_back(path.generic_path());

		else
			files.push_back(path.generic_path());
	}

	// 3. ���� ������ ����Լ��� sync ȣ��
	if (!directories.empty())
	{
		for (int index = 0; index < directories.size(); index++)
		{
			tmp_dest = dest; tmp_dest /= root.filename();
			sync(directories[index], tmp_dest);
		}

	}

	// 4. ���� ����
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