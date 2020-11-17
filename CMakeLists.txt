cmake_minimum_required (VERSION 3.3)

project(spacewar)
set (CMAKE_CXX_STANDARD 17)

# The game - hope you enjoy!
add_executable(spacewar src/main.cpp)

# To make things portable as possible, we'll compile SFML
set(SFML_DIR src/3rdparty/SFML)
set(SFML_STATIC_LIBRARIES TRUE)
set(BUILD_SHARED_LIBS FALSE)

add_subdirectory(${SFML_DIR})
target_include_directories(spacewar PRIVATE ${SFML_DIR}/include)
target_link_libraries(
    spacewar
    sfml-system
    sfml-audio
    sfml-window
    sfml-graphics)

