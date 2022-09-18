#include "Main.h"


void ThreadInit()
{
    //初始化唯一实例指针
    CDevice* pDevice = CDevice::GetInstance();

    if (pDevice == nullptr)
    {
        //打印错误日志
        return;
    }

    pDevice->m_spModuleSimuTemp.reset(new SimuData::TempInfo::CModuleSimuTemp());
    pDevice->InitDevice();
}