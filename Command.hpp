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
    exit // cmd���� �����ϴ� ���� �ƴ� �� ���
};

enum class path_option
{
    none = 0,
    file = none,
    command,
};

/**
 * @brief
 * @param string command ��ɾ�
 */
 void command(const std::string command);

 /**
 * @brief
 * @param cosnt int argc ��ū(' ')���� ������ ��ɾ��� ����
 * @param const char* ��ɾ ��ū(' ')���� ���� �ܾ�� ������ ���ڿ� �迭 
 */
 void command(std::vector<std::string> vector_argv);
 
/**
 * @brief ��ɾ�(command)���� ������ action�� ��ȯ�ϴ� �޼ҵ�
 * @param string command ��ɾ�
 */
 backup::command::work get_work(const std::string command);

 /**
  * @brief ��ɾ�(command)���� ������ work�� ��ȯ�ϰ� string str_work�� ���ڿ� work�� �����ϴ� �޼ҵ�
  * @param string command ��ɾ�
  * @param string str_work work�� work�� ���ڿ��� ������ string ������
  */
 backup::command::work get_work(const std::string command, std::string* const str_work);

 /**
 * @brief main�� ���ڷ� �Էµ� ��ɾ�� ������ work �� ��ȯ�ϴ� �޼ҵ�
 * @param const char* argv[] ��ɾ�
 */
 backup::command::work get_work(std::vector<std::string> vector_argv);
 
/**
 * @brief ��ɾ�(connad)���� root�� ��θ� ��ȯ�ϴ� �޼ҵ�
 * @param string command ��ɾ�
 * @param backup::command::path_option path_option ��ɾ�/������
 */
 bfs::path get_root_path(const std::string command, backup::command::path_option path_option);

 /**
 * @brief main ���ڷ� �Էµ� ��ɾ�� root�� ��θ� ��ȯ�ϴ� �޼ҵ�
 * @param const int argc main ������ ����
 * @param const char* argv[] 
 */
 bfs::path get_root_path(std::vector<std::string> vector_argv);
 
/**
 * @brief
 * @param string command ��ɾ�
 */
 bfs::path get_dest_path(const std::string command, backup::command::path_option path_option);

 /**
 * @brief
 * @param string command ��ɾ�
 */
 bfs::path get_dest_path(std::vector<std::string> vector_argv);
 
/**
 * @brief �ǹٸ� ��ɾ����� Ȯ���ϴ� �޼ҵ�
 * @param string command ��ɾ�
 */
 bool is_right(const std::string command);

 /**
 * @brief �ǹٸ� ��ɾ����� Ȯ���ϴ� �޼ҵ�
 * @param string command ��ɾ�
 */
 bool is_right(std::vector<std::string> vector_argv, backup::system::Error_Code& error_code);

} // !namespace command
} // !namespace backup

#endif // !COMMAND_HPP

