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
 * @brief �ܺ� ���Ͽ� ����� source-dest ��θ� �߰��ϴ� �޼ҵ�
 * @param boost::filesystem::path source �߰��� source ���
 * @param boost::filesystem::path dest ������ dest ���
 */
void add(bfs::path source, bfs::path dest);

/**
 * @brief �ܺ� ���Ͽ� ����� root-dest ��θ� �����ϴ� �޼ҵ�
 */
void _delete();

/**
 * @brief �ܺ� ���Ͽ� ����� source-dest ��θ� ����ϴ� �޼ҵ�
 * @return �ܺ� ���Ͽ� source-dest ����� ���� ���� ���� ��ȯ, ������ 1, ������ 0
 */
bool print();

/**
 * @brief �ܺ� ���Ͽ� ����� source-dest ��θ� ����ϰ� vector�� �����ϴ� �޼ҵ�
 * @param std::vector<std::string>* �ܺ� ���Ͽ� ����� source-dest ��θ� ������ vector
 * @return �ܺ� ���Ͽ� source-dest ����� ���� ���� ���� ��ȯ, ������ 1, ������ 0
 */
bool print(std::vector<std::string>* str_paths);

/**
 * @brief �ܺ� ���Ͽ��� ������ source-dest ��� ���ڿ����� 
 *		source�� ��θ� ��ȯ�ϴ� �޼ҵ�
 * @param std::string str_paths �ܺ� ���Ͽ��� ������ source-dest ��� ���ڿ�
 * @return bfs::path source ���
 */
bfs::path get_source_path(std::string str_paths);

/**
 * @brief �ܺ� ���Ͽ��� ������ source-dest ��� ���ڿ�����
 *		dest�� ��θ� ��ȯ�ϴ� �޼ҵ�
 * @param std::string str_paths �ܺ� ���Ͽ��� ������ source-dest ��� ���ڿ�
 * @return bfs::path dest ���
 */
bfs::path get_dest_path(std::string str_paths);
} // !namespace dir_center
} // !namespace backup

#endif	//	!DIR_CENTER_HPP