#pragma once

#include <functional>
#include <memory>

#include "Core/GameObject.hpp"
#include "Core/ISystem.hpp"
#include "RigidBody.hpp"

namespace engine::phys {
class PhysicsSystem : public ISystem {
 public:
  struct GameObjectRecord {
    std::shared_ptr<GameObject> game_object;
    RigidBody rigid_body;
  };

 public:
  ~PhysicsSystem() override = default;

  void RegisterGameObject(const std::shared_ptr<GameObject>& game_object,
                          RigidBody rigid_body);

  void Update(float dt) override;

 private:
  std::vector<GameObjectRecord> records_;
};
}  // namespace engine::phys
