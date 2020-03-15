#include "Command.hpp"

using namespace std;	

void tmp::command::command(const std::string command)
{
	if (!tmp::command::is_right(command))
	{
		cout << "[�˸�] >> �߸��� ��ɾ� �Դϴ�." << endl << endl;
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
		cout << "[�˸�] >> ���� �׸��� ����ȭ �մϴ�." << endl << endl;

		{
			vector<string> paths; 
			if (tmp::dir_center::print(&paths))
				return;
		
			for (int index = 0; index < paths.size(); index++)
				tmp::sync::sync(tmp::command::get_root_path(paths[index], tmp::command::path_option::file),
					tmp::command::get_dest_path(paths[index], tmp::command::path_option::file));
		}

		cout << "[�˸�] >> ����ȭ�� �������ϴ�." << endl << endl;

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
		cout << "[�˸�] >> " << error_code.what() << endl << endl;
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
		cout << "[�˸�] >> ���� �׸��� ����ȭ �մϴ�." << endl << endl;

		{
			vector<string> paths;
			if (tmp::dir_center::print(&paths))
				return;

			for (int index = 0; index < paths.size(); index++)
				tmp::sync::sync(tmp::command::get_root_path(paths[index], tmp::command::path_option::file),
					tmp::command::get_dest_path(paths[index], tmp::command::path_option::file));
		}

		cout << "[�˸�] >> ����ȭ�� �������ϴ�." << endl << endl;

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

	// work�� unknown�� ��
	// ���� �����̴�.
	if (tmp::command::get_work(command) == tmp::command::work::unknown)
		return false;


	// work�� tmp::command::work::add �� �ƴ� ��(�ɼ��� �ʿ����� �ʴ� work)
	// ��ɾ�� work�� ���̰� ������ �ǹٸ� ����,
	// �ƴϸ� ���� �����̴�.
	else if (tmp::command::get_work(command, &str_work) != tmp::command::work::add)
	{		
		if (str_work.size() == command.size())
			return true;

		return false;
	}

	// tmp::command::work::add �� ��
	else
	{
		// "-root"�� ��ġ�� "-dest"�� ��ġ���� ������ 
		// ���� �����̴�.
		if (command.find("-root") > command.find("-dest"))
			return false;

		// root�� dest�� ��ΰ� �����ϸ� �ǹٸ� ����,
		// �������� ������ ���� �����̴�.
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
	// work�� unknown�� �� ���� �����̴�.
	case  tmp::command::work::unknown:
		error_code.set_error_code(tmp::system::error_list::nonexistent_work);
		return false;

	// work�� print, delete, help (�ɼ��� ���� work)�� �� 
	case tmp::command::work::print:
	case tmp::command::work::_delete:
	case tmp::command::work::help:
		// ��ɾ��� ���̰� 3�� �̻��̸� ���� �����̴�.
		if (argc > 2)
		{
			error_code.set_error_code(tmp::system::error_list::number_of_element);
			return false;
		}

		return true;

	// work�� add�� ��
	case tmp::command::work::add:
		// ��ɾ��� ���̰� 6���� �ƴϸ� ���� �����̴�.
		if (argc != 6)
		{
			error_code.set_error_code(tmp::system::error_list::number_of_element);
			return false;
		}

		// �ɼ� �ڸ��� -root, -dest�� ������ ���� �����̴�.
		if (!(strcmp(argv[2], "-root") || !strcmp(argv[4], "-root")) == false || (!strcmp(argv[2], "-dest") || !strcmp(argv[4], "-dest")) == false)
		{
			error_code.set_error_code(tmp::system::error_list::nonexistent_option);
			return false;
		}

		// ��ΰ� �������� ������ ���� �����̴�.
		if (!bfs::exists(tmp::command::get_root_path(argc, argv)) || !bfs::exists(tmp::command::get_dest_path(argc, argv)))
		{
			error_code.set_error_code(tmp::system::error_list::nonexistent_path);
			return false;
		}

		return true;
	}
}


