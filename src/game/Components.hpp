#pragma once

#include "Primitives.hpp"
#include "Graphics/Color.hpp"
#include "Collisions.hpp"

struct PlayerTag{};

struct EnemyTag{};

struct Health {
  int value;
};

struct Position {
  Vector2f value;
};

struct Velocity {
  Vector2f value;
};

struct RectShape {
  FloatRect value;
};

struct CircleShape {
  FloatCircle value;
};

struct Color {
  ColorBGRA value;
};
