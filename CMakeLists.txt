cmake_minimum_required (VERSION 2.6)
include_directories ("include")
include_directories ("pugixml")
include_directories ("skyelib")
add_subdirectory(pugixml)
add_subdirectory(skyelib)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic -lncurses")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

find_package( OpenCV REQUIRED )

project (yapp)
add_executable(yapp src/yapp.cpp src/episode.cpp src/podcast.cpp src/ui.cpp src/player.cpp)
target_link_libraries(yapp ncurses ${OpenCV_LIBS} pugixml skyelib)

