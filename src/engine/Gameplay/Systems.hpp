#pragma once

#include "Components.hpp"
#include "ECS/ECS.hpp"

class PhysicsSystem : public ISystem {
 public:
  ~PhysicsSystem() override = default;

  void Update(World& world, float dt) override;
};

class RenderSystem : public ISystem {
 public:
  ~RenderSystem() override = default;

  void Update(World& world, float dt) override;

 private:
  static void RenderRects(World& world);

  static void RenderCircles(World& world);

  static void Clear();
};