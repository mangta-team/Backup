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
		Dir() { this->Set_Ptr_Source(new bfs::path); this->Set_Ptr_Dest(new bfs::path); }
		~Dir() { delete this->Get_Ptr_Source(); delete this->Get_Ptr_Dest(); }

		// 클래스 멤버의 set/get
		void Set_Ptr_Source(bfs::path* ptr_source) { this->ptr_source = ptr_source; }
		void Set_Ptr_Dest(bfs::path* ptr_dest) { this->ptr_dest = ptr_dest; }
		bfs::path* Get_Ptr_Source() { return this->ptr_source; }
		bfs::path* Get_Ptr_Dest() { return this->ptr_dest; }

		void Set_Source(const bfs::path& source) { *(this->ptr_source) = source; }
		void Set_Dest(const bfs::path& dest) { *(this->ptr_dest) = dest; }
		std::string Get_Source() { return this->ptr_source->string(); }
		std::string Get_Dest() { return this->ptr_dest->string(); }
	};
}

#endif	//	!DIR_CENTER_HPP