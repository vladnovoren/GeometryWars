#pragma once

#include "Primitives.hpp"
#include "Graphics/Color.hpp"

struct PlayerTag{};

struct EnemyTag{};

struct Health {
  int value;
};

struct Position {
  Vector2i value;
};

struct Velocity {
  Vector2i value;
};

struct RectShape {
  IntRect value;
};

struct CircleShape {
  IntCircle value;
};

struct Color {
  ColorBGRA value;
};