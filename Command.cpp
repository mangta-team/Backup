#include "Command.hpp"

using namespace std;	

void backup::command::command(const std::string command)
{
	if (!backup::command::is_right(command))
	{
		cout << "[�˸�] >> �߸��� ��ɾ� �Դϴ�." << endl << endl;
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
		cout << "[�˸�] >> ���� �׸��� ����ȭ �մϴ�." << endl << endl;

		{
			vector<string> paths; 
			if (backup::dir_center::print(&paths))
				return;
		
			for (int index = 0; index < paths.size(); index++)
				backup::sync::sync(backup::command::get_root_path(paths[index], backup::command::path_option::file),
					backup::command::get_dest_path(paths[index], backup::command::path_option::file));
		}

		cout << "[�˸�] >> ����ȭ�� �������ϴ�." << endl << endl;

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
		cout << "[�˸�] >> " << error_code.what() << endl << endl;
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
		cout << "[�˸�] >> ���� �׸��� ����ȭ �մϴ�." << endl << endl;

		{
			vector<string> paths;
			if (backup::dir_center::print(&paths))
				return;

			for (int index = 0; index < paths.size(); index++)
				backup::sync::sync(backup::command::get_root_path(paths[index], backup::command::path_option::file),
					backup::command::get_dest_path(paths[index], backup::command::path_option::file));
		}

		cout << "[�˸�] >> ����ȭ�� �������ϴ�." << endl << endl;

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

	// work�� unknown�� ��
	// ���� �����̴�.
	if (backup::command::get_work(command) == backup::command::work::unknown)
		return false;


	// work�� backup::command::work::add �� �ƴ� ��(�ɼ��� �ʿ����� �ʴ� work)
	// ��ɾ�� work�� ���̰� ������ �ǹٸ� ����,
	// �ƴϸ� ���� �����̴�.
	else if (backup::command::get_work(command, &str_work) != backup::command::work::add)
	{		
		if (str_work.size() == command.size())
			return true;

		return false;
	}

	// backup::command::work::add �� ��
	else
	{
		// "-root"�� ��ġ�� "-dest"�� ��ġ���� ������ 
		// ���� �����̴�.
		if (command.find("-root") > command.find("-dest"))
			return false;

		// root�� dest�� ��ΰ� �����ϸ� �ǹٸ� ����,
		// �������� ������ ���� �����̴�.
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
	// work�� unknown�� �� ���� �����̴�.
	case  backup::command::work::unknown:
		error_code.set_error_code(backup::system::error_list::nonexistent_work);
		return false;

	// work�� print, delete, help (�ɼ��� ���� work)�� �� 
	case backup::command::work::print:
	case backup::command::work::_delete:
	case backup::command::work::sync:
	case backup::command::work::help:
		// ��ɾ��� ���̰� 2�� �ƴϸ� ���� �����̴�.
		if (vector_argv.size() != 2)
		{
			error_code.set_error_code(backup::system::error_list::number_of_element);
			return false;
		}

		return true;

	// work�� add�� ��
	case backup::command::work::add:
		// ��ɾ��� ���̰� 6���� �ƴϸ� ���� �����̴�.
		if (vector_argv.size() != 6)
		{
			error_code.set_error_code(backup::system::error_list::number_of_element);
			return false;
		}

		// �ɼ� �ڸ��� -root, -dest�� ������ ���� �����̴�.
		if (!((vector_argv[2] == "-root") || (vector_argv[4] == "-root") && ((vector_argv[2] == "-dest") || (vector_argv[4] == "-dest"))))
		{
			error_code.set_error_code(backup::system::error_list::nonexistent_option);
			return false;
		}

		// ��ΰ� �������� ������ ���� �����̴�.
		if (!bfs::exists(backup::command::get_root_path(vector_argv)) || !bfs::exists(backup::command::get_dest_path(vector_argv)))
		{
			error_code.set_error_code(backup::system::error_list::nonexistent_path);
			return false;
		}

		return true;
	}
}


