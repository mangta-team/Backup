#pragma once
#ifndef DIR_CENTER_HPP
#define DIR_CENTER_HPP

#include <string>
#include <boost/filesystem/path.hpp>


#define ROOT_PATH	
#define COPY_PATH

namespace bfs = boost::filesystem;

namespace dir_center
{
	class Dir
	{
	private:
		bfs::path* ptr_source;
		bfs::path* ptr_dest;

	public:
		Dir() { this->set_ptr_source(new bfs::path); this->set_ptr_dest(new bfs::path); }
		~Dir() { delete this->get_ptr_source(); delete this->get_ptr_dest(); }

		// 클래스 멤버의 set/get
		void set_ptr_source(bfs::path* ptr_source) { this->ptr_source = ptr_source; }
		void set_ptr_dest(bfs::path* ptr_dest) { this->ptr_dest = ptr_dest; }
		bfs::path* get_ptr_source() { return this->ptr_source; }
		bfs::path* get_ptr_dest() { return this->ptr_dest; }

		void set_source(const bfs::path& source) { *(this->ptr_source) = source; }
		void set_dest(const bfs::path& dest) { *(this->ptr_dest) = dest; }
		std::string get_source() { return this->ptr_source->string(); }
		std::string get_dest() { return this->ptr_dest->string(); }
	};
}

#endif	//	!DIR_CENTER_HPP