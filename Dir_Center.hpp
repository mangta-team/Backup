#pragma once
#ifndef DIR_CENTER_HPP
#define DIR_CENTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>

namespace bfs = boost::filesystem;

#define PATH_TXT "dir_path/path.txt"
class Dir_Center
{
private:

public:
	/**
	 * @brief 외부 파일에 저장된 root-dest 경로를 추가하는 메소드
	 */
	void static add(bfs::path root, bfs::path dest);

	/**
	 * @brief 외부 파일에 저장된 root-dest 경로를 삭제하는 메소드
	 */
	void static _delete();

	/**
	 * @brief 외부 파일에 저장된 root-dest 경로를 출력하는 메소드
	 * @return 외부 파일에 root-dest 경로의 저장 존재 유무 반환, 없으면 1, 있으면 0
	 */
	bool static print();

	/**
	 * @brief 외부 파일에 저장된 root-dest 경로를  출력하고 vector에 저장하는 메소드
	 * @param 외부 파일에 저장된 경로를 저장할 vector
	 * @return 외부 파일에 저장된 경로의 존재 유무 반환, 없으면 1, 있으면 0
	 */
	bool static print(std::vector<std::string>*);
};


#endif	//	!DIR_CENTER_HPP