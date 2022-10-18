#include "Monitor.h"

CMonitor::CMonitor(CDevice* pDevice) : ThreadBase(pDevice)
{

}

CMonitor::~CMonitor()
{
}

void CMonitor::InitThread()
{
    std::shared_ptr <CThreadMonitorBase> m_spMonitorTempHumiRead;
    m_spMonitorTempHumiRead.reset(new CMonitorTempHumiRead());
    m_vMonitorThread.push_back(m_spMonitorTempHumiRead);
}

void CMonitor::RunThread()
{
    for(auto& thread : m_vMonitorThread)
    {
        thread->Run();
    }
}

bool CMonitor::StartThread()
{

}

