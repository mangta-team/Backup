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
namespace bfs = boost::filesystem;

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
     * @details ����Լ�, root�� dest�� ���� ������ ������ ��¥ ��, �ٸ��� root�� ������ ����Ѵ�.
     * @param boost::filesystem::path root ���� ���
     * @param boost::filesystem::path deest ���纻 ���
     * @commnet �Ű������� ���� �����ϱ�
     *          boost::system::error_code�� �⺻���� ������ �޼ҵ带 ������ �� ������ ����
     */
    void static sync(bfs::path root, bfs::path dest/*, boost::system::error_code*/);
    
    /**
     * @brief �Ű������� ���� ��ο��� ������ ���丮 �̸��� ��ȯ
     * @details boost::filesystem::path ���� ���� ��θ� std::string���� ��ȯ�Ͽ� 
                ������ ���丮�� �̸��� ��ȯ�Ѵ�.
     * @param boost::filesystem::path path ������ ������ �����丮�� ���
     * @return std::string ������ ���丮 �̸�
     */
    std::string static get_dir_name(bfs::path& path);

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
};
	
#endif // !SYNC_HPP
