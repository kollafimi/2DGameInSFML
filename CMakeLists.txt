cmake_minimum_required(VERSION 3.12)

project(2DGameInSFML)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
	src/main.cpp
	src/Game.cpp
	src/Player.cpp
	src/Enemy.cpp
	src/Map.cpp
	src/ResourceManager.cpp)

set(HEADERS
	include/Game.h
	include/Player.h
	include/Enemy.h
	include/Map.h
	include/ResourceManager.h)

set(SFML_DIR "D:/C++/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

add_executable(2DGameInSFML ${SOURCES} ${HEADERS})

target_link_libraries(2DGameInSFML sfml-graphics sfml-window sfml-system sfml-audio)

target_include_directories(2DGameInSFML PRIVATE include)

set_property(TARGET 2DGameInSFML PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
