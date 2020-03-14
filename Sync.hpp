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

namespace tmp // �ӽ� ���ӽ����̽�
{
namespace sync
{

/**
 * @brief ����ȭ �޼ҵ�
 * @details ����Լ�, root�� dest�� ���� ������ ������ ��¥ ��, �ٸ��� root�� ������ ����Ѵ�.
 * @param boost::filesystem::path root ���� ���
 * @param boost::filesystem::path deest ���纻 ���
 * @commnet boost::system::error_code�� �⺻���� ������ �޼ҵ带 ������ �� ������ ����
 *          ���� �߻�, ����Լ� ȣ���� �������η� ȣ��
 */
void sync(const bfs::path &root, const bfs::path &dest/*, boost::system::error_code*/);

} // !namespace sycn
} // !namespace tmp	

#endif // !SYNC_HPP