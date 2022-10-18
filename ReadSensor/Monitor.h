#pragma once
#include "./MonitorTempHumiRead.h"
#include "ThreadBase.h"

class CMonitor : public CThreadMonitorBase
{
public:
	CMonitor(CDevice* pDevice);
	~CMonitor();

public:
	std::vector<std::shared_ptr<CThreadMonitorBase>>				m_vMonitorThread;
	void InitThread();
	void RunThread();
private:
	bool StartThread();
};

