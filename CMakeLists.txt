cmake_minimum_required(VERSION 3.1)



project(Portal2D)



find_package(SFML 2.5 COMPONENTS graphics REQUIRED)


add_executable(Portal2D main.cpp Level.cpp LevelBuilder.cpp LevelRenderer.cpp Player.cpp Ray.cpp)

target_link_libraries(Portal2D sfml-graphics)