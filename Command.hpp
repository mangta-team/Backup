#pragma once
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include <boost/filesystem/path.hpp>
#include "Dir_Center.hpp"
#include "Sync.hpp"
#include "Error_Code.hpp"

namespace bfs = boost::filesystem;
namespace backup
{
namespace command
{
#define COMMAND_TOKEN ' '

enum class work
{
    unknown,
	add,
	_delete,
	print,
	sync,
	help,
    exit // cmd에서 실행하는 것이 아닐 때 사용
};

enum class path_option
{
    none = 0,
    file = none,
    command,
};

 /**
 * @brief
 * @param cosnt int argc 토큰(' ')으로 나눠진 명령어의 개수
 * @param const char* 명령어를 토큰(' ')으로 나눠 단어별로 저장한 문자열 배열 
 */
 void command(std::vector<std::string> vector_argv);

 /**
 * @brief main의 인자로 입력된 명령어에서 열거형 work 을 반환하는 메소드
 * @param const char* argv[] 명령어
 */
 backup::command::work get_work(std::vector<std::string> vector_argv);
 

 /**
 * @brief main 인자로 입력된 명령어에서 root의 경로를 반환하는 메소드
 * @param const int argc main 인자의 개수
 * @param const char* argv[] 
 */
 bfs::path get_root_path(std::vector<std::string> vector_argv);
 

 /**
 * @brief
 * @param string command 명령어
 */
 bfs::path get_dest_path(std::vector<std::string> vector_argv);

 /**
 * @brief 옳바른 명령어인지 확인하는 메소드
 * @param string command 명령어
 */
 bool is_right(std::vector<std::string> vector_argv, backup::system::Error_Code& error_code);

} // !namespace command
} // !namespace backup

#endif // !COMMAND_HPP

