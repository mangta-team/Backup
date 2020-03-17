#include "Dir_Center.hpp"

using namespace std;

void backup::dir_center::add(bfs::path source, bfs::path dest)
{
	bfs::ofstream write(PATH_TXT, ios::app);
	write << source.generic_string() << "-" << dest.generic_string() << endl;
	write.close();
}

void backup::dir_center::_delete()
{
	// �ܺ� ���Ͽ� ����� ��θ� ���, vector ������ ����
	// vector ������ ��������� �Լ� ����
	vector<string> str_paths;
	if (print(&str_paths))
		return;
	
	// ������ �ε����� �Է� �޴´�.
	while (1)
	{
		int index = 0;
		cout << "[������ �ε���] >> ";
		cin >> index;

		if (index >= 0 && index <= str_paths.size())
		{
			str_paths.erase(str_paths.begin() + index);
			break;
		}

		cout << "[�˸�] �߸��� ���� �Էµƽ��ϴ�. �ٽ� �Է����ּ���." << endl << endl;
	}

	bfs::ofstream write(PATH_TXT);
	for (int index = 0; index < str_paths.size(); index++)
	{
		write << str_paths[index] << endl;
	}
	write.close();
}

bool backup::dir_center::print()
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

bool backup::dir_center::print(std::vector<std::string>* paths)
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

bfs::path backup::dir_center::get_source_path(std::string str_paths)
{
	string str_source = str_paths.substr(0, str_paths.find("-"));
	bfs::path source = str_source;
	return source.generic_string();
}

bfs::path backup::dir_center::get_dest_path(std::string str_paths)
{
	string dest_source = str_paths.substr(str_paths.find("-") + 1);
	bfs::path dest = dest_source;
	return dest.generic_string();
}
