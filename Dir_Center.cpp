#include "Dir_Center.hpp"

using namespace std;

Dir::Dir()
{
	this->set_ptr_root(new bfs::path); 
	this->set_ptr_dest(new bfs::path);
}

Dir::Dir(bfs::path root, bfs::path dest)
{
	this->set_ptr_root(new bfs::path); this->set_ptr_dest(new bfs::path);
	this->set_root(root); this->set_dest(dest);
}

void Dir_Center::init()
{
	this->set_ptr_dir(new std::vector<Dir*>);

	bfs::ifstream read_file(PATH_TXT);
	if (read_file.is_open())
	{
		string paths; // root - dest 로 구성된 경로 문자열
		bfs::path root;	// paths에서 root를 추출
		bfs::path dest; // paths에서 dest를 추출
		int token_index; // paths에서 토큰인"-"의 인덱스값
		
		while (!read_file.eof())
		{
			getline(read_file, paths);
			
			if (paths == "") break;

			token_index = paths.find("-");
			root = paths.substr(0, token_index);
			dest = paths.substr(token_index + 1);

			this->ptr_dir->push_back(new Dir);
			this->ptr_dir->back()->set_root(root);
			this->ptr_dir->back()->set_dest(dest);
		}
	}

	else
	{
		cout << "[알림] 경로 파일을 찾지 못했습니다. 경로 파일을 재생성합니다." << endl;

		bfs::ofstream write_file(PATH_TXT);
		if (!write_file.is_open())
		{
			cout << "[알림] 파일을 생성하지 못했습니다. 시스템을 종료합니다." << endl;
			exit(0);
		}
	}
}

void Dir_Center::shutdown()
{
	bfs::ofstream write_file(PATH_TXT);
	if (write_file.is_open())
	{
		for (int index = 0; index < this->ptr_dir->size(); index++)
		{
			write_file << this->ptr_dir->at(index)->get_root() << "-" << this->ptr_dir->at(index)->get_dest() << endl;
		}
	}

	else
	{
		cout << "[알림] 파일을 읽지 못했습니다. 경로가 저장되지 않았습니다." << endl;
	}
}

