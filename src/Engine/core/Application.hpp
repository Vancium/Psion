#pragma once

#include "../Psion.hpp"
#include <string>

namespace Psion {
class PSION_API Application {
public:
  std::string GetName();

  static Application &GetInstance(std::string name);

private:
  Application(std::string name);
  std::string name;
};
} // namespace Psion
