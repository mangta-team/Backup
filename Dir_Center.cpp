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
	// 외부 파일에 저장된 경로를 출력, vector 변수에 저장
	vector<string> paths;

	// vector 변수가 비어있으면 함수 종료
	if (print(&paths))
		return;
	
	// 삭제할 인덱스를 입력 받는다.
	while (1)
	{
		int index = 0;
		cout << "[삭제할 인덱스] >> ";
		cin >> index;

		if (index >= 0 && index <= paths.size())
		{
			paths.erase(paths.begin() + index);
			break;
		}

		cout << "[알림] 잘못된 값이 입력됐습니다. 다시 입력해주세요." << endl << endl;
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
		cout << "[알림] 경로가 없습니다." << endl;
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
		cout << "[알림] 경로가 없습니다." << endl;
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
