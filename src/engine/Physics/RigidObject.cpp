#include "RigidObject.hpp"

namespace engine::phys {
RigidObject::RigidObject(const Vector2f& position, const Vector2f& velocity,
                         CirclesCollider collider)
    : MovableObject(position, velocity), collider_(std::move(collider)) {
}

CirclesCollider RigidObject::GetCollider() const {
  return collider_;
}
}  // namespace engine::phys
