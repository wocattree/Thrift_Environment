#include"ModuleSimuTemp.h"

SimuData::TempInfo::CModuleSimuTemp::CModuleSimuTemp(CDevice* pDevice) :  CModuleBase(pDevice)
    ,TempIndex(0)
{
    vSimuTempInfos.resize(10);
}

SimuData::TempInfo::CModuleSimuTemp::~CModuleSimuTemp()
{

}


//int SimuData::TempInfo::CModuleSimuTemp::Run()
//{
//   // CDevice *m_Device = CDevice::GetInstance();
//    ProduceTemps();
//  //  m_Device->m_Logs->D_LOG->info("�¶��������");
//    return 1;
//}

void SimuData::TempInfo::CModuleSimuTemp::ProduceTemps()
{
    //ÿһ���Ӳ���ģ����¶���ֵ
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //��ʱ����Ϊ���������,vs�е�time_t��64λ����default_random_engine��Ҫunsigned int 32λ������ǿת
    std::default_random_engine e(static_cast<unsigned int> (time(0)));
    //�¶ȷ�Χ
    std::uniform_real_distribution<float> u(30, 42.5);

    if (TempIndex == 10)
    {
        TempIndex = 0;
    }

    vSimuTempInfos[TempIndex] = round( u(e) * 10) / 10;

    TempIndex = TempIndex + 1;
}


std::vector<float> SimuData::TempInfo::CModuleSimuTemp::GetSimuTemoInfos()
{
    return vSimuTempInfos;
}
