#pragma once

#include<boost/noncopyable.hpp>
#include "../Device.h"

class CThreadBase : public boost::noncopyable, public std::enable_shared_from_this<CThreadBase>
{
public:
    CThreadBase(CDevice* pDevice);
    ~CThreadBase();


    virtual int ContinueRun();

    virtual int Run();

    bool IsStop();

    virtual void SetStop(bool bstop);

    bool HasError(void);

    virtual void SetError(bool bError);

    bool IsPause(void);

    void Pause(void);

    void Resume(void);

    virtual bool IsFinished();

    virtual void SetFinish(bool bFinish);

    virtual void WaitThreadFinish();

protected:
    CDevice* m_pDevice;					//设备对象

private:
    bool m_bStop;
    bool m_bHasError;
    bool m_bPause;
    bool m_bFinished;
};
