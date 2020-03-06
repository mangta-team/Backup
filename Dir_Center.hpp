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
	 * @brief �ܺ� ���Ͽ� ����� root-dest ��θ� �߰��ϴ� �޼ҵ�
	 */
	void static add(bfs::path root, bfs::path dest);

	/**
	 * @brief �ܺ� ���Ͽ� ����� root-dest ��θ� �����ϴ� �޼ҵ�
	 */
	void static _delete();

	/**
	 * @brief �ܺ� ���Ͽ� ����� root-dest ��θ� ����ϴ� �޼ҵ�
	 * @return �ܺ� ���Ͽ� root-dest ����� ���� ���� ���� ��ȯ, ������ 1, ������ 0
	 */
	bool static print();

	/**
	 * @brief �ܺ� ���Ͽ� ����� root-dest ��θ�  ����ϰ� vector�� �����ϴ� �޼ҵ�
	 * @param �ܺ� ���Ͽ� ����� ��θ� ������ vector
	 * @return �ܺ� ���Ͽ� ����� ����� ���� ���� ��ȯ, ������ 1, ������ 0
	 */
	bool static print(std::vector<std::string>*);
};


#endif	//	!DIR_CENTER_HPP