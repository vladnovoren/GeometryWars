#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "GameObject.hpp"

namespace engine {
class LayersManager {
 public:
  explicit LayersManager(const std::vector<std::string>& layers_order);

  void Register(const std::shared_ptr<GameObject>& game_object,
                const std::string& layer);
  void Unregister(const std::shared_ptr<GameObject>& game_object);

  const std::vector<std::unordered_set<std::shared_ptr<GameObject>>>& Layers()
      const;

 private:
  std::unordered_map<std::string, std::size_t> layers_map_;
  std::vector<std::unordered_set<std::shared_ptr<GameObject>>> layers_;
};
}  // namespace engine