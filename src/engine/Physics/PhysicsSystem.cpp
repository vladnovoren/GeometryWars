#include "PhysicsSystem.hpp"

using namespace engine::phys;

void PhysicsSystem::RegisterGameObject(
    const std::shared_ptr<GameObject>& game_object,
    RigidBody rigid_body) {
  records_.emplace_back(game_object, std::move(rigid_body));
}

void PhysicsSystem::Update(float dt) {

}