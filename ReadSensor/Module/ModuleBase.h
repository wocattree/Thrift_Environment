////////////////////////////////
//filename:ModuleBase.h
//description:模块管理基类
//data:2022/09/17 20:08:29
//author:wocattree
////////////////////////////////

#pragma once
#include <vector>
#include <chrono>
#include<thread>
#include <iostream>
#include <random>
#include "../logs/logs.h"
#include "../Thrift/DeviceToUiProxy.h"
#include "../ThreadBase.h"
#include "../Device.h"


class CModuleBase : public CThreadBase
{
public:
    CModuleBase(CDevice * pDevice);
    ~CModuleBase();
};
