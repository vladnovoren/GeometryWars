#pragma once

#include "Collisions.hpp"
#include "MovableObject.hpp"

namespace engine::phys {

class RigidObject : public MovableObject {
 public:
  RigidObject() = default;
  RigidObject(const Vector2f& position, const Vector2f& velocity,
              CirclesCollider collider);

  [[nodiscard]] CirclesCollider GetCollider() const;

  virtual void OnCollide() = 0;

 protected:
  CirclesCollider collider_;
};

}  // namespace engine::phys
