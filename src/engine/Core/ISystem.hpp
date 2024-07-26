#pragma once

namespace engine {
class ISystem {
 public:
  virtual ~ISystem() = 0;

  virtual void Update(float dt) = 0;
};
}  // namespace engine
