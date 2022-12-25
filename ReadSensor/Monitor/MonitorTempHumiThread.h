#pragma once

#include "../Thread/ThreadMonitorBase.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;

class CMonitorHumiThread : public CThreadMonitorBase
{
public:
    CMonitorHumiThread(CDevice* pDevice);
    ~CMonitorHumiThread();

public:

    void BeginRecvTempHumi();
    virtual int Run();
    void GPIO_init(int gpio_pin);
    void DHT11_start(int gpio_pin);
    uint8 DHT11_read(int gpio_pin);

    uint32 databuf;

    std::shared_ptr<std::thread>			m_spThread; //×ÓÏß³Ì
    virtual void WaitThreadFinish() override;
private:

};