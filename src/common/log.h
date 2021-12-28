#ifndef __LOG_H__
#define __LOG_H__

#include <iostream>
#include <memory>
#include <string>

#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/spdlog.h"

#define SPDLOG_BASE(logger, level, ...) \
    (logger)->log(spdlog::source_loc{__FILE__, __LINE__, __func__}, level, __VA_ARGS__)
#define TRACELOG(...) \
    SPDLOG_BASE(mmq::Mlog::getInstance()->getLogger(), spdlog::level::trace, __VA_ARGS__)
#define DEBUGLOG(...) \
    SPDLOG_BASE(mmq::Mlog::getInstance()->getLogger(), spdlog::level::debug, __VA_ARGS__)
#define INFOLOG(...) \
    SPDLOG_BASE(mmq::Mlog::getInstance()->getLogger(), spdlog::level::info, __VA_ARGS__)
#define WARNLOG(...) \
    SPDLOG_BASE(mmq::Mlog::getInstance()->getLogger(), spdlog::level::warn, __VA_ARGS__)
#define ERRORLOG(...) \
    SPDLOG_BASE(mmq::Mlog::getInstance()->getLogger(), spdlog::level::err, __VA_ARGS__)
#define CRITICALLOG(...)                                                        \
    SPDLOG_BASE(mmq::Mlog::getInstance()->getLogger(), spdlog::level::critical, \
                __VA_ARGS__)

namespace mmq {

class Mlog {
public:
    int init(const char *logName, const char *fileName, size_t maxFileSize,
             size_t maxFiles, spdlog::level::level_enum level);
    static Mlog *getInstance();
    std::shared_ptr<spdlog::logger> getLogger();

private:
    static std::shared_ptr<spdlog::logger> logging_provider;
};
}  // namespace mmq
#endif