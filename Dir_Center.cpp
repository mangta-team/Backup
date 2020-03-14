#include "Dir_Center.hpp"

using namespace std;

void tmp::dir_center::add(bfs::path root, bfs::path dest)
{
	bfs::ofstream write(PATH_TXT, ios::app);
	write << root.generic_string() << "-" << dest.generic_string() << endl;
	write.close();
}

void tmp::dir_center::_delete()
{
	// �ܺ� ���Ͽ� ����� ��θ� ���, vector ������ ����
	vector<string> paths;

	// vector ������ ��������� �Լ� ����
	if (print(&paths))
		return;
	
	// ������ �ε����� �Է� �޴´�.
	while (1)
	{
		int index = 0;
		cout << "[������ �ε���] >> ";
		cin >> index;

		if (index >= 0 && index <= paths.size())
		{
			paths.erase(paths.begin() + index);
			break;
		}

		cout << "[�˸�] �߸��� ���� �Էµƽ��ϴ�. �ٽ� �Է����ּ���." << endl << endl;
	}

	bfs::ofstream write(PATH_TXT);
	for (int index = 0; index < paths.size(); index++)
	{
		write << paths[index] << endl;
	}
	write.close();
}

bool tmp::dir_center::print()
{
	if (bfs::file_size(PATH_TXT) == 0)
	{
		cout << "[�˸�] ��ΰ� �����ϴ�." << endl;
		return 1;
	}

	bfs::ifstream read(PATH_TXT);
	for (int index = 0; !read.eof(); index++)
	{
		string paths;
		getline(read, paths);

		if (paths != "")
			cout << "[" << index << "] " << paths << endl;
	}
	read.close();

	return 0;
}

bool tmp::dir_center::print(std::vector<std::string>* paths)
{
	if (bfs::file_size(PATH_TXT) == 0)
	{
		cout << "[�˸�] ��ΰ� �����ϴ�." << endl;
		return 1;
	}
		

	bfs::ifstream read(PATH_TXT);
	for (int index = 0; !read.eof(); index++)
	{
		string str_paths;
		getline(read, str_paths);

		if (str_paths != "")
		{
			paths->push_back(str_paths);
			cout << "[" << index << "] " << str_paths << endl;
		}
	}
	read.close();

	return 0;
}
