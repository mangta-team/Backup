#pragma once
#ifndef DIR_CENTER_HPP
#define DIR_CENTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>

namespace bfs = boost::filesystem;

class Dir
{
private:
	bfs::path* ptr_source;
	bfs::path* ptr_dest;

public:
	Dir();
	Dir(bfs::path source, bfs::path dest);
	~Dir() { delete this->get_ptr_source(); delete this->get_ptr_dest(); }

	// Ŭ���� ����� set/get
	void set_ptr_source(bfs::path* ptr_source) { this->ptr_source = ptr_source; }
	void set_ptr_dest(bfs::path* ptr_dest) { this->ptr_dest = ptr_dest; }
	bfs::path* get_ptr_source() { return this->ptr_source; }
	bfs::path* get_ptr_dest() { return this->ptr_dest; }

	void set_source(const bfs::path& source) { *(this->ptr_source) = source; }
	void set_source(const std::string& source) { *(this->ptr_source) = source; }
	void set_dest(const bfs::path& dest) { *(this->ptr_dest) = dest; }
	void set_dest(const std::string& dest) { *(this->ptr_dest) = dest; }
	std::string get_source() { return this->ptr_source->string(); }
	std::string get_dest() { return this->ptr_dest->string(); }
};

#define PATH_TXT "dir_path/path.txt"
class Dir_
{
private:
	std::vector<Dir*>* ptr_dir;

public:
	void set_ptr_dir(std::vector<Dir*>* ptr_dir) { this->ptr_dir = ptr_dir; }
	std::vector<Dir*>* get_ptr_dir() { return this->ptr_dir; }

	/**
		* @brief ���α׷� �ʱ�ȭ�� �ϴ� Ȱ��
		* @details ptr_dir�� �޸𸮸� �Ҵ��ϰ� path.txt���� source�� dest�� ��θ� �����´�.
		*/
	void init();

	/**
		* @brief ���α׷� ����� �ϴ� Ȱ��
		* @details source�� dest�� ��θ� path.txt�� �����ϰ� ptr_dir�� �Ҵ��� �޷θ��� �����Ѵ�.
		*/
	void shutdown();
};


#endif	//	!DIR_CENTER_HPP