#pragma once
#ifndef DIR_CENTER_HPP
#define DIR_CENTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>

namespace bfs = boost::filesystem;

#define PATH_TXT "dir_path/path.txt"
class Dir_Center
{
private:

public:
	/**
	 * @brief ���丮�� �߰��ϴ� �޼ҵ�
	 */
	void add(bfs::path path);

	/**
	 * @brief �����丮�� �����ϴ� �޼ҵ�
	 */
	void _delete();

	/**
	 * @brief ���丮�� ����ϴ� �޼ҵ�
	 */
	void print();
};


#endif	//	!DIR_CENTER_HPP