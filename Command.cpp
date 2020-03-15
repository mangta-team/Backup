#include "Command.hpp"

using namespace std;	

void tmp::command::command(const std::string command)
{
	if (!tmp::command::is_right(command))
	{
		cout << "[알림] >> 잘못된 명령어 입니다." << endl << endl;
		return;
	}

	switch (get_work(command))
	{
	case tmp::command::work::add :
		tmp::dir_center::add(tmp::command::get_root_path(command ,tmp::command::path_option::command), 
			tmp::command::get_dest_path(command, tmp::command::path_option::command));
		break;

	case tmp::command::work::_delete :
		tmp::dir_center::_delete();
		break;

	case tmp::command::work::print :
		tmp::dir_center::print();
		break;

	case tmp::command::work::sync :
		cout << "[알림] >> 다음 항목을 동기화 합니다." << endl << endl;

		{
			vector<string> paths; 
			if (tmp::dir_center::print(&paths))
				return;
		
			for (int index = 0; index < paths.size(); index++)
				tmp::sync::sync(tmp::command::get_root_path(paths[index], tmp::command::path_option::file),
					tmp::command::get_dest_path(paths[index], tmp::command::path_option::file));
		}

		cout << "[알림] >> 동기화가 끝났습니다." << endl << endl;

		break;

	case tmp::command::work::help :
		// 
		break;
	}
}

void tmp::command::command(const int argc,  char* argv[])
{
	tmp::system::Error_Code error_code;
	if (!tmp::command::is_right(argc, argv, error_code))
	{
		cout << "[알림] >> " << error_code.what() << endl << endl;
		return;
	}

	switch (tmp::command::get_work(argv))
	{
	case tmp::command::work::add:
		tmp::sync::sync(tmp::command::get_root_path(argc, argv), tmp::command::get_dest_path(argc, argv));
		break;

	case tmp::command::work::_delete:
		tmp::dir_center::_delete();
		break;

	case tmp::command::work::print:
		tmp::dir_center::print();
		break;

	case tmp::command::work::sync:
		cout << "[알림] >> 다음 항목을 동기화 합니다." << endl << endl;

		{
			vector<string> paths;
			if (tmp::dir_center::print(&paths))
				return;

			for (int index = 0; index < paths.size(); index++)
				tmp::sync::sync(tmp::command::get_root_path(paths[index], tmp::command::path_option::file),
					tmp::command::get_dest_path(paths[index], tmp::command::path_option::file));
		}

		cout << "[알림] >> 동기화가 끝났습니다." << endl << endl;

		break;

	case tmp::command::work::help:
		// 
		break;
	}
}

tmp::command::work tmp::command::get_work(const std::string command)
{
	string work = command.substr(0, command.find(COMMAND_TOKEN));

	if (work == "add")
		return tmp::command::work::add;

	else if (work == "delete")
		return tmp::command::work::_delete;

	else if (work == "print")
		return tmp::command::work::print;

	else if (work == "sync")
		return tmp::command::work::sync;

	else if (work == "help")
		return tmp::command::work::help;

	else
		return tmp::command::work::unknown;
}

tmp::command::work tmp::command::get_work(const std::string command, std::string* const str_work)
{
	string work = command.substr(0, command.find(COMMAND_TOKEN));
	*str_work = work;

	if (work == "add")
		return tmp::command::work::add;	

	else if (work == "delete")
		return tmp::command::work::_delete;

	else if (work == "print")
		return tmp::command::work::print;

	else if (work == "sync")
		return tmp::command::work::sync;

	else if (work == "help")
		return tmp::command::work::help;

	else
		return tmp::command::work::unknown;
}

tmp::command::work tmp::command::get_work( char* argv[])
{
	string work = *(argv + 1);

	if (work == "add")
		return tmp::command::work::add;

	else if (work == "delete")
		return tmp::command::work::_delete;

	else if (work == "print")
		return tmp::command::work::print;

	else if (work == "sync")
		return tmp::command::work::sync;

	else if (work == "help")
		return tmp::command::work::help;

	else
		return tmp::command::work::unknown;
}

bfs::path tmp::command::get_root_path(const std::string command, tmp::command::path_option path_option)
{
	bfs::path root;

	if (path_option == tmp::command::path_option::file)
		root = command.substr(0, command.find('-'));
	
	else
	{
		string str_root = command.substr(command.find("-root"), command.find("-dest") - command.find("-root"));
		str_root = str_root.substr(str_root.find_first_of('\"') + 1, 
			str_root.find_last_of('\"') - str_root.find_first_of('\"') - 1);
		root = str_root;
	}

	return root.generic_string();
}

