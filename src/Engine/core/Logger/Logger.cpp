#include "Logger.hpp"

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Psion {

    std::shared_ptr<spdlog::logger> Logger::sLogger;

    void Logger::Initialize() {
        spdlog::set_pattern( "%^ [%T] %v %$" );
        sLogger = spdlog::stderr_color_mt( "CORE" );
    }
} // namespace Psion
