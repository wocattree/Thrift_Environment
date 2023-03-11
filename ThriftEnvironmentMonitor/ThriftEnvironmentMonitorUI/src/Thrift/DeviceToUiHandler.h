////////////////////////////////
//filename:DeviceToUiHandler.h
//description:UI层服务端接受文件
//data:2022/09/18 21:16:48
//author:wocattree
////////////////////////////////
#pragma once
#include <algorithm>
#include <iostream>
#include "./gen-cpp/DeviceToUi.h"
#include "../common/Logs.h"
#include "../Manager/DBManager.h"

//std::vector<double> mytemp(2, 0);

class DeviceToUiHandler : virtual public DeviceToUiIf
{
public:
    DeviceToUiHandler();

    //客户端调用的函数
    void ReportDeviceTemps(const MonitorTemps& monitortemps);

};
