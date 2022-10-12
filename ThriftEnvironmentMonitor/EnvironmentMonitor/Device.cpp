////////////////////////////////
//filename:Device.cpp
//description:下位机设备类
//data:2022/09/17 20:47:20
//author:wocattree
////////////////////////////////
#include "Device.h"
#include "DeviceToUiProxy.h"

CDevice::CDevice()
{

}

CDevice::CDevice(const CDevice& other)
{

}

CDevice::~CDevice()
{

}

void ThreadInit()
{

    //初始化唯一实例指针
    CDevice* pDevice = CDevice::GetInstance();
    pDevice->m_spModuleSimuTemp.reset(new SimuData::TempInfo::CModuleSimuTemp());
    pDevice->m_Logs.reset(new CLogs());
    
    while (true)
    {
        if (pDevice == nullptr)
        {
            //打印错误日志
            return;
        }

        pDevice->InitDevice();
    }

}
////////////////////////////////
//funcname:
//description:调用Thrift服务
//param:
//return:
//data:2022/09/19 21:32:11
//author:wocattree
///////////////////////////////
void ThriftSend()
{
    DeviceToUiProxy::DeviceToUiProxy();
}

int main()
{

    //std::thread   tMainThread(ThreadInit);
    //循环启动线程
    //tMainThread.join();

    //std::thread tThriftSend(ThriftSend);
    //tThriftSend.join();

    return 0;
}


void CDevice::InitDevice()
{
    m_spModuleSimuTemp->Run();
    //m_Logs->D_LOG->info("调试成功");

    //m_Logs->A_LOG->debug("调试成功");

    //m_Logs->P_LOG->error("调试成功");
}

std::shared_ptr<SimuData::TempInfo::CModuleSimuTemp> CDevice::GetMoudleSimuTemp()
{
    return m_spModuleSimuTemp;
}