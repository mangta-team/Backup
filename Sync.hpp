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
 * @brief ����ȭ �޼ҵ�
 * @details ����Լ�, source�� dest�� ���� ������ ������ ��¥ ��, �ٸ��� source�� ������ ����Ѵ�.
 * @param boost::filesystem::path source ���� ���
 * @param boost::filesystem::path deest ���纻 ���
 * @commnet boost::system::error_code�� �⺻���� ������ �޼ҵ带 ������ �� ������ ����
 *          ���� �߻�, ����Լ� ȣ���� �������η� ȣ��
 */
void sync(const bfs::path &source, const bfs::path &dest/*, boost::system::error_code*/);

} // !namespace sycn
} // !namespace backup	

#endif // !SYNC_HPP