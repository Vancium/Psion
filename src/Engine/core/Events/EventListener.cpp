#include "EventListener.hpp"

namespace Psion {
    EventListener::EventListener() {}
    EventListener::EventListener( std::function<void( void * )> eventCallback,
                                  EventType eventType )
        : mEventCallback( eventCallback ), mEventType( eventType ) {}

    EventListener::~EventListener() {}

    void EventListener::Trigger( void *data ) {
        if ( mEventCallback ) {
            mEventCallback( data );
        }
    }
} // namespace Psion
