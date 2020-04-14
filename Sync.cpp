#include "Sync.hpp"

using namespace std;

// 1. "dest/source.relative_path()"�� ������ copy
// 2. source�� ���� ���丮, ������ ���� ����
// 3. ���� ������ ������ sync(��������, dest/source.filename()) ȣ�� (���� ���� �ݺ�)
// 4. ���� ������ ���̻� ������ ���ϵ� ����
void backup::sync::sync(const bfs::path& source, const bfs::path& dest)
{
	// 1. dest/source.filename()�� �������� ������ ����
	bfs::path tmp_source = source.generic_path();
	bfs::path tmp_dest = dest.generic_path();
	if (!bfs::exists(tmp_dest /= source.filename()))
		bfs::create_directory(tmp_dest.generic_path());

	// 2. source ���� ���丮, ���� ����
	vector<bfs::path> directories;
	vector<bfs::path> files;
	BOOST_FOREACH(const bfs::path & path, make_pair(bfs::directory_iterator(source), bfs::directory_iterator()))
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
			tmp_dest = dest; tmp_dest /= source.filename();
			sync(directories[index], tmp_dest);
		}

	}

	// 4. ���� ����
	if (!files.empty())
	{
		for (int index = 0; index < files.size(); index++)
		{
			tmp_dest = dest;
			tmp_dest /= source.filename() /= files[index].filename();
			bfs::copy_file(files[index], tmp_dest, bfs::copy_option::overwrite_if_exists);
		}
	}

}