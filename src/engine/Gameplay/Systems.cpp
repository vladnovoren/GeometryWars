#include "Systems.hpp"

#include "Graphics/Render.hpp"
#include <cstring>

void PhysicsSystem::Update(World& world, float dt) {
  auto ents = world.Filter<Position, Velocity>();
  for (auto& ent : ents) {
    auto& pos = world.GetComponent<Position>(ent);
    const auto& vel = world.GetComponent<Velocity>(ent);

    pos.value += +dt * vel.value;
  }
}

void RenderSystem::Update(World& world, float) {
  Clear();
  RenderRects(world);
  RenderCircles(world);
}

void RenderSystem::RenderRects(World& world) {
  auto ents = world.Filter<Position, RectShape, Color>();
  for (const auto& ent : ents) {
    const auto& pos = world.GetComponent<Position>(ent).value;
    const auto& rect = world.GetComponent<RectShape>(ent).value;
    const auto& color = world.GetComponent<Color>(ent).value;
    RenderRect(pos, rect, color);
  }
}

void RenderSystem::RenderCircles(World& world) {
  auto ents = world.Filter<Position, CircleShape, Color>();
  for (const auto& ent : ents) {
    const auto& pos = world.GetComponent<Position>(ent).value;
    const auto& circle = world.GetComponent<CircleShape>(ent).value;
    const auto& color = world.GetComponent<Color>(ent).value;
    RenderCircle(pos, circle, color);
  }
}

void RenderSystem::Clear() {
  memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
}
