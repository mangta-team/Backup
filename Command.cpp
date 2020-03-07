#include "Command.hpp"

using namespace std;	

void sync::command::Command::command(const std::string command)
{
	if (!check_command(command))
	{
		cout << "[알림] >> 잘못된 명령어 입니다." << endl << endl;
		return;
	}

	switch (get_action(command))
	{
	case sync::command::Action::add :
		//
		break;

	case sync::command::Action::_delete :
		//
		break;

	case sync::command::Action::print :
		//
		break;

	case sync::command::Action::sync :
		//
		break;

	case sync::command::Action::help :
		// 
		break;

	default:
		cout << "[알림] >> 잘못된 명령어 입니다." << endl << endl;
	}
}

bool sync::command::Command::check_command(const std::string command)
{

	ios::app;
	return false;
}
