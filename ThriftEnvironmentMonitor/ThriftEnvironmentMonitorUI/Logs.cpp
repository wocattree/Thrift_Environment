////////////////////////////////
//filename:Logs.cpp
//description:日志类单例
//data:2022/10/15 21:04:22
//author:wocattree
////////////////////////////////
#include "Logs.h"

static inline int NowDateToInt()
{
    time_t now;
    time(&now);
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32
    int now_date = (1900 + p.tm_year) * 10000 + (p.tm_mon + 1) * 100 + p.tm_mday;
    return now_date;
}

static inline int NowTimeToInt()
{
    time_t now;
    time(&now);
    // choose thread save version in each platform
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32

    int now_int = p.tm_hour * 10000 + p.tm_min * 100 + p.tm_sec;
    return now_int;
}


XLogger::XLogger()
{
    // hardcode log path
    const std::string log_dir = "./log"; 

    // decide print to console or log file
    bool console = false;

    // decide the log level
    std::string level = "debug";

    try
    {
        // logger name with timestamp
        int date = NowDateToInt();
        int time = NowTimeToInt();

        const std::string logger_PlogsName = "P_Logs";
        const std::string logger_AlogsName = "A_Logs";

        if (console)
            m_Plogs = spdlog::stdout_color_st(logger_PlogsName);
        else
            // only one log file
            // multi part log files, with every part 500M, max 1000 files
            m_Plogs = spdlog::create_async<spdlog::sinks::rotating_file_sink_mt>(logger_PlogsName, log_dir + "/Process.log", 1048576 * 5, 3);
            m_Alogs = spdlog::create_async<spdlog::sinks::rotating_file_sink_mt>(logger_AlogsName, log_dir + "/App.log", 1048576 * 5, 3);

        // custom format
            m_Plogs->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] [%t] %s:%# %! : %v");
            m_Alogs->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] [%t] %s:%# %! : %v");
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    }
}

XLogger::~XLogger()
{
    spdlog::drop_all(); // must do this
}

spdlog::level::level_enum XLogger::getPLogInfo(std::string level)
{
    if (level == "trace")
    {
        m_Plogs->set_level(spdlog::level::trace);
        m_Plogs->flush_on(spdlog::level::trace);
        return spdlog::level::trace;
    }
    else if (level == "debug")
    {
        m_Plogs->set_level(spdlog::level::debug);
        m_Plogs->flush_on(spdlog::level::debug);
        return spdlog::level::debug;
    }
    else if (level == "info")
    {
        m_Plogs->set_level(spdlog::level::info);
        m_Plogs->flush_on(spdlog::level::info);
        return spdlog::level::info;
    }
    else if (level == "warn")
    {
        m_Plogs->set_level(spdlog::level::warn);
        m_Plogs->flush_on(spdlog::level::warn);
        return spdlog::level::warn;
    }
    else if (level == "error")
    {
        m_Plogs->set_level(spdlog::level::err);
        m_Plogs->flush_on(spdlog::level::err);
        return spdlog::level::err;
    }
}

spdlog::level::level_enum XLogger::getALogInfo(std::string level)
{
    if (level == "trace")
    {
        m_Alogs->set_level(spdlog::level::trace);
        m_Alogs->flush_on(spdlog::level::trace);
        return spdlog::level::trace;
    }
    else if (level == "debug")
    {
        m_Alogs->set_level(spdlog::level::debug);
        m_Alogs->flush_on(spdlog::level::debug);
        return spdlog::level::debug;
    }
    else if (level == "info")
    {
        m_Alogs->set_level(spdlog::level::info);
        m_Alogs->flush_on(spdlog::level::info);
        return spdlog::level::info;
    }
    else if (level == "warn")
    {
        m_Alogs->set_level(spdlog::level::warn);
        m_Alogs->flush_on(spdlog::level::warn);
        return spdlog::level::warn;
    }
    else if (level == "error")
    {
        m_Alogs->set_level(spdlog::level::err);
        m_Alogs->flush_on(spdlog::level::err);
        return spdlog::level::err;
    }
}
