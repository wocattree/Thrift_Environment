#include "logs.h"

////////////////////////////////
//filename:logs.cpp
//description:环境监视系统日志类
//data:2022/09/10 0:11:56
//author:wocattree
////////////////////////////////

SystemLogs::SystemLogs()
{
	A_LOG = spdlog::basic_logger_mt("sbasic_logger", "logs/A_LOGS.txt");
	P_LOG = spdlog::basic_logger_mt("sbasic_logger", "logs/P_LOGS.txt");
	D_LOG = spdlog::basic_logger_mt("sbasic_logger", "logs/D_LOGS.txt");
	try
	{
		//在logs/basic.txt中写下Hello world
		A_LOG->info("Hello {}", "world");
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		std::cout << "Log initialization failed: " << ex.what() << std::endl;
	}
}

SystemLogs::~SystemLogs()
{

}


