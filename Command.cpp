#include "Command.hpp"

using namespace std;	

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
		backup::dir_center::add(backup::command::get_source_path(vector_argv), backup::command::get_dest_path(vector_argv));
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
			vector<string> str_paths;
			if (backup::dir_center::print(&str_paths))
				return;

			for (int index = 0; index < str_paths.size(); index++)
				backup::sync::sync(backup::dir_center::get_source_path(str_paths[index]),
					backup::dir_center::get_dest_path(str_paths[index]));
		}

		cout << "[�˸�] >> ����ȭ�� �������ϴ�." << endl << endl;

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
		if (!bfs::exists(backup::command::get_source_path(vector_argv)) || !bfs::exists(backup::command::get_dest_path(vector_argv)))
		{
			error_code.set_error_code(backup::system::error_list::nonexistent_path);
			return false;
		}

		return true;
	}
}


