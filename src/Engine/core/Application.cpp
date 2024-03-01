#include "Application.hpp"
#include <string>

namespace Psion {

Application::Application(std::string name) { this->name = name; }

Application &Application::GetInstance(std::string name) {
  static Application instance(name);
  return instance;
}

std::string Application::GetName() { return this->name; }
} // namespace Psion
