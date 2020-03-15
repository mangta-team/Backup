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
	nonexistent_work,	// �۾��� �������� ���� �� 
	nonexistent_option,	// �ɼ��� �������� ���� ��
	nonexistent_path,	// ��ΰ� �������� ���� ��
	number_of_element	// ��� ������ ���� ���� ��
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