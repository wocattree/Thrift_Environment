////////////////////////////////
//filename:Device.cpp
//description:��λ���豸��
//data:2022/09/17 20:47:20
//author:wocattree
////////////////////////////////
#include "Device.h"

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

    //��ʼ��Ψһʵ��ָ��
    CDevice* pDevice = CDevice::GetInstance();
    pDevice->m_spModuleSimuTemp.reset(new SimuData::TempInfo::CModuleSimuTemp());
    pDevice->m_Logs.reset(new CLogs());
    
    while (true)
    {
        if (pDevice == nullptr)
        {
            //��ӡ������־
            return;
        }

        pDevice->InitDevice();
    }

}

int main()
{

    std::thread   tMainThread(ThreadInit);
    //ѭ�������߳�
    tMainThread.join();

    return 0;
}


void CDevice::InitDevice()
{
    m_spModuleSimuTemp->Run();
    //m_Logs->D_LOG->info("���Գɹ�");

    //m_Logs->A_LOG->debug("���Գɹ�");

    //m_Logs->P_LOG->error("���Գɹ�");
}

std::shared_ptr<SimuData::TempInfo::CModuleSimuTemp> CDevice::GetMoudleSimuTemp()
{
    return m_spModuleSimuTemp;
}