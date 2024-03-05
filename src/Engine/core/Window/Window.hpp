#pragma once

#include "../../Psion.hpp"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Psion {

    struct KeyData {
        int key, scancode, action, mods;
    };
    class PSION_API Window {
      public:
        Window( std::string name, unsigned int width, unsigned int height );
        ~Window();
        GLFWwindow *GetHandle();

      private:
        GLFWwindow *mHandle;
        unsigned int mWidth;
        unsigned int mHeight;
    };
} // namespace Psion
