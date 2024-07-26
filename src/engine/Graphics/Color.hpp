#pragma once

#include <cstddef>
#include <cstdint>

namespace engine::graphics {
using ColorCompT = uint8_t;
using ColorT = uint32_t;

struct ColorBGRA {
  ColorCompT b = 0;
  ColorCompT g = 0;
  ColorCompT r = 0;
  ColorCompT a = 0;

  ColorBGRA() = default;

  ColorBGRA(ColorCompT b, ColorCompT g, ColorCompT r, ColorCompT a);

  [[nodiscard]] ColorT GetUIntColor() const;
  [[nodiscard]] int GetIntColor() const;
};
}  // namespace engine::graphics
