#pragma once

/*
 *
 *
 *
 */

#include <functional>
namespace Psion {
    enum EventType {
        EventKeyPress,
        EventKeyRelease,
        EventWindowResize,
        EventWindowClose,
        iter_end
    };

    class EventListener {
      private:
        std::function<void( void * )> mEventCallback;
        EventType mEventType;

      public:
        EventListener();
        EventListener( std::function<void( void * )> eventCallback,
                       EventType eventType );
        ~EventListener();

        // Runs event callback
        void Trigger( void *eventData );

        inline void SetEventType( EventType type ) {
            if ( !mEventType ) {
                mEventType = type;
            }
        }

        inline EventType GetType() { return mEventType; }

        inline void SetCallback( std::function<void( void * )> callback ) {
            mEventCallback = callback;
        }

        inline std::function<void( void * )> GetCallback() {
            return mEventCallback;
        }
    };
} // namespace Psion
