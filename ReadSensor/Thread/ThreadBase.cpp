#include "ThreadBase.h"

CThreadBase::CThreadBase(CDevice* pDevice)
    :m_bStop(false), m_bHasError(false), m_bPause(false), m_pDevice(pDevice), m_bFinished(false)
{

}

CThreadBase::~CThreadBase()
{
}


int CThreadBase::ContinueRun()
{
    while (IsPause())
    {
        if (IsStop() || HasError())
        {
            return 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    if ((!IsStop()) && (!HasError()))
    {
        return 1;
    }
    return 0;
}

int CThreadBase::Run()
{
    return 0;
}

bool CThreadBase::IsStop()
{
    return m_bStop;
}

void CThreadBase::SetStop(bool bstop)
{
    m_bStop = bstop;
}

bool CThreadBase::HasError(void)
{
    return m_bHasError;
}

void CThreadBase::SetError(bool bError)
{
    m_bHasError = bError;
}

bool CThreadBase::IsPause(void)
{
    return m_bPause;
}

//暂停调度
void CThreadBase::Pause(void)
{
    m_bPause = true;
}

//继续运行
void CThreadBase::Resume(void)
{
    m_bPause = false;
}

bool CThreadBase::IsFinished()
{
    return m_bFinished;
}

void CThreadBase::SetFinish(bool bFinish)
{
    m_bFinished = bFinish;
}

//给子类重写
void CThreadBase::WaitThreadFinish()
{

}
