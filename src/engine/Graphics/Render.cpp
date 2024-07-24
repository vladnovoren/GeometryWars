#include "Render.hpp"
#include <cstring>

void RenderRect(const Vector2i& position, const IntRect& rect,
                const ColorBGRA& color) {
  int start_y = position.y + rect.position.y;
  int end_y = start_y + rect.size.y;
  int start_x = position.x + rect.position.x;
  int width = rect.size.x;

  uint32_t int_color = color.GetIntColor();

  for (int y = start_y; y < end_y; ++y) {
    memset(&buffer[y][start_x], int_color, width * sizeof(buffer[0][0]));
  }
}

void RenderCircle(const Vector2i& position, const IntCircle& circle,
                  const ColorBGRA& color) {
  IntCircle corrected_circle(position.x + circle.center.x,
                             position.y + circle.center.y, circle.radius);
  Vector2i r_r_v(corrected_circle.radius, corrected_circle.radius);
  Vector2i left_up = corrected_circle.center - r_r_v;
  Vector2i right_down = corrected_circle.center + r_r_v;

  for (int y = left_up.y; y < right_down.y; ++y) {
    for (int x = left_up.x; x < right_down.x; ++x) {
      if (corrected_circle.IsPointInside(x, y)) {
        buffer[y][x] = color.GetIntColor();
      }
    }
  }
}
