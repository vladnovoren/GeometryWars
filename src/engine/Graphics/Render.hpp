#pragma once

#include "Color.hpp"
#include "Engine.h"
#include "Primitives.hpp"

void RenderRect(const Vector2i& position, const IntRect& rect,
                const ColorBGRA& color);

void RenderCircle(const Vector2i& position, const IntCircle& circle,
                  const ColorBGRA& color);
