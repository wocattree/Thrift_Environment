////////////////////////////////
//filename:Device.h
//description:��λ���豸��
//data:2022/09/17 20:46:53
//author:wocattree
////////////////////////////////

#pragma once
#include <thread>
#include "ModuleSimuTemp.h"
#include "logs.h"


class CDevice
{
private:    //����ʽ����ģʽ��Ĭ�Ϲ��캯���Ϳ������캯������private
    //��ֹ�ⲿ����
    CDevice();
    //��ֹ�ⲿ����
    ~CDevice();
    //��ֹ�ⲿ���ƹ���
    CDevice(const CDevice& other);
    // ��ֹ�ⲿ��ֵ����
    const CDevice& operator=(const CDevice& device);
public:
    // Ψһʵ��������,c++11��staticΪ�̰߳�ȫ
    static CDevice* GetInstance() {
        static CDevice instance;
        return &instance;
    }

    ////////////////////////////////
    //funcname:
    //description:����¶�ģ��ģ��ָ��
    //param:
    //return:
    //data:2022/09/17 21:46:39
    //author:wocattree
    ///////////////////////////////
    std::shared_ptr<SimuData::TempInfo::CModuleSimuTemp>     GetMoudleSimuTemp();

    ////////////////////////////////
    //funcname:InitDevice()
    //description:��ʼ����λ���е�ģ��
    //param:
    //return:void
    //data:2022/09/17 22:20:28
    //author:wocattree
    ///////////////////////////////
    void InitDevice();

public:
    std::shared_ptr<SimuData::TempInfo::CModuleSimuTemp>                m_spModuleSimuTemp;                //�¶�ģ��ģ��ָ��
    std::shared_ptr<CLogs>                                              m_Logs;                            //��־��

private:
    std::shared_ptr<CDevice>                                            m_spDevice;                        //�豸��ָ��

private:

};