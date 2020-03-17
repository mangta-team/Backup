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
 * @param string command 명령어
 */
 void command(const std::string command);

 /**
 * @brief
 * @param cosnt int argc 토큰(' ')으로 나눠진 명령어의 개수
 * @param const char* 명령어를 토큰(' ')으로 나눠 단어별로 저장한 문자열 배열 
 */
 void command(std::vector<std::string> vector_argv);
 
/**
 * @brief 명령어(command)에서 열거형 action을 반환하는 메소드
 * @param string command 명령어
 */
 backup::command::work get_work(const std::string command);

 /**
  * @brief 명령어(command)에서 열거형 work을 반환하고 string str_work에 문자열 work을 저장하는 메소드
  * @param string command 명령어
  * @param string str_work work의 work의 문자열을 저장할 string 포인터
  */
 backup::command::work get_work(const std::string command, std::string* const str_work);

 /**
 * @brief main의 인자로 입력된 명령어에서 열거형 work 을 반환하는 메소드
 * @param const char* argv[] 명령어
 */
 backup::command::work get_work(std::vector<std::string> vector_argv);
 
/**
 * @brief 명령어(connad)에서 root의 경로를 반환하는 메소드
 * @param string command 명령어
 * @param backup::command::path_option path_option 명령어/파일을
 */
 bfs::path get_root_path(const std::string command, backup::command::path_option path_option);

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
 bfs::path get_dest_path(const std::string command, backup::command::path_option path_option);

 /**
 * @brief
 * @param string command 명령어
 */
 bfs::path get_dest_path(std::vector<std::string> vector_argv);
 
/**
 * @brief 옳바른 명령어인지 확인하는 메소드
 * @param string command 명령어
 */
 bool is_right(const std::string command);

 /**
 * @brief 옳바른 명령어인지 확인하는 메소드
 * @param string command 명령어
 */
 bool is_right(std::vector<std::string> vector_argv, backup::system::Error_Code& error_code);

} // !namespace command
} // !namespace backup

#endif // !COMMAND_HPP

