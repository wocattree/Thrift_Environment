#pragma once

#include "ThreadBase.h"

class CThreadMonitorBase : public CThreadBase
{
public:
    CThreadMonitorBase(CDevice* pDevice);
    ~CThreadMonitorBase();



protected:
    CDevice* m_pDevice;

    std::shared_ptr<CThreadBase> GetSharedPtrFromThis();

private:


};

