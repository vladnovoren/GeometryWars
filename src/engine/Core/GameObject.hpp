#pragma once

namespace engine {
class GameObject {
 public:
  virtual ~GameObject() = 0;

  virtual void Update(float dt) = 0;

  virtual void Render() = 0;
};
}  // namespace engine