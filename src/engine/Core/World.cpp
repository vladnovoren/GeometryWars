#include "World.hpp"

#include <cstring>

using namespace engine;

World::World(std::unique_ptr<IGameObjectsManager> game_object_manager)
    : game_object_manager_(std::move(game_object_manager)) {
}

void World::Update(float dt) {
  for (auto& system_p : systems_) {
    system_p->Update(dt);
  }
}

void World::Render() {
  memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(buffer[0][0]));
  for (const auto& layer : game_object_manager_->GetLayersManager().Layers()) {
    for (const auto& game_object : layer) {
      game_object->Render();
    }
  }
}
