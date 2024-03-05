#pragma once

#include "EventListener.hpp"
#include <vector>
namespace Psion {

    class EventManager {
      private:
        std::vector<std::vector<EventListener *>> *mAllEventListeners;

        EventManager();

      public:
        static EventManager &GetInstance();
        ~EventManager();
        EventListener *
        AddListener( EventType eventType,
                     std::function<void( void * )> eventCallback );
        EventListener *AddListener( EventType eventType,
                                    EventListener *listener );

        // Removes listener for a given event
        void RemoveListener( EventType eventType, EventListener *listener );

        // Removes listeners for all events
        void RemoveAllListeners( EventType eventType );

        // Triggers events of given type
        void Trigger( EventType eventType, void *data );
    };
} // namespace Psion
