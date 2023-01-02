#ifndef DM3_CORE_LOGGING_HPP
#define DM3_CORE_LOGGING_HPP

#include <util/logger.hpp>
#include <util/logger_console_sink.hpp>

namespace dm3 {

class dm3Logger {
    dm3Logger() {
        m_logger.addSink<util::logger_console_sink>("dm3ConsoleLogger");
        m_logger.logInfo("logger initalized");
    }

public:

    ~dm3Logger() {
        m_logger.logInfo("destroying logger");
    }

    static dm3Logger& instance() {
        static dm3Logger instance;
        return instance;
    }

    dm3Logger(dm3Logger const&) = delete;
    void operator=(dm3Logger const&) = delete;

public:

    util::logger m_logger;

};

#define DM3_TRACE(...) dm3::dm3Logger::instance().m_logger.logTrace(__VA_ARGS__)
#define DM3_DEBUG(...) dm3::dm3Logger::instance().m_logger.logDebug(__VA_ARGS__)
#define DM3_INFO(...) dm3::dm3Logger::instance().m_logger.logInfo(__VA_ARGS__)
#define DM3_WARN(...) dm3::dm3Logger::instance().m_logger.logWarning(__VA_ARGS__)
#define DM3_ERROR(...) dm3::dm3Logger::instance().m_logger.logError(__VA_ARGS__)
#define DM3_CRITICAL(...) dm3::dm3Logger::instance().m_logger.logCritical(__VA_ARGS__)

};

#endif
