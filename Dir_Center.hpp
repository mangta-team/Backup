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
#define PATH_TXT "dir_path/path.txt"

	/**
	 * @brief �ܺ� ���Ͽ� ����� source-dest ��θ� �߰��ϴ� �޼ҵ�
	 */
	void add(bfs::path source, bfs::path dest);

	/**
	 * @brief �ܺ� ���Ͽ� ����� root-dest ��θ� �����ϴ� �޼ҵ�
	 */
	void _delete();

	/**
	 * @brief �ܺ� ���Ͽ� ����� root-dest ��θ� ����ϴ� �޼ҵ�
	 * @return �ܺ� ���Ͽ� root-dest ����� ���� ���� ���� ��ȯ, ������ 1, ������ 0
	 */
	bool print();

	/**
	 * @brief �ܺ� ���Ͽ� ����� root-dest ��θ�  ����ϰ� vector�� �����ϴ� �޼ҵ�
	 * @param �ܺ� ���Ͽ� ����� ��θ� ������ vector
	 * @return �ܺ� ���Ͽ� ����� ����� ���� ���� ��ȯ, ������ 1, ������ 0
	 */
	bool print(std::vector<std::string>*);

	/**
	 * @brief �ܺ� ���Ͽ��� ������ source-dest ��� ���ڿ����� 
			  source�� ��θ� ��ȯ�ϴ� �޼ҵ�
	 * @param std::string str_paths �ܺ� ���Ͽ��� ������ source-dest ��� ���ڿ�
	 * @return bfs::path source ���
	 */
	bfs::path get_source_path(std::string str_paths);

	/**
	 * @brief �ܺ� ���Ͽ��� ������ source-dest ��� ���ڿ�����
			  dest�� ��θ� ��ȯ�ϴ� �޼ҵ�
	 * @param std::string str_paths �ܺ� ���Ͽ��� ������ source-dest ��� ���ڿ�
	 * @return bfs::path dest ���
	 */
	bfs::path get_dest_path(std::string str_paths);
} // !namespace dir_center
} // !namespace backup

#endif	//	!DIR_CENTER_HPP