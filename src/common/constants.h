#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__
#include <iostream>

namespace mmq {
constexpr static const char *lOGGERNAME = "logger";
constexpr static const char *LOGFILENAME = "/tmp/mmq.log";
constexpr static const size_t MAXFILESIZE = 3 * 1024 * 1024 * 1024UL;
constexpr static const size_t MAXFILES = 3 * 1024 * 1024 * 1024UL;
}  // namespace mmq
#endif