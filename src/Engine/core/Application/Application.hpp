#pragma once

#include "../../Psion.hpp"
#include "../Window/Window.hpp"
#include <memory>

namespace Psion {
    class PSION_API Application {
      public:
        std::string GetName();

        static Application &GetInstance( std::string name, unsigned int width,
                                         unsigned int height );

        void Run();
        ~Application();

      private:
        Application( std::string name, unsigned int height,
                     unsigned int width );
        std::string mName;
        std::unique_ptr<Window> mWindow;

        bool mRunning = false;
    };
} // namespace Psion
