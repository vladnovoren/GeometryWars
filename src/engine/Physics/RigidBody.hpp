#pragma once

#include "Collisions.hpp"
#include "Primitives.hpp"

namespace engine::phys {
struct RigidBody {
  Vector2f position;
  Vector2f velocity;
  CirclesCollider collider;
};
}  // namespace engine::phys
