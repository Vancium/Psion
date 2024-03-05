#include "Window.hpp"
#include "../Events/EventListener.hpp"
#include "../Events/EventManager.hpp"
#include "GLFW/glfw3.h"
#include "../Logger/Logger.hpp"

namespace Psion {

    static void KeyPressCallback( GLFWwindow *window, int key, int scancode,
                                  int action, int mods ) {
        struct KeyData data {
            .key = key, .scancode = scancode, .action = action, .mods = mods
        };
        EventManager &e = EventManager::GetInstance();

        if ( data.action == GLFW_PRESS ) {
            e.Trigger( EventKeyPress, &data );
        } else {
            e.Trigger( EventKeyRelease, &data );
        }
    }

    Window::Window( std::string name, unsigned int width, unsigned int height )
        : mWidth( width ), mHeight( height ) {
        // TODO move to subsytem manager
        if ( !glfwInit() ) {
            PS_CRITICAL( "Could not initialize GLFW." );
        }

        mHandle =
            glfwCreateWindow( mWidth, mHeight, name.c_str(), nullptr, nullptr );

        if ( !mHandle ) {
            PS_CRITICAL( "Could not create GLFW window." );
        }
        glfwSetKeyCallback( mHandle, KeyPressCallback );

        glfwMakeContextCurrent( mHandle );
    }

    GLFWwindow *Window::GetHandle() { return mHandle; }
    Window::~Window() {}
} // namespace Psion
