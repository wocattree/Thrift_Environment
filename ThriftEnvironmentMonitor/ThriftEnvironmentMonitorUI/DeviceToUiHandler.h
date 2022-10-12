////////////////////////////////
//filename:DeviceToUiHandler.h
//description:UI层服务端接受文件
//data:2022/09/18 21:16:48
//author:wocattree
////////////////////////////////
#pragma once
#include <algorithm>
#include"../ThriftProduce/gen-cpp/DeviceToUi.h"
#include <iostream>

class DeviceToUiHandler : virtual public DeviceToUiIf
{
public:
    DeviceToUiHandler();

    //客户端调用的函数
    void ReportDeviceTemps(const MonitorTemps& monitortemps);

};
