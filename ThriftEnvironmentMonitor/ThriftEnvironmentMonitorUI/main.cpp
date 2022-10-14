#include "ThriftEnvironmentMonitorUI.h"
#include <QtWidgets/QApplication>
#include "../EnvironmentMonitor/logs.h"
#include "../ThriftProduce//gen-cpp/DeviceToUi.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "DeviceToUiHandler.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

void UiThrift()
{
    //初始化Thrift服务端
    int port = 9090;
    ::std::shared_ptr<DeviceToUiHandler> handler(new DeviceToUiHandler());
    ::std::shared_ptr<TProcessor> processor(new DeviceToUiProcessor(handler));
    ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
}


int main(int argc, char *argv[])
{
    std::thread tUiThrift(UiThrift);
    tUiThrift.join();

    QApplication a(argc, argv);
    ThriftEnvironmentMonitorUI w;
    w.show();
    return a.exec();
    
    
}
