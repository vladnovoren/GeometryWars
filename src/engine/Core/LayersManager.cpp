#include "LayersManager.hpp"

using namespace engine;

LayersManager::LayersManager(const std::vector<std::string>& layers_order) {
  layers_.resize(layers_order.size());
  for (std::size_t i = 0; i < layers_order.size(); ++i) {
    layers_map_[layers_order[i]] = i;
  }
}

void LayersManager::Register(const std::shared_ptr<GameObject>& game_object,
                             const std::string& layer) {
  layers_[layers_map_[layer]].emplace(game_object);
}

void LayersManager::Unregister(const std::shared_ptr<GameObject>& game_object) {
  for (auto& layer : layers_) {
    if (layer.contains(game_object)) {
      layer.erase(game_object);
    }
  }
}

const std::vector<std::unordered_set<std::shared_ptr<GameObject>>>&
LayersManager::Layers() const {
  return layers_;
}