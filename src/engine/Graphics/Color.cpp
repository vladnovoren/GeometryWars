#include "Color.hpp"

using namespace engine::graphics;

ColorBGRA::ColorBGRA(const ColorCompT b, const ColorCompT g, const ColorCompT r,
                     const ColorCompT a)
    : b(b), g(g), r(r), a(a) {
}

ColorT ColorBGRA::GetUIntColor() const {
  ColorCompT color[4] = {b, g, r, a};
  return *reinterpret_cast<ColorT*>(color);
}

int ColorBGRA::GetIntColor() const {
  ColorCompT color[4] = {b, g, r, a};
  return *reinterpret_cast<int*>(color);
}
