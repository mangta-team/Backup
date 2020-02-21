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
     * @param boost::filesystem::path root ���� ���
     * @param boost::filesystem::path deest ���纻 ���
     */
    void static play_sync(boost::filesystem::path& root, boost::filesystem::path& dest);
    
    /**
     * @brief �Ű������� ���� ��ο��� ������ ���丮 �̸��� ��ȯ
     * @details boost::filesystem::path ���� ���� ��θ� std::string���� ��ȯ�Ͽ� 
                ������ ���丮�� �̸��� ��ȯ�Ѵ�.
     * @param boost::filesystem::path path ������ ������ �����丮�� ���
     * @return std::string ������ ���丮 �̸�
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
