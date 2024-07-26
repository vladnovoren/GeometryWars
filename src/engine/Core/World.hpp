#pragma once

#include <memory>
#include <vector>

#include "Engine.h"
#include "GameObject.hpp"
#include "IGameObjectsManager.hpp"
#include "ISystem.hpp"

namespace engine {
class World {
 public:
  explicit World(std::unique_ptr<IGameObjectsManager> game_object_manager);

  void Update(float dt);

  void Render();

  template <typename... ArgsT>
  void AddSystem(ArgsT&&... args) {
    systems_.emplace_back(std::forward<ArgsT>(args)...);
  }

 private:
  std::unique_ptr<IGameObjectsManager> game_object_manager_;
  std::vector<std::unique_ptr<ISystem>> systems_;
};
}  // namespace engine