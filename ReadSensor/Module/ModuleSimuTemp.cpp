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
//  //  m_Device->m_Logs->D_LOG->info("温度生成完毕");
//    return 1;
//}

void SimuData::TempInfo::CModuleSimuTemp::ProduceTemps()
{
    //每一秒钟产生模拟的温度数值
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //以时间作为随机数种子,vs中的time_t是64位，而default_random_engine需要unsigned int 32位，所以强转
    std::default_random_engine e(static_cast<unsigned int> (time(0)));
    //温度范围
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
