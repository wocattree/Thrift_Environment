#pragma once
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include <iostream>
#include "spdlog/logger.h"

////////////////////////////////
//filename:logs.h
//description:��������ϵͳ��־��
//data:2022/09/10 0:11:27
//author:wocattree
////////////////////////////////

class SystemLogs
{
public:
	SystemLogs();
	~SystemLogs();
public:
	std::shared_ptr<spdlog::logger>						A_LOG;					// Ӧ�ô�ӡ��־
	std::shared_ptr<spdlog::logger>						P_LOG;					// ���̴�ӡ��־
	std::shared_ptr<spdlog::logger>						D_LOG;					// ���Դ�ӡ��־
	
	
};