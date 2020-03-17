#include "Command.hpp"

using namespace std;	

void backup::command::command(const std::string command)
{
	if (!backup::command::is_right(command))
	{
		cout << "[알림] >> 잘못된 명령어 입니다." << endl << endl;
		return;
	}

	switch (get_work(command))
	{
	case backup::command::work::add :
		backup::dir_center::add(backup::command::get_root_path(command ,backup::command::path_option::command), 
			backup::command::get_dest_path(command, backup::command::path_option::command));
		break;

	case backup::command::work::_delete :
		backup::dir_center::_delete();
		break;

	case backup::command::work::print :
		backup::dir_center::print();
		break;

	case backup::command::work::sync :
		cout << "[알림] >> 다음 항목을 동기화 합니다." << endl << endl;

		{
			vector<string> paths; 
			if (backup::dir_center::print(&paths))
				return;
		
			for (int index = 0; index < paths.size(); index++)
				backup::sync::sync(backup::command::get_root_path(paths[index], backup::command::path_option::file),
					backup::command::get_dest_path(paths[index], backup::command::path_option::file));
		}

		cout << "[알림] >> 동기화가 끝났습니다." << endl << endl;

		break;

	case backup::command::work::help :
		// 
		break;
	}
}

void backup::command::command(std::vector<std::string> vector_argv)
{
	backup::system::Error_Code error_code;
	if (!backup::command::is_right(vector_argv, error_code))
	{
		cout << "[알림] >> " << error_code.what() << endl << endl;
		return;
	}

	switch (backup::command::get_work(vector_argv))
	{
	case backup::command::work::add:
		backup::dir_center::add(backup::command::get_root_path(vector_argv), backup::command::get_dest_path(vector_argv));
		break;

	case backup::command::work::_delete:
		backup::dir_center::_delete();
		break;

	case backup::command::work::print:
		backup::dir_center::print();
		break;

	case backup::command::work::sync:
		cout << "[알림] >> 다음 항목을 동기화 합니다." << endl << endl;

		{
			vector<string> paths;
			if (backup::dir_center::print(&paths))
				return;

			for (int index = 0; index < paths.size(); index++)
				backup::sync::sync(backup::command::get_root_path(paths[index], backup::command::path_option::file),
					backup::command::get_dest_path(paths[index], backup::command::path_option::file));
		}

		cout << "[알림] >> 동기화가 끝났습니다." << endl << endl;

		break;

	case backup::command::work::help:
		// 
		break;
	}
}

backup::command::work backup::command::get_work(const std::string command)
{
	string work = command.substr(0, command.find(COMMAND_TOKEN));

	if (work == "add")
		return backup::command::work::add;

	else if (work == "delete")
		return backup::command::work::_delete;

	else if (work == "print")
		return backup::command::work::print;

	else if (work == "sync")
		return backup::command::work::sync;

	else if (work == "help")
		return backup::command::work::help;

	else
		return backup::command::work::unknown;
}

backup::command::work backup::command::get_work(const std::string command, std::string* const str_work)
{
	string work = command.substr(0, command.find(COMMAND_TOKEN));
	*str_work = work;

	if (work == "add")
		return backup::command::work::add;	

	else if (work == "delete")
		return backup::command::work::_delete;

	else if (work == "print")
		return backup::command::work::print;

	else if (work == "sync")
		return backup::command::work::sync;

	else if (work == "help")
		return backup::command::work::help;

	else
		return backup::command::work::unknown;
}

backup::command::work backup::command::get_work(std::vector<std::string> vector_argv)
{
	string work = vector_argv[1];

	if (work == "add")
		return backup::command::work::add;

	else if (work == "delete")
		return backup::command::work::_delete;

	else if (work == "print")
		return backup::command::work::print;

	else if (work == "sync")
		return backup::command::work::sync;

	else if (work == "help")
		return backup::command::work::help;

	else
		return backup::command::work::unknown;
}

