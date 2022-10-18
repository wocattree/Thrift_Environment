////////////////////////////////
//filename:Device.cpp
//description:下位机设备类
//data:2022/09/17 20:47:20
//author:wocattree
////////////////////////////////
#include "Device.h"


CDevice::CDevice()
{
    m_monitor.reset(new CMonitor(this));
}

CDevice::~CDevice()
{

}