bfs::path tmp::command::get_root_path(const int argc,  char* argv[])
{
	int index = 0;

	if (!strcmp(argv[2], "-root"))
		index = 3;

	else if (!strcmp(argv[4], "-root"))
		index = 5;

	string str_root(argv[index]);
	bfs::path root(str_root);
	return root.generic_string();
}

bfs::path tmp::command::get_dest_path(const std::string command, tmp::command::path_option path_option)
{
	bfs::path dest;

	if (path_option == tmp::command::path_option::file)
		dest = command.substr(command.find('-') + 1, command.size() - command.find("-dest") - 1);

	else
	{
		string str_dest = command.substr(command.find("-dest"), command.size() - command.find("-dest"));
		str_dest=str_dest.substr(str_dest.find_first_of('\"') + 1,
			str_dest.find_last_of('\"') - str_dest.find_first_of('\"') - 1);
		dest = str_dest;
	}

	return dest.generic_string();
}

bfs::path tmp::command::get_dest_path(const int argc,  char* argv[])
{
	int index = 0;

	if (!strcmp(argv[2], "-dest"))
		index = 3;

	else if (!strcmp(argv[4], "-dest"))
		index = 5;

	string str_dest(argv[index]);
	bfs::path dest(str_dest);
	return dest.generic_string();
}

bool tmp::command::is_right(const std::string command)
{
	string str_work;

	// work이 unknown일 때
	// 오류 문장이다.
	if (tmp::command::get_work(command) == tmp::command::work::unknown)
		return false;


	// work이 tmp::command::work::add 이 아닐 때(옵션이 필요하지 않는 work)
	// 명령어와 work의 길이가 같으면 옳바른 문장,
	// 아니면 오류 문장이다.
	else if (tmp::command::get_work(command, &str_work) != tmp::command::work::add)
	{		
		if (str_work.size() == command.size())
			return true;

		return false;
	}

	// tmp::command::work::add 일 때
	else
	{
		// "-root"의 위치가 "-dest"의 위치보다 높으면 
		// 오류 문장이다.
		if (command.find("-root") > command.find("-dest"))
			return false;

		// root와 dest의 경로가 존재하면 옳바른 문장,
		// 존재하지 않으면 오류 문장이다.
		if (bfs::exists(tmp::command::get_root_path(command, tmp::command::path_option::command)) &&
			bfs::exists(tmp::command::get_dest_path(command, tmp::command::path_option::command)))
			return true;

		return false;
	}
}

bool tmp::command::is_right(const int argc,  char* argv[], tmp::system::Error_Code& error_code)
{
	switch (tmp::command::get_work(argv))
	{
	// work이 unknown일 때 오류 문장이다.
	case  tmp::command::work::unknown:
		error_code.set_error_code(tmp::system::error_list::nonexistent_work);
		return false;

	// work이 print, delete, help (옵션이 없는 work)일 때 
	case tmp::command::work::print:
	case tmp::command::work::_delete:
	case tmp::command::work::help:
		// 명령어의 길이가 3개 이상이면 오류 문장이다.
		if (argc > 2)
		{
			error_code.set_error_code(tmp::system::error_list::number_of_element);
			return false;
		}

		return true;

	// work이 add일 때
	case tmp::command::work::add:
		// 명령어의 길이가 6개가 아니면 오류 문장이다.
		if (argc != 6)
		{
			error_code.set_error_code(tmp::system::error_list::number_of_element);
			return false;
		}

		// 옵션 자리에 -root, -dest가 없으면 오류 문장이다.
		if (!(strcmp(argv[2], "-root") || !strcmp(argv[4], "-root")) == false || (!strcmp(argv[2], "-dest") || !strcmp(argv[4], "-dest")) == false)
		{
			error_code.set_error_code(tmp::system::error_list::nonexistent_option);
			return false;
		}

		// 경로가 존재하지 않으면 오류 문장이다.
		if (!bfs::exists(tmp::command::get_root_path(argc, argv)) || !bfs::exists(tmp::command::get_dest_path(argc, argv)))
		{
			error_code.set_error_code(tmp::system::error_list::nonexistent_path);
			return false;
		}

		return true;
	}
}


