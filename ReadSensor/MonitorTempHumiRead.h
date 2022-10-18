#pragma once
#include "ThreadMonitorBase.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;


class CMonitorTempHumiRead : public CMonitor
{
public:
	CMonitorTempHumiRead(CDevice* pDevice);
	~CMonitorTempHumiRead();
public:
	void BeginRecvTempHumi();
	void Run();
	void GPIO_init(int gpio_pin);
	void DHT11_start(int gpio_pin);
	uint8 DHT11_read(int gpio_pin);

	uint32 databuf;

private:

};


