#pragma once

#include <memory>
#include <vector>

#include "GameObject.hpp"
#include "LayersManager.hpp"

namespace engine {
class IGameObjectsManager {
 public:
  using GameObjectsList = std::vector<std::shared_ptr<GameObject>>;

 public:
  explicit IGameObjectsManager(const std::vector<std::string>& layers);

  [[nodiscard]] const GameObjectsList& GetGameObjects() const;

  virtual void AddGameObject(const std::shared_ptr<GameObject>& game_object,
                             const std::string& layer);

  const LayersManager& GetLayersManager() const;

 private:
  std::vector<std::shared_ptr<GameObject>> game_objects_;
  LayersManager layers_manager_;
};
}  // namespace engine
