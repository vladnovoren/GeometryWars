#pragma once

#include <vector>

#include "Primitives.hpp"

namespace engine::phys {
bool CirclesCollide(const FloatCircle& c1, const FloatCircle& c2);

class CirclesCollider {
 public:
  CirclesCollider() = default;

  explicit CirclesCollider(std::vector<FloatCircle> circles);

  [[nodiscard]] bool Collide(const Vector2f& my_pos,
                             const CirclesCollider& other,
                             const Vector2f& other_pos);

 private:
  std::vector<FloatCircle> circles_;
};
}  // namespace engine::phys