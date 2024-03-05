#include "Application.hpp"
#include "../Events/EventListener.hpp"
#include "../Events/EventManager.hpp"
#include "GLFW/glfw3.h"
#include <memory>
#include <string>
#include "../Logger/Logger.hpp"

#include "../Window/Window.hpp"

namespace Psion {

    static void KeyPressCallback( void *data ) {
        struct KeyData *keyData = static_cast<struct KeyData *>( data );

        PS_INFO( "KeyPressEvent:\n\tkey: {0}\n\tscancode: {1}\n\taction: "
                 "{2}\n\tmods: {3}",
                 keyData->key, keyData->scancode, keyData->action,
                 keyData->mods );
    }
    static void KeyReleaseCallback( void *data ) {
        struct KeyData *keyData = static_cast<struct KeyData *>( data );

        PS_INFO( "KeyReleaseEvent:\n\tkey: {0}\n\tscancode: {1}\n\taction: "
                 "{2}\n\tmods: {3}",
                 keyData->key, keyData->scancode, keyData->action,
                 keyData->mods );
    }

    Application::Application( std::string name, unsigned int width,
                              unsigned int height )
        : mName( name ), mRunning( true ) {

        mWindow = std::unique_ptr<Window>( new Window( name, width, height ) );
    }

    Application::~Application() { PS_INFO( "Application Destroyed" ); }

    Application &Application::GetInstance( std::string name, unsigned int width,
                                           unsigned int height ) {
        static Application instance( name, width, height );

        PS_INFO( "Application {0} created", name );

        return instance;
    }

    void Application::Run() {

        EventManager &e = EventManager::GetInstance();

        e.AddListener( EventKeyPress, KeyPressCallback );
        e.AddListener( EventKeyRelease, KeyReleaseCallback );

        while ( mRunning ) {

            while ( !glfwWindowShouldClose( mWindow->GetHandle() ) ) {
                glfwPollEvents();
            }
            mRunning = false;
        }
    }

    std::string Application::GetName() { return this->mName; }
} // namespace Psion
