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

namespace backup
{
namespace dir_center
{
#define PATH_TXT bfs::path("dir_path/path.txt")
#define TEST_PATH_TXT "path.txt"

/**
 * @brief 외부 파일에 저장된 source-dest 경로를 추가하는 메소드
 * @param boost::filesystem::path source 추가할 source 경로
 * @param boost::filesystem::path dest 추자할 dest 경로
 */
void add(bfs::path source, bfs::path dest);

/**
 * @brief 외부 파일에 저장된 root-dest 경로를 삭제하는 메소드
 */
void _delete();

/**
 * @brief 외부 파일에 저장된 source-dest 경로를 출력하는 메소드
 * @return 외부 파일에 source-dest 경로의 저장 존재 유무 반환, 없으면 1, 있으면 0
 */
bool print();

/**
 * @brief 외부 파일에 저장된 source-dest 경로를 출력하고 vector에 저장하는 메소드
 * @param std::vector<std::string>* 외부 파일에 저장된 source-dest 경로를 저장할 vector
 * @return 외부 파일에 source-dest 경로의 저장 존재 유무 반환, 없으면 1, 있으면 0
 */
bool print(std::vector<std::string>* str_paths);

/**
 * @brief 외부 파일에서 가져온 source-dest 경로 문자열에서 
 *		source의 경로를 반환하는 메소드
 * @param std::string str_paths 외부 파일에서 가져온 source-dest 경로 문자열
 * @return bfs::path source 경로
 */
bfs::path get_source_path(std::string str_paths);

/**
 * @brief 외부 파일에서 가져온 source-dest 경로 문자열에서
 *		dest의 경로를 반환하는 메소드
 * @param std::string str_paths 외부 파일에서 가져온 source-dest 경로 문자열
 * @return bfs::path dest 경로
 */
bfs::path get_dest_path(std::string str_paths);
} // !namespace dir_center
} // !namespace backup

#endif	//	!DIR_CENTER_HPP