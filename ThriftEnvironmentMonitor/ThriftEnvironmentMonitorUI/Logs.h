#pragma once
////////////////////////////////
//filename:Logs.h
//description:日志类单例
//data:2022/10/15 20:54:53
//author:wocattree
////////////////////////////////
#include <iostream>
#include <string>
#include <memory>
#include <time.h>
#include <chrono>
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h" // or "../stdout_sinks.h" if no color needed
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

// use embedded macro to support file and line number
#define PLOG(level,...) SPDLOG_LOGGER_CALL(XLogger::getInstance()->getPLogger().get(),XLogger::getInstance()->getPLogInfo(level),__VA_ARGS__)
#define ALOG(level,...) SPDLOG_LOGGER_CALL(XLogger::getInstance()->getALogger().get(),XLogger::getInstance()->getALogInfo(level),__VA_ARGS__)

///////////////////////////////////////////
//使用方法：
//    PLOG("debug", "helllo");
//    ALOG("debug", "helllo");
///////////////////////////////////////////

class XLogger
{

public:
    static XLogger* getInstance()
    {
        static XLogger xlogger;
        return &xlogger;
    }

    std::shared_ptr<spdlog::logger> getPLogger()
    {
       return m_Plogs;
    }

    std::shared_ptr<spdlog::logger> getALogger()
    {
        return m_Alogs;
    }


    spdlog::level::level_enum getPLogInfo(std::string level);
    spdlog::level::level_enum getALogInfo(std::string level);
private:
    // make constructor private to avoid outside instance
    XLogger();

    ~XLogger();

    void* operator new(size_t size)
    {}

    XLogger(const XLogger&) = delete;
    XLogger& operator=(const XLogger&) = delete;

private:
    //新建两个日志P_Logs和A_Logs
    std::shared_ptr<spdlog::logger>         m_Plogs;            //应用程序流程日志
    std::shared_ptr<spdlog::logger>         m_Alogs;            //应用程序运行日志

};