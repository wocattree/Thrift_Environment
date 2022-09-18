////////////////////////////////
//filename:DeviceToUiProxy.cpp
//description:Thrift客户端文件
//data:2022/09/18 21:16:15
//author:wocattree
////////////////////////////////

#include "DeviceToUiProxy.h"
#include "D:\Software_Data\Code\Cpp\ThriftEnvironmentMonitor\ThriftEnvironmentMonitor\ThriftProduce\gen-cpp\DeviceToUi.h"  //客户端项目这里引入上面thrift文件定义的接口
#include<thrift/transport/TSocket.h>
#include<thrift/transport/TBufferTransports.h>
#include<thrift/protocol/TBinaryProtocol.h>
#include <list>
#include <vector>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;



DeviceToUiProxy::DeviceToUiProxy()
{
}

DeviceToUiProxy::~DeviceToUiProxy()
{
}

void DeviceToUiProxy::ReportDeviceTemps()
{
    MonitorTemps sMonitorTemps; //定义的结构体
    ::std::shared_ptr<TSocket> socket(new TSocket("127.0.0.1", 9090)); //客户端连接当前端口
    ::std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    ::std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    transport->open();
    std::vector<double> testTemp(10, 5);        //赋初始值进行测试
    sMonitorTemps.Temps = testTemp;
    DeviceToUiClient client(protocol); //调用自动生成的client对象，通过client对象调用服务端方法
    printf("客户端开始调用服务端的方法：ReportDeviceTemps()\n");
    client.ReportDeviceTemps(sMonitorTemps); //到这一步客户端已经往服务端发送了数据
}