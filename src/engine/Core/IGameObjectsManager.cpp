#include "IGameObjectsManager.hpp"

using namespace engine;

IGameObjectsManager::IGameObjectsManager(const std::vector<std::string>& layers)
    : layers_manager_(layers) {
}

const IGameObjectsManager::GameObjectsList&
IGameObjectsManager::GetGameObjects() const {
  return game_objects_;
}

void IGameObjectsManager::AddGameObject(
    const std::shared_ptr<GameObject>& game_object, const std::string& layer) {
  game_objects_.push_back(game_object);
  layers_manager_.Register(game_object, layer);
}

const LayersManager& IGameObjectsManager::GetLayersManager() const {
  return layers_manager_;
}
