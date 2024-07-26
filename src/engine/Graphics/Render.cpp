#include "Render.hpp"

using namespace engine::graphics;

void RenderRect(const Vector2i& position, const IntRect& rect,
                const ColorBGRA& color) {
  int start_y = position.y + rect.position.y;
  int end_y = start_y + rect.size.y;
  int start_x = position.x + rect.position.x;
  int end_x = start_x + rect.size.x;

  auto int_color = color.GetIntColor();

  for (int y = start_y; y < end_y; ++y) {
    for (int x = start_x; x < end_x; ++x) {
      buffer[y][x] = int_color;
    }
  }
}

void RenderCircle(const IntCircle& circle, const ColorBGRA& color) {
  int radius = circle.radius;
  int cx = circle.center.x;
  int cy = circle.center.y;
  auto int_color = color.GetIntColor();

  int x = radius;
  int y = 0;
  int err = 0;

  while (x >= y) {
    for (int to_x = cx - x; to_x <= cx + x; ++to_x) {
      buffer[cy + y][to_x] = int_color;
    }
    for (int to_x = cx - x; to_x <= cx + x; ++to_x) {
      buffer[cy - y][to_x] = int_color;
    }
    if (y != x) {
      for (int to_x = cx - y; to_x <= cx + y; ++to_x) {
        buffer[cy + x][to_x] = int_color;
      }
      for (int to_x = cx - y; to_x <= cx + y; ++to_x) {
        buffer[cy - x][to_x] = int_color;
      }
    }

    if (err <= 0) {
      y += 1;
      err += 2 * y + 1;
    }

    if (err > 0) {
      x -= 1;
      err -= 2 * x + 1;
    }
  }
}
