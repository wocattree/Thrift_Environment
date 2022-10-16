#include"UiThriftManager.h"

UiThriftManager::UiThriftManager()
{

}

UiThriftManager::~UiThriftManager()
{

}

void UiThriftManager::UiThriftInit()
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