////////////////////////////////
//filename:Device.h
//description:��λ���豸��
//data:2022/09/17 20:46:53
//author:wocattree
////////////////////////////////

#pragma once
#include "./Thrift/DeviceToUiProxy.h"
#include <boost/noncopyable.hpp>
#include<vector>
#include <thread>
#include <memory>
#include "./logs/logs.h"


class CDevice : public boost::noncopyable
{
public:
    CDevice();
    ~CDevice();

public:

private:

};