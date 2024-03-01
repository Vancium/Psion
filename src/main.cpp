#include "Engine/core/Application.hpp"
#include <iostream>

int main(void) {
  Psion::Application app = Psion::Application::GetInstance("Engine");

  std::cout << app.GetName() << std::endl;
}
