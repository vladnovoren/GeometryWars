#include "Engine.h"
#include <stdlib.h>
#include <iostream>
#include <memory.h>
#include <cassert>
#include <cstdint>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Gameplay/Systems.hpp"

#include <stdio.h>

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, VK_RETURN)
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  schedule_quit_game() - quit game after act()

World world;

// initialize game data in this function
void initialize()
{
  world.AddSystem<PhysicsSystem>();
  world.AddSystem<RenderSystem>();

  auto player_ent = world.CreateEntity();
  world.SetComponent(player_ent, PlayerTag{});
  world.SetComponent(player_ent, Position{Vector2i(100, 100)});
//  world.SetComponent(player_ent, CircleShape{IntCircle(0, 0, 20)});
  world.SetComponent(player_ent, RectShape{IntRect(-10, -10, 20, 20)});
  world.SetComponent(player_ent, Color{ColorBGRA(255, 0, 0, 255)});
  world.SetComponent(player_ent, Velocity{Vector2i(150, 0)});
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();
  world.Update(dt);
}

sf::Color blendColors(const sf::Color& src, const sf::Color& dst) {
  float srcAlpha = src.a / 255.0f;
  float dstAlpha = dst.a / 255.0f;
  float outAlpha = srcAlpha + dstAlpha * (1 - srcAlpha);

  if (outAlpha == 0) {
      return sf::Color(0, 0, 0, 0);
  }

  sf::Uint8 r = static_cast<sf::Uint8>((src.r * srcAlpha + dst.r * dstAlpha * (1 - srcAlpha)) / outAlpha);
  sf::Uint8 g = static_cast<sf::Uint8>((src.g * srcAlpha + dst.g * dstAlpha * (1 - srcAlpha)) / outAlpha);
  sf::Uint8 b = static_cast<sf::Uint8>((src.b * srcAlpha + dst.b * dstAlpha * (1 - srcAlpha)) / outAlpha);
  sf::Uint8 a = static_cast<sf::Uint8>(outAlpha * 255);

  return sf::Color(r, g, b, a);
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
  // clear backbuffer
//  memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
}

// free game data in this function
void finalize()
{
}

