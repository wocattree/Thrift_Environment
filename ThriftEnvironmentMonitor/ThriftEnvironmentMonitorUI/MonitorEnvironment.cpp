#pragma once
#include "UiThriftManager.h"
#include "ThriftEnvironmentMonitorUI.h"
#include "./logs.h"
#include <QtWidgets/QApplication>
#include <thread>
#include"DeviceDB.h"


int main(int argc, char *argv[])
{
	auto& m_pDeviceDB = DeviceDB::GetInstance();
	//连接数据库
	m_pDeviceDB.Connect("localhost", "root", "1234", "m_device", 0);

    //开启thrift通信
    UiThriftManager m_pUiThriftManger;
    std::thread tThriftServer(&UiThriftManager::UiThriftInit, &m_pUiThriftManger);
    tThriftServer.detach();

    QApplication a(argc, argv);
    ThriftEnvironmentMonitorUI w;
    w.show();

    //进入事件循环
    return a.exec(); 
}