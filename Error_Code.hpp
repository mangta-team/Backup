#pragma once
#ifndef ERROR_CODE_HPP
#define ERROR_CODE_HPP

#include <string>

namespace backup
{
namespace system
{

enum class error_list
{
	none = 0,

	//----------------------------------
	//				Dir_Center				
	//----------------------------------

	//----------------------------------
	//				  Sync				
	//----------------------------------

	//----------------------------------
	//				Command				
	//----------------------------------
	nonexistent_work,	// �۾��� �������� ���� �� 
	nonexistent_option,	// �ɼ��� �������� ���� ��
	nonexistent_path,	// ��ΰ� �������� ���� ��
	number_of_element	// ��� ������ ���� ���� ��
};

/**
 * @brief ���α׷� ������ ���� Ŭ����
 */
class Error_Code
{
private:
	error_list error_code;

public:
	Error_Code() { set_error_code(error_list::none); }

	/**
	 * @breif ��ü�� error_list error_code�� �����ϴ� �޼ҵ�
	 * @param backup::system::error_list error_code ������ �����ڵ�
	 */
	void set_error_code(error_list error_code) { this->error_code = error_code; }

	/**
	 * @breif ��ü�� error_list error_code�� ��ȯ�ϴ� �޼ҵ�
	 * @return ��ü�� error_list error_code
	 */
	backup::system::error_list get_error_code() { return error_code; }

	/**
	 * @brief � ������ �߻��� ������ ������ִ� �޼ҵ�
	 * @return ������ ����
	 */
	std::string what();
};

} // !namespace system
} // !namespace backup

#endif // !ERROR_CODE_HPP