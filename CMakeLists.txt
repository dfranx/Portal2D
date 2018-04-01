cmake_minimum_required(VERSION 2.6)

project(Portal2D)

set(EXECUTABLE_NAME "Portal2D")
add_executable(${EXECUTABLE_NAME}
	main.cpp
	Level.cpp
	LevelBuilder.cpp
	LevelRenderer.cpp
	Player.cpp
	Ray.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
