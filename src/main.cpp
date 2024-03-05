#include "Engine/core/Application/Application.hpp"
#include "Engine/core/Logger/Logger.hpp"

using namespace Psion;

int main( void ) {
    Logger::Initialize();
    Application &a = Application::GetInstance( "Psion Engine", 1280, 720 );
    a.Run();
}
