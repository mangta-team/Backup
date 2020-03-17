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
	help
};

 /**
  * @brief 명령어 메소드
  * @param std::vector<std::string> vector_argv main의 매개변수 argv를 저장한 vecter
  */
 void command(std::vector<std::string> vector_argv);

 /**
  * @brief main의 매개변수 argv에서 작업(work)을 반환하는 메소드
  * @param std::vector<std::string> vector_argv main의 매개변수 argv를 저장한 vecter
  * @return backup::command::work 명령어의 work에 해당하는 열거형 값
  */
 backup::command::work get_work(std::vector<std::string> vector_argv);
 

 /**
  * @brief main 인자로 입력된 명령어에서 source의 경로를 반환하는 메소드
  * @param std::vector<std::string> vector_argv main의 매개변수 argv를 저장한 vecter
  * @return boost::filesystem::path 명령어의 source의 경로
  */
 bfs::path get_source_path(std::vector<std::string> vector_argv);

 /**
  * @brief main 인자로 입력된 명령어에서 dest의 경로를 반환하는 메소드
  * @param std::vector<std::string> vector_argv main의 매개변수 argv를 저장한 vecter
  * @return boost::filesystem::path 명령어의 dest의 경로
  */
 bfs::path get_dest_path(std::vector<std::string> vector_argv);

 /**
  * @brief 옳바른 명령어인지 확인하는 메소드
  * @param std::vector<std::string> vector_argv main의 매개변수 argv를 저장한 vecter
  * @param backup::system::Error_Code& error_code 
  * @return bool 옳음의 유무, 옳바른 명령어 true, 오류 명령어 false
  */
 bool is_right(std::vector<std::string> vector_argv, backup::system::Error_Code& error_code);

} // !namespace command
} // !namespace backup

#endif // !COMMAND_HPP

