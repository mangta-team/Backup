#include "Command.hpp"

using namespace std;	

// add -root "c:/" -dest "d:/"
// 01234567890123456789
// 토큰 문자열 자르기
// 다음 문자열 삭제
// 토큰 문자열 벡터에 넣기
std::vector<std::string> backup::command::get_command()
{
	string str_command;
	getline(cin, str_command);
	//cout << str_command << endl;

	vector<string> vector_argv;
	for (; ;)
	{
		int token_index;
		string token_command;

		// 토큰 문자열 자르기
		token_command = str_command.substr(0, str_command.find(" "));
		if (str_command[0] == '\"')
			token_command = str_command.substr(1, str_command.find('\"', 1) - 1);

		// push_back
		vector_argv.push_back(token_command);

		// 토큰 인덱스 계산
		token_index = str_command.find(" ") + 1;
		if (str_command[0] == '\"')
			token_index = str_command.find('\"', str_command.find('\"', 1) + 1);
		
		// 마지막 명령인지 확인
		if (token_index < 0)
			break;

		// 토큰 문자열 삭제
		str_command = str_command.substr(token_index);
	}

	return vector_argv;
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
		backup::dir_center::add(backup::command::get_source_path(vector_argv), backup::command::get_dest_path(vector_argv));
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
			vector<string> str_paths;
			if (backup::dir_center::print(&str_paths))
				return;

			for (int index = 0; index < str_paths.size(); index++)
				backup::sync::sync(backup::dir_center::get_source_path(str_paths[index]),
					backup::dir_center::get_dest_path(str_paths[index]));
		}

		cout << "[알림] >> 동기화가 끝났습니다." << endl << endl;

		break;

	case backup::command::work::help:
		// 
		break;
	}
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

bfs::path backup::command::get_source_path(std::vector<std::string> vector_argv)
{
	int index = 0;

	if (vector_argv[2] == "-root")
		index = 3;

	else if (vector_argv[4] == "-root")
		index = 5;

	bfs::path root(vector_argv[index]);
	return root.generic_string();
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


bool backup::command::is_right(std::vector<std::string> vector_argv, backup::system::Error_Code& error_code)
{
	// main의 argv의 개수가 1개 이면 오류 문장이다.
	if (vector_argv.size() == 1)
	{
		error_code.set_error_code(backup::system::error_list::number_of_element);
		return false;
	}

	switch (backup::command::get_work(vector_argv))
	{

	// work == unknown일 때 오류 문장이다.
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
		if (!bfs::exists(backup::command::get_source_path(vector_argv)) || !bfs::exists(backup::command::get_dest_path(vector_argv)))
		{
			error_code.set_error_code(backup::system::error_list::nonexistent_path);
			return false;
		}

		return true;
	}
}


