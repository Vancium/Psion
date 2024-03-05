#include "EventManager.hpp"
#include "EventListener.hpp"
#include "../Logger/Logger.hpp"
#include <strings.h>
#include <vector>

namespace Psion {

    EventManager &EventManager::GetInstance() {
        static EventManager instance;
        return instance;
    }

    EventManager::EventManager() {
        mAllEventListeners = new std::vector<std::vector<EventListener *>>();

        for ( int iter = 0; iter != iter_end; iter++ ) {
            std::vector<EventListener *> *newListenerGroup =
                new std::vector<EventListener *>();
            mAllEventListeners->push_back( *newListenerGroup );
        }
        PS_INFO( "Event manager created" );
    }
    EventManager::~EventManager() {
        delete mAllEventListeners;
        PS_INFO( "Event manager destroyed" );
    }

    EventListener *EventManager::AddListener( EventType type,
                                              EventListener *listener ) {
        int index = static_cast<int>( type );

        std::vector<EventListener *> *eventGroup =
            &mAllEventListeners->at( index );

        eventGroup->push_back( listener );
        return listener;
    }

    EventListener *
    EventManager::AddListener( EventType eEventType,
                               std::function<void( void * )> pfnCallback ) {
        // Get the relevant index in the list of event types
        int iIndex = static_cast<int>( eEventType );

        // Get the relevant list with that index
        std::vector<EventListener *> *listOfListeners =
            &mAllEventListeners->at( iIndex );

        // Create new event listener
        EventListener *aNewListener =
            new EventListener( pfnCallback, eEventType );

        // Add the new listener into that list
        listOfListeners->push_back( aNewListener );

        // Return the listener
        return aNewListener;
    }

    void EventManager::RemoveListener( EventType eEventType,
                                       EventListener *pListener ) {
        // Get the relevant index in the list of event types
        int iIndex = static_cast<int>( eEventType );

        // Get the relevant list with that index
        std::vector<EventListener *> *listOfListeners =
            &mAllEventListeners->at( iIndex );

        // Search that list
        for ( unsigned i = 0; i < listOfListeners->size(); i++ ) {
            // Delete the listener
            if ( listOfListeners->at( i ) == pListener ) {
                listOfListeners->erase( listOfListeners->begin() + i );
                break;
            }
        }
    }
    void EventManager::RemoveAllListeners( EventType eEventType ) {
        // Get the relevant index in the list of event types
        int iIndex = static_cast<int>( eEventType );

        // Get the relevant list with that index
        std::vector<EventListener *> *listOfListeners =
            &mAllEventListeners->at( iIndex );

        // Delete contents of the array of listeners
        listOfListeners->clear();
    }

    // Tells event manager to trigger events of a given type
    void EventManager::Trigger( EventType eEventType, void *pData ) {
        // Get the relevant index in the list of event types
        int iIndex = static_cast<int>( eEventType );

        // Get list of listeners to trigger
        std::vector<EventListener *> *aListOfListeners =
            &mAllEventListeners->at( iIndex );

        // Trigger all listeners for that event
        //

        for ( auto eventListener : *aListOfListeners ) {
            eventListener->Trigger( pData );
        }
    }
} // namespace Psion
//
