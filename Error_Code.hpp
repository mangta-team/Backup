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
	nonexistent_work,	// 작업이 존재하지 않을 떄 
	nonexistent_option,	// 옵션이 존재하지 않을 때
	nonexistent_path,	// 경로가 존재하지 않을 때
	number_of_element	// 요소 개수가 맞지 않을 때
};

/**
 * @brief 프로그램 에러에 관한 클래스
 */
class Error_Code
{
private:
	error_list error_code;

public:
	Error_Code() { set_error_code(error_list::none); }

	/**
	 * @breif 객체의 error_list error_code를 설정하는 메소드
	 * @param backup::system::error_list error_code 설정할 에러코드
	 */
	void set_error_code(error_list error_code) { this->error_code = error_code; }

	/**
	 * @breif 객체의 error_list error_code를 반환하는 메소드
	 * @return 객체의 error_list error_code
	 */
	backup::system::error_list get_error_code() { return error_code; }

	/**
	 * @brief 어떤 에러가 발생한 것인지 출력해주는 메소드
	 * @return 에러의 원인
	 */
	std::string what();
};

} // !namespace system
} // !namespace backup

#endif // !ERROR_CODE_HPP