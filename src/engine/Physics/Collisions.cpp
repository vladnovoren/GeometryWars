#include "Collisions.hpp"

using namespace engine::phys;

bool CirclesCollide(const FloatCircle& c1, const FloatCircle& c2) {
  return (c1.center - c2.center).LengthSqr() <
         std::pow(c1.radius + c2.radius, 2);
}

CirclesCollider::CirclesCollider(std::vector<FloatCircle> circles)
    : circles_(std::move(circles)) {
}

bool CirclesCollider::Collide(const Vector2f& my_pos,
                              const CirclesCollider& other,
                              const Vector2f& other_pos) {
  auto get_global_circles = [](const std::vector<FloatCircle>& circles,
                               const Vector2f& pos) {
    std::vector<FloatCircle> res = circles;
    for (auto& circle : res) {
      circle.center += pos;
    }
    return res;
  };

  auto circles_1 = get_global_circles(circles_, my_pos);
  auto circles_2 = get_global_circles(other.circles_, other_pos);

  for (const auto& circle_1 : circles_1) {
    for (const auto& circle_2 : circles_2) {
      if (CirclesCollide(circle_1, circle_2)) {
        return true;
      }
    }
  }

  return false;
}
