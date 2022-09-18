#include "logs.h"

////////////////////////////////
//filename:logs.cpp
//description:环境监视系统日志类
//data:2022/09/10 0:11:56
//author:wocattree
////////////////////////////////

CLogs::CLogs()
{
    try
    {
        A_LOG = spdlog::rotating_logger_mt("A_LOGS", "logs/A_LOGS.txt", 1048576 * 5, 3);
        A_LOG->flush_on(spdlog::level::trace);
        //rotating_logger->info("a = {}, b = {}, a/b = {}, a%b = {}", a, b, a / b, a % b);
        //rotating_logger->flush();用法
        P_LOG = spdlog::rotating_logger_mt("P_LOGS", "logs/P_LOGS.txt", 1048576 * 5, 3);
        P_LOG->flush_on(spdlog::level::trace);
        D_LOG = spdlog::rotating_logger_mt("D_LOGS", "logs/D_LOGS.txt", 1048576 * 5, 3);
        D_LOG->flush_on(spdlog::level::trace);
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    }
}

CLogs::~CLogs()
{

}


