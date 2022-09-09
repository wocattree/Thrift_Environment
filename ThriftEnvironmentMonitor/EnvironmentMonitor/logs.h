#pragma once
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include <iostream>
#include "spdlog/logger.h"

////////////////////////////////
//filename:logs.h
//description:环境监视系统日志类
//data:2022/09/10 0:11:27
//author:wocattree
////////////////////////////////

class SystemLogs
{
public:
	SystemLogs();
	~SystemLogs();
public:
	std::shared_ptr<spdlog::logger>						A_LOG;					// 应用打印日志
	std::shared_ptr<spdlog::logger>						P_LOG;					// 流程打印日志
	std::shared_ptr<spdlog::logger>						D_LOG;					// 调试打印日志
	
	
};