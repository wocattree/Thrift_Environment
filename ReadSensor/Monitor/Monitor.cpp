#include "Monitor.h"

CMonitor::CMonitor(CDevice* pDevice) : CThreadMonitorBase(pDevice)
{
}

CMonitor::~CMonitor()
{
    StopWork();
}

void CMonitor::StarkWork()
{
    InitThread();
    RunThread();
}

void CMonitor::StopWork()
{
    //Í£Ö¹×ÓÏß³Ì
    StopSubThread();
    m_vThreadMonitor.clear();
}

void CMonitor::InitThread()
{
    std::shared_ptr<CThreadMonitorBase> SPMoniTempHumi(new CMonitorHumiThread(m_pDevice));
    m_vThreadMonitor.push_back(SPMoniTempHumi);
}

void CMonitor::RunThread()
{
    for (auto& thread : m_vThreadMonitor)
    {
        thread->Run();
    }
}

void CMonitor::StopSubThread()
{
    for (auto& thread : m_vThreadMonitor)
    {
        thread->SetStop(true);
        thread->WaitThreadFinish();
    }
}
