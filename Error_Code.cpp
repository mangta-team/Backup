#include "Error_Code.hpp"

using namespace std;

std::string tmp::system::Error_Code::what()
{
	switch (error_code)
	{
	case tmp::system::error_list::nonexistent_work:
		return "�Էµ� ������ �߸��� �����Դϴ�.";

	case tmp::system::error_list::nonexistent_option:
		return string("�Էµ� �ɼ��� �߸��� �ɼ��Դϴ�.");

	case tmp::system::error_list::nonexistent_path:
		return string("�Է��� ��ΰ� �������� �ʽ��ϴ�.");

	case tmp::system::error_list::number_of_element:
		return string("����� ������ �����ʽ��ϴ�.");
	}
}
