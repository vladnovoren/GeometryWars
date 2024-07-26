
# You are free to modify this file

cmake_minimum_required(VERSION 3.0)
project(game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})

set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

include_directories(src/engine)
add_subdirectory(sigslot)

add_library(engine STATIC
        src/engine/Core/World.cpp
        src/engine/Core/ISystem.cpp
        src/engine/Core/ISystem.cpp
        src/engine/Core/IGameObjectsManager.cpp
        src/engine/Core/LayersManager.cpp
        src/engine/Physics/PhysicsSystem.cpp
        src/engine/Physics/Collisions.cpp
        src/engine/Physics/RigidBody.cpp
        src/engine/Physics/MovableObject.cpp
        src/engine/Physics/RigidObject.cpp
)

target_sources(engine PRIVATE
        src/engine/Engine.cpp
        src/engine/Graphics/Render.cpp
        src/engine/Graphics/Color.cpp

        src/engine/Core/GameObject.cpp
)

add_executable(game
        src/game/GameObjectManager.cpp)

target_sources(game PRIVATE
        src/Game.cpp
)

target_compile_options(game PRIVATE
        -g
        -fsanitize=address
)

target_link_options(game PRIVATE
        -g
        -fsanitize=address
)

target_link_libraries(engine m ${X11_LIBRARIES} Pal::Sigslot)
target_link_libraries(game engine)
