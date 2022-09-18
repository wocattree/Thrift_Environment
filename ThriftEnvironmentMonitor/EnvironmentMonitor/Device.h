////////////////////////////////
//filename:Device.h
//description:下位机设备类
//data:2022/09/17 20:46:53
//author:wocattree
////////////////////////////////

#pragma once
#include <thread>
#include "ModuleSimuTemp.h"
#include "logs.h"


class CDevice
{
private:    //饿汉式单例模式，默认构造函数和拷贝构造函数都是private
    //禁止外部构造
    CDevice();
    //禁止外部析构
    ~CDevice();
    //禁止外部复制构造
    CDevice(const CDevice& other);
    // 禁止外部赋值操作
    const CDevice& operator=(const CDevice& device);
public:
    // 唯一实例化对象,c++11中static为线程安全
    static CDevice* GetInstance() {
        static CDevice instance;
        return &instance;
    }

    ////////////////////////////////
    //funcname:
    //description:获得温度模拟模块指针
    //param:
    //return:
    //data:2022/09/17 21:46:39
    //author:wocattree
    ///////////////////////////////
    std::shared_ptr<SimuData::TempInfo::CModuleSimuTemp>     GetMoudleSimuTemp();

    ////////////////////////////////
    //funcname:InitDevice()
    //description:初始化下位机中的模块
    //param:
    //return:void
    //data:2022/09/17 22:20:28
    //author:wocattree
    ///////////////////////////////
    void InitDevice();

public:
    std::shared_ptr<SimuData::TempInfo::CModuleSimuTemp>                m_spModuleSimuTemp;                //温度模拟模块指针
    std::shared_ptr<CLogs>                                              m_Logs;                            //日志类

private:
    std::shared_ptr<CDevice>                                            m_spDevice;                        //设备类指针

private:

};