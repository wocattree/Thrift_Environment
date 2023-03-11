////////////////////////////////
//filename:Main.cpp
//
//description:主程序入口
//
//data:2023/3/11 21:39
//
//author:wocattree
//version:1.0
////////////////////////////////


//                          _ooOoo_                               //
//                         o8888888o                              //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                   /  \\|||  :  |||//  \                        //
//                  /  _||||| -:- |||||-  \                       //
//                  |   | \\\  -  /// |   |                       //
//                  | \_|  ''\---/''  |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//              ."" '<  `.___\_<|>_/___.'  >'"".                  //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /                 //
//      ========`-.____`-.___\_____/___.-`____.-'========         //
//                           `=---='                              //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //
//                  佛祖保佑       永不宕机     永无BUG              //

#pragma once
#include <thread>
#include "src/Manager/DBManager.h"
#include "src/Manager/UiThriftManager.h"
#include "src/Ui/mainWidget.h"
#include "src/Ui/environmentMonitorWidget.h"
#include "src/Common/Logs.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	auto& m_pDeviceDB = DBManager::GetInstance();
	//连接数据库
	m_pDeviceDB.Connect("localhost", "root", "1234", "m_device", 0);

    //开启thrift通信
    UiThriftManager m_pUiThriftManger;
    std::thread tThriftServer(&UiThriftManager::UiThriftInit, &m_pUiThriftManger);
    tThriftServer.detach();

    QApplication a(argc, argv);

    //主界面显示
    mainWidget w;
    w.resize(1280, 720);
    w.setStyleSheet("background-color:white;");
    w.show();

    //进入事件循环
    return a.exec(); 
}

////////////////////////////////
//function name:Init()
//
//description:初始化管理器
//
//param:
//
//return:bool
//
//data:2023/3/11 21:40
//
//author:wocattree
///////////////////////////////
bool Init()
{
    return false;
}