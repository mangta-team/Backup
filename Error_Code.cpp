#include "Error_Code.hpp"

using namespace std;

std::string tmp::system::Error_Code::what()
{
	switch (error_code)
	{
	case tmp::system::error_list::nonexistent_work:
		return "입력된 동작은 잘못된 동작입니다.";

	case tmp::system::error_list::nonexistent_option:
		return string("입력된 옵션은 잘못된 옵션입니다.");

	case tmp::system::error_list::nonexistent_path:
		return string("입력한 경로가 존재하지 않습니다.");

	case tmp::system::error_list::number_of_element:
		return string("요소의 개수가 맞지않습니다.");
	}
}
