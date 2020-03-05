#pragma once
#ifndef DIR_CENTER_HPP
#define DIR_CENTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>

namespace bfs = boost::filesystem;

/**
 * @brief root, dest �� �����ϴ� �޼ҵ�
 */
class Dir
{
private:
	bfs::path* ptr_root; // ���� ���
	bfs::path* ptr_dest; // ��ǥ ���

public:
	Dir();
	Dir(bfs::path root, bfs::path dest);
	~Dir() { delete this->get_ptr_root(); delete this->get_ptr_dest(); }

	// Ŭ���� ����� set/get
	void set_ptr_root(bfs::path* ptr_root) { this->ptr_root = ptr_root; }
	void set_ptr_dest(bfs::path* ptr_dest) { this->ptr_dest = ptr_dest; }
	bfs::path* get_ptr_root() { return this->ptr_root; }
	bfs::path* get_ptr_dest() { return this->ptr_dest; }

	void set_root(const bfs::path& root) { *(this->ptr_root) = root; }
	void set_dest(const bfs::path& dest) { *(this->ptr_dest) = dest; }
	std::string get_root() { return this->ptr_root->string(); }
	std::string get_dest() { return this->ptr_dest->string(); }
};


#define PATH_TXT "dir_path/path.txt"
class Dir_Center
{
private:
	std::vector<Dir*>* ptr_dir;

public:
	void set_ptr_dir(std::vector<Dir*>* ptr_dir) { this->ptr_dir = ptr_dir; }
	std::vector<Dir*>* get_ptr_dir() { return this->ptr_dir; }

	/**
	  * @brief �ܺ� ���Ͽ� ����� ��θ� ���α׷��� �ʱ�ȭ�ϴ� �޼ҵ�
	  * @details ptr_dir�� �޸𸮸� �Ҵ��ϰ� path.txt���� root�� dest�� ��θ� �����´�.
	  */
	void init();

	/**
	  * @brief ���α׷��� ����� ��θ� �ܺ� ���Ͽ� �����ϴ� �޼ҵ�
	  * @details root�� dest�� ��θ� path.txt�� �����ϰ� ptr_dir�� �Ҵ��� �޷θ��� �����Ѵ�.
	  */
	void shutdown();

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