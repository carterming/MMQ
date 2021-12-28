#include "log.h"

#include <string>

namespace mmq {
int Mlog::init(const char *logName, const char *fileName, size_t maxFileSize,
               size_t maxFiles, spdlog::level::level_enum level) {
    try {
        logging_provider =
            spdlog::rotating_logger_mt(logName, fileName, maxFileSize, maxFiles);
        logging_provider->set_level(level);
        logging_provider->flush_on(spdlog::level::trace);
    } catch (const spdlog::spdlog_ex &ex) {
        std::cout << "log init failed: " << ex.what() << std::endl;
        return -1;
    }
    return 0;
}
Mlog *Mlog::getInstance() {
    static Mlog mlog;
    return &mlog;
}
std::shared_ptr<spdlog::logger> Mlog::getLogger() { return logging_provider; }
std::shared_ptr<spdlog::logger> Mlog::logging_provider = nullptr;
}  // namespace mmq