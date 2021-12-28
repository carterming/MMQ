#include <iostream>
#include <string>

#include "common/constants.h"
#include "common/log.h"

int logInit() {
    int ret = 0;
    ret = mmq::Mlog::getInstance()->init(mmq::lOGGERNAME, mmq::LOGFILENAME,
                                         mmq::MAXFILESIZE, mmq::MAXFILES,
                                         spdlog::level::debug);
    return ret;
}
int main() {
    if (-1 == logInit()) {
        exit(1);
    }

    DEBUGLOG("Log init success.");
    return 0;
}
