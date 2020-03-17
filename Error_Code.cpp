#include "Error_Code.hpp"

using namespace std;

std::string backup::system::Error_Code::what()
{
	switch (this->error_code)
	{
	case backup::system::error_list::nonexistent_work:
		return "�Էµ� ������ �߸��� �����Դϴ�.";

	case backup::system::error_list::nonexistent_option:
		return string("�Էµ� �ɼ��� �߸��� �ɼ��Դϴ�.");

	case backup::system::error_list::nonexistent_path:
		return string("�Է��� ��ΰ� �������� �ʽ��ϴ�.");

	case backup::system::error_list::number_of_element:
		return string("����� ������ �����ʽ��ϴ�.");
	}
}
