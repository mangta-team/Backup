#pragma once
#ifndef ERROR_CODE_HPP
#define ERROR_CODE_HPP

#include <string>

namespace tmp
{
namespace system
{

enum class error_list
{
	none = 0,
	nonexistent_work,	// 작업이 존재하지 않을 떄 
	nonexistent_option,	// 옵션이 존재하지 않을 때
	nonexistent_path,	// 경로가 존재하지 않을 때
	number_of_element	// 요소 개수가 맞지 않을 때
};

class Error_Code
{
private:
	error_list error_code;

public:
	Error_Code() { set_error_code(error_list::none); }

	void set_error_code(error_list error_code) { this->error_code =error_code; }
	tmp::system::error_list get_error_code() { return error_code; }

	std::string what();
};

} // !namespace system
} // !namespace tmp

#endif // !ERROR_CODE_HPP