#pragma once
#include "D:\Software_Data\CppEnv\vcpkg\packages\thrift_x64-windows\tools\thrift\gen-cpp\printhello.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>


class printhelloHandler : virtual public printhelloIf {
public:
	printhelloHandler() {
		// Your initialization goes here
	}

	void hello(const std::string& h) {
		// Your implementation goes here
		printf("hello\n");
	}

};

void UiControlData();

