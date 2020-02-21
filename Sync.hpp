#pragma once
#ifndef SYNC_HPP
#define SYNC_HPP

#include <iostream>
#include <string>
//#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/exception.hpp>  

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
     * @param boost::filesystem::path root 원본 경로
     * @param boost::filesystem::path deest 복사본 경로
     */
    void static play_sync(boost::filesystem::path& root, boost::filesystem::path& dest);
    
    /**
     * @brief 매개변수로 받은 경로에서 최하위 디렉토리 이름을 반환
     * @details boost::filesystem::path 으로 받은 경로를 std::string으로 변환하여 
                최하위 디렉토리의 이름을 반환한다.
     * @param boost::filesystem::path path 추출할 최하위 데렉토리의 경로
     * @return std::string 최하위 디렉토리 이름
     */
    std::string static get_dir_name(boost::filesystem::path& path);

    void static copy()
    {
        const boost::filesystem::path path("test_dir/test1.txt");
        const boost::filesystem::path dest("test_dir/copy.txt");

        try
        {
            boost::filesystem::copy_file(path, dest, boost::filesystem::copy_option::overwrite_if_exists);
        }
        catch (boost::filesystem::filesystem_error& ex)
        {
            std::cout << ex.what() << std::endl;
            throw;
        }
    }
};
	
#endif // !SYNC_HPP
