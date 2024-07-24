
# You are free to modify this file

cmake_minimum_required(VERSION 3.0)
project(game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

find_package(X11 REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(${X11_INCLUDE_DIR})

set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

include_directories(src/engine)

add_library(engine STATIC)
target_sources(engine PRIVATE
        src/engine/Engine.cpp
        src/engine/Graphics/Render.cpp
        src/engine/Graphics/Color.cpp

        src/engine/ECS/Component/IComponentBucket.cpp
        src/engine/ECS/System/System.cpp
        src/engine/ECS/World.cpp
)

add_executable(game)
target_sources(game PRIVATE
        src/engine/Gameplay/Systems.cpp

        src/Game.cpp
)

target_link_libraries(engine m ${X11_LIBRARIES} sfml-graphics)
target_link_libraries(game engine)
