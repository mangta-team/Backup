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
#define ADD_OPTION_INDEX_1 1
#define ADD_OPTION_INDEX_2 3

enum class work
{
    unknown,
	add,
	_delete,
	print,
	sync,
	help,
    exit
};

/**
 * @brief ��ɾ �Է¹޴� �޼ҵ�
 * @return �Է� ���� ��ɾ ' '���� ���� ������ std::vector<std::string>
 */
std::vector<std::string> get_command();

 /**
  * @brief ��ɾ� �޼ҵ�
  * @param std::vector<std::string> vector_argv main�� �Ű����� argv�� ������ vecter
  * @return bool ���� ��ȣ(��� ����: 1, ����: 0)
  */
 bool command(std::vector<std::string> vector_argv);

 /**
  * @brief main�� �Ű����� argv���� �۾�(work)�� ��ȯ�ϴ� �޼ҵ�
  * @param std::vector<std::string> vector_argv main�� �Ű����� argv�� ������ vecter
  * @return backup::command::work ��ɾ��� work�� �ش��ϴ� ������ ��
  */
 backup::command::work get_work(std::vector<std::string> vector_argv);
 

 /**
  * @brief main ���ڷ� �Էµ� ��ɾ�� source�� ��θ� ��ȯ�ϴ� �޼ҵ�
  * @param std::vector<std::string> vector_argv main�� �Ű����� argv�� ������ vecter
  * @return boost::filesystem::path ��ɾ��� source�� ���
  */
 bfs::path get_source_path(std::vector<std::string> vector_argv);

 /**
  * @brief main ���ڷ� �Էµ� ��ɾ�� dest�� ��θ� ��ȯ�ϴ� �޼ҵ�
  * @param std::vector<std::string> vector_argv main�� �Ű����� argv�� ������ vecter
  * @return boost::filesystem::path ��ɾ��� dest�� ���
  */
 bfs::path get_dest_path(std::vector<std::string> vector_argv);

 /**
  * @brief �ǹٸ� ��ɾ����� Ȯ���ϴ� �޼ҵ�
  * @param std::vector<std::string> vector_argv main�� �Ű����� argv�� ������ vecter
  * @param backup::system::Error_Code& error_code 
  * @return bool ������ ����, �ǹٸ� ��ɾ� true, ���� ��ɾ� false
  */
 bool is_right(std::vector<std::string> vector_argv, backup::system::Error_Code& error_code);

} // !namespace command
} // !namespace backup

#endif // !COMMAND_HPP

