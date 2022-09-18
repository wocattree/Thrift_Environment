#pragma once
public:
    void ThreadInit();
    void ThreadInit()
    {
        //��ʼ��Ψһʵ��ָ��
        CDevice* pDevice = CDevice::GetInstance();

        if (pDevice == nullptr)
        {
            //��ӡ������־
            return;
        }

        pDevice->m_spModuleSimuTemp.reset(new SimuData::TempInfo::CModuleSimuTemp());
        pDevice->InitDevice();
    }