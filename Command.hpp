#pragma once
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include <boost/filesystem/path.hpp>

#define COMMAND_TOKEN ' '
namespace bfs = boost::filesystem;
namespace sync
{
namespace command
{
	enum class Action
	{
		add,
		_delete,
		print,
		sync,
		help
	};

/**
 * @brief
 * @param string command 명령어
 */
 void command(const std::string command);
 
/**
 * @brief
 * @param string command 명령어
 */
 sync::command::Action get_action(const std::string command);
 
/**
 * @brief
 * @param string command 명령어
 */
 bfs::path get_root_path(const std::string command);
 
/**
 * @brief
 * @param string command 명령어
 */
 bfs::path get_dest_path(const std::string command);
 
/**
 * @brief
 * @param string command 명령어
 */
 bool check_command(const std::string command);

} // !namespace command
} // !namespace sync

#endif // !COMMAND_HPP

