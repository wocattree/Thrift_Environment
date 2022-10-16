#pragma once

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "../ThriftProduce//gen-cpp/DeviceToUi.h"
#include "DeviceToUiHandler.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class UiThriftManager
{
public:
    UiThriftManager();
    ~UiThriftManager();

public:
    void UiThriftInit();

};