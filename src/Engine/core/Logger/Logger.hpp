#pragma once

#include "../../Psion.hpp"
#include <memory>
#include <spdlog/spdlog.h>

namespace Psion {

    class PSION_API Logger {
      public:
        static void Initialize();

        inline static std::shared_ptr<spdlog::logger> &GetLogger() {
            return sLogger;
        }

      private:
        static std::shared_ptr<spdlog::logger> sLogger;
    };

#define PS_CRITICAL( ... ) ::Psion::Logger::GetLogger()->critical( __VA_ARGS__ )
#define PS_ERROR( ... ) ::Psion::Logger::GetLogger()->error( __VA_ARGS__ )
#define PS_WARN( ... ) ::Psion::Logger::GetLogger()->warn( __VA_ARGS__ )
#define PS_DEBUG( ... ) ::Psion::Logger::GetLogger()->debug( __VA_ARGS__ )
#define PS_INFO( ... ) ::Psion::Logger::GetLogger()->info( __VA_ARGS__ )
#define PS_TRACE( ... ) ::Psion::Logger::GetLogger()->trace( __VA_ARGS__ )
} // namespace Psion