bfs::path backup::command::get_root_path(const std::string command, backup::command::path_option path_option)
{
	bfs::path root;

	if (path_option == backup::command::path_option::file)
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

bfs::path backup::command::get_root_path(std::vector<std::string> vector_argv)
{
	int index = 0;

	if (vector_argv[2] == "-root")
		index = 3;

	else if (vector_argv[4] == "-root")
		index = 5;

	bfs::path root(vector_argv[index]);
	return root.generic_string();
}

bfs::path backup::command::get_dest_path(const std::string command, backup::command::path_option path_option)
{
	bfs::path dest;

	if (path_option == backup::command::path_option::file)
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

bfs::path backup::command::get_dest_path(std::vector<std::string> vector_argv)
{
	int index = 0;

	if (vector_argv[2] == "-dest")
		index = 3;

	else if (vector_argv[4] == "-dest")
		index = 5;

	bfs::path dest(vector_argv[index]);
	return dest.generic_string();
}

bool backup::command::is_right(const std::string command)
{
	string str_work;

	// work이 unknown일 때
	// 오류 문장이다.
	if (backup::command::get_work(command) == backup::command::work::unknown)
		return false;


	// work이 backup::command::work::add 이 아닐 때(옵션이 필요하지 않는 work)
	// 명령어와 work의 길이가 같으면 옳바른 문장,
	// 아니면 오류 문장이다.
	else if (backup::command::get_work(command, &str_work) != backup::command::work::add)
	{		
		if (str_work.size() == command.size())
			return true;

		return false;
	}

	// backup::command::work::add 일 때
	else
	{
		// "-root"의 위치가 "-dest"의 위치보다 높으면 
		// 오류 문장이다.
		if (command.find("-root") > command.find("-dest"))
			return false;

		// root와 dest의 경로가 존재하면 옳바른 문장,
		// 존재하지 않으면 오류 문장이다.
		if (bfs::exists(backup::command::get_root_path(command, backup::command::path_option::command)) &&
			bfs::exists(backup::command::get_dest_path(command, backup::command::path_option::command)))
			return true;

		return false;
	}
}

bool backup::command::is_right(std::vector<std::string> vector_argv, backup::system::Error_Code& error_code)
{
	if (vector_argv.size() == 1)
	{
		error_code.set_error_code(backup::system::error_list::number_of_element);
		return false;
	}

	switch (backup::command::get_work(vector_argv))
	{
	// work이 unknown일 때 오류 문장이다.
	case  backup::command::work::unknown:
		error_code.set_error_code(backup::system::error_list::nonexistent_work);
		return false;

	// work이 print, delete, help (옵션이 없는 work)일 때 
	case backup::command::work::print:
	case backup::command::work::_delete:
	case backup::command::work::sync:
	case backup::command::work::help:
		// 명령어의 길이가 2가 아니면 오류 문장이다.
		if (vector_argv.size() != 2)
		{
			error_code.set_error_code(backup::system::error_list::number_of_element);
			return false;
		}

		return true;

	// work이 add일 때
	case backup::command::work::add:
		// 명령어의 길이가 6개가 아니면 오류 문장이다.
		if (vector_argv.size() != 6)
		{
			error_code.set_error_code(backup::system::error_list::number_of_element);
			return false;
		}

		// 옵션 자리에 -root, -dest가 없으면 오류 문장이다.
		if (!((vector_argv[2] == "-root") || (vector_argv[4] == "-root") && ((vector_argv[2] == "-dest") || (vector_argv[4] == "-dest"))))
		{
			error_code.set_error_code(backup::system::error_list::nonexistent_option);
			return false;
		}

		// 경로가 존재하지 않으면 오류 문장이다.
		if (!bfs::exists(backup::command::get_root_path(vector_argv)) || !bfs::exists(backup::command::get_dest_path(vector_argv)))
		{
			error_code.set_error_code(backup::system::error_list::nonexistent_path);
			return false;
		}

		return true;
	}
}


