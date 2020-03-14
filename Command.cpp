#include "Command.hpp"

using namespace std;	

void tmp::command::command(const std::string command)
{
	if (!tmp::command::is_right(command))
	{
		cout << "[�˸�] >> �߸��� ��ɾ� �Դϴ�." << endl << endl;
		return;
	}

	switch (get_action(command))
	{
	case tmp::command::action::add :
		tmp::dir_center::add(tmp::command::get_root_path(command ,tmp::command::path_option::command), 
			tmp::command::get_dest_path(command, tmp::command::path_option::command));
		break;

	case tmp::command::action::_delete :
		tmp::dir_center::_delete();
		break;

	case tmp::command::action::print :
		tmp::dir_center::print();
		break;

	case tmp::command::action::sync :
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

	case tmp::command::action::help :
		// 
		break;

	default:
		cout << "[�˸�] >> �߸��� ��ɾ� �Դϴ�." << endl << endl;
	}
}

void tmp::command::command(const int argc,  char* argv[])
{
	if (tmp::command::is_right(argc, argv))
	{
		cout << "[�˸�] >> �߸��� ��ɾ� �Դϴ�." << endl << endl;
		return;
	}

	switch (tmp::command::get_action(argv))
	{
	case tmp::command::action::add:
		tmp::sync::sync(tmp::command::get_root_path(argc, argv), tmp::command::get_dest_path(argc, argv));
		break;

	case tmp::command::action::_delete:
		tmp::dir_center::_delete();
		break;

	case tmp::command::action::print:
		tmp::dir_center::print();
		break;

	case tmp::command::action::sync:
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

	case tmp::command::action::help:
		// 
		break;

	default:
		cout << "[�˸�] >> �߸��� ��ɾ� �Դϴ�." << endl << endl;
	}
}

tmp::command::action tmp::command::get_action(const std::string command)
{
	string action = command.substr(0, command.find(COMMAND_TOKEN));

	if (action == "add")
		return tmp::command::action::add;

	else if (action == "delete")
		return tmp::command::action::_delete;

	else if (action == "print")
		return tmp::command::action::print;

	else if (action == "sync")
		return tmp::command::action::sync;

	else if (action == "help")
		return tmp::command::action::help;

	else
		return tmp::command::action::unknown;
}

tmp::command::action tmp::command::get_action(const std::string command, std::string* const str_action)
{
	string action = command.substr(0, command.find(COMMAND_TOKEN));
	*str_action = action;

	if (action == "add")
		return tmp::command::action::add;	

	else if (action == "delete")
		return tmp::command::action::_delete;

	else if (action == "print")
		return tmp::command::action::print;

	else if (action == "sync")
		return tmp::command::action::sync;

	else if (action == "help")
		return tmp::command::action::help;

	else
		return tmp::command::action::unknown;
}

tmp::command::action tmp::command::get_action( char* argv[])
{
	string action = *(argv + 1);

	if (action == "add")
		return tmp::command::action::add;

	else if (action == "delete")
		return tmp::command::action::_delete;

	else if (action == "print")
		return tmp::command::action::print;

	else if (action == "sync")
		return tmp::command::action::sync;

	else if (action == "help")
		return tmp::command::action::help;

	else
		return tmp::command::action::unknown;
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
	int index;
	for (index = 0; index < argc; index++)
	{
		if (strcmp(*(argv + index), "-root"))
		{
			index++;
			break;
		}
	}

	string str_root(*(argv + index));
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
	int index;
	for (index = 0; index < argc; index++)
	{
		if (strcmp(*(argv + index), "-dest"))
		{
			index++;
			break;
		}
	}

	string str_dest(*(argv + index));
	bfs::path dest(str_dest);
	return dest.generic_string();
}

bool tmp::command::is_right(const std::string command)
{
	string str_action;

	// action�� unknown�� ��
	// ���� �����̴�.
	if (tmp::command::get_action(command) == tmp::command::action::unknown)
		return false;


	// action�� tmp::command::action::add �� �ƴ� ��(�ɼ��� �ʿ����� �ʴ� action)
	// ��ɾ�� action�� ���̰� ������ �ǹٸ� ����,
	// �ƴϸ� ���� �����̴�.
	else if (tmp::command::get_action(command, &str_action) != tmp::command::action::add)
	{		
		if (str_action.size() == command.size())
			return true;

		return false;
	}

	// tmp::command::action::add �� ��
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

bool tmp::command::is_right(const int argc,  char* argv[])
{
	// action�� tmp::command::action::unkown �̸� Ʋ�� �����̴�.
	if (tmp::command::get_action(argv) == tmp::command::action::unknown)
		return false;

	// action�� tmp::command::action::add �� �ƴ� ��(�ɼ��� �ʿ����� �ʴ� action)
	// main ������ ������ 2�� ���� ������ ���� �����̴�.
	else if (tmp::command::get_action(argv) != tmp::command::action::add)
	{
		if (argc > 2)
			return false;
	}

	// action�� tmp::command::action::add �� ��
	else
	{
		if (argc < 6)
			false;

		if (bfs::exists(tmp::command::get_root_path(argc, argv)) && 
			bfs::exists(tmp::command::get_dest_path(argc, argv)))
			return true;	
		
		return false;
	}

	switch (tmp::command::get_action(argv))
	{
	case  tmp::command::action::unknown:
		return false;

	case tmp::command::action::print:
	case tmp::command::action::_delete:
	case tmp::command::action::help:
		if (argc > 2)
			return false;

	case tmp::command::action::add:


	default:
		break;
	}
}


