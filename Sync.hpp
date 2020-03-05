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

/**
 * @brief 동기화를 담당하는 클래스
 * @details 동기화
 * @author Park18
 * @date 2020-02-13
 * @version 0.0.1
 */
class Sync
{
private:

public:
    /**
     * @brief 동기화 메소드
     * @details 재귀함수, root와 dest의 각각 파일의 수정한 날짜 비교, 다르면 root의 것으로 백업한다.
     * @param boost::filesystem::path root 원본 경로
     * @param boost::filesystem::path deest 복사본 경로
     * @commnet boost::system::error_code의 기본값이 정해진 메소드를 구현할 수 있으면 구현
     *          에러 발생, 재귀함수 호출중 비정상경로로 호출
     */
    void static sync(const bfs::path &root, const bfs::path &dest/*, boost::system::error_code*/);
   
    /**
     * @brief 매개변수로 받은 경로에서 최하위 디렉토리 이름을 반환
     * @details boost::filesystem::path 으로 받은 경로를 std::string으로 변환하여 
                최하위 디렉토리의 이름을 반환한다.
     * @param boost::filesystem::path path 추출할 최하위 데렉토리의 경로
     * @return std::string 최하위 디렉토리 이름
     * @commnet path.filename() 때문에 없어도 되는 메소드, 삭제필요
     */
    std::string static get_dir_name(bfs::path& path);

    void static get_directories(const bfs::path& path, std::vector<bfs::path>&);

    void static copy()
    {
        const bfs::path path("test_dir/test1.txt");
        const bfs::path dest("test_dir/copy.txt");

        try
        {
            bfs::copy_file(path, dest, bfs::copy_option::overwrite_if_exists);
        }
        catch (bfs::filesystem_error& ex)
        {
            std::cout << ex.what() << std::endl;
            throw;
        }
    }

    void static test(const bfs::path& root, const bfs::path& dest);
};
	
#endif // !SYNC_HPP
