#pragma once
#ifndef SYNC_HPP
#define SYNC_HPP

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/exception.hpp>  

/**
 * @brief ����ȭ�� ����ϴ� Ŭ����
 * @details ����ȭ
 * @author Park18
 * @date 2020-02-13
 * @version 0.0.1
 */
class Sync
{
private:

public:
    /**
     * @brief ����ȭ �޼ҵ�
     */
    void static play_sync();
    
    
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
