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
	 * @brief 디렉토리를 추가하는 메소드
	 */
	void add(bfs::path path);

	/**
	 * @brief 데렉토리를 삭제하는 메소드
	 */
	void _delete();

	/**
	 * @brief 디렉토리를 출력하는 메소드
	 */
	void print();
};


#endif	//	!DIR_CENTER_HPP