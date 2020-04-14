#pragma once
#ifndef SYNC_HPP
#define SYNC_HPP

#include <iostream>
#include <string>
#include <vector>

//#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/exception.hpp>  
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
namespace bfs = boost::filesystem;

namespace backup
{
namespace sync
{

/**
 * @brief 동기화 메소드
 * @details 재귀함수, source와 dest의 각각 파일의 수정한 날짜 비교, 다르면 source의 것으로 백업한다.
 * @param boost::filesystem::path source 원본 경로
 * @param boost::filesystem::path deest 복사본 경로
 * @commnet boost::system::error_code의 기본값이 정해진 메소드를 구현할 수 있으면 구현
 *          에러 발생, 재귀함수 호출중 비정상경로로 호출
 */
void sync(const bfs::path &source, const bfs::path &dest/*, boost::system::error_code*/);

} // !namespace sycn
} // !namespace backup	

#endif // !SYNC_HPP