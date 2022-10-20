#pragma once

#include "../Thread/ThreadMonitorBase.h"
#include "MonitorTempHumiThread.h"

class CMonitor : public CThreadMonitorBase // , public boost::noncopyable
{
public:
    CMonitor(CDevice* pDevice);
    ~CMonitor();

    void StarkWork();

    void StopWork();

    void InitThread();

    void RunThread();

    void StopSubThread();
private:
    std::vector<std::shared_ptr<CThreadMonitorBase>> m_vThreadMonitor;
};

