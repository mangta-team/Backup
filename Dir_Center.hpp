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
 * @brief root, dest 를 저장하는 메소드
 */
class Dir
{
private:
	bfs::path* ptr_root; // 원본 경로
	bfs::path* ptr_dest; // 목표 경로

public:
	Dir();
	Dir(bfs::path root, bfs::path dest);
	~Dir() { delete this->get_ptr_root(); delete this->get_ptr_dest(); }

	// 클래스 멤버의 set/get
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
	  * @brief 외부 파일에 저장된 경로를 프로그램에 초기화하는 메소드
	  * @details ptr_dir에 메모리를 할당하고 path.txt에서 root와 dest의 경로를 가져온다.
	  */
	void init();

	/**
	  * @brief 프로그램에 저장된 경로를 외부 파일에 저장하는 메소드
	  * @details root와 dest의 경로를 path.txt에 저장하고 ptr_dir에 할당한 메로리를 해제한다.
	  */
	void shutdown();

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