////////////////////////////////
//filename:Device.h
//description:��λ���豸��
//data:2022/09/17 20:46:53
//author:wocattree
////////////////////////////////

#pragma once
#include<vector>
#include <thread>
#include <boost/noncopyable.hpp>
#include "./logs/logs.h"
#include "./Monitor.h"


class CDevice : boost::noncopyable
{
public:
    CDevice();
    ~CDevice();

public:

    std::shared_ptr<CMonitor> GetMonitor()
    {
        return m_monitor;
    }

private:
    std::shared_ptr<CMonitor>                                           m_monitor;
};