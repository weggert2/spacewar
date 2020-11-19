cmake_minimum_required (VERSION 3.3)

project(spacewar)
set (CMAKE_CXX_STANDARD 17)


# Shortcut - get all of the sources. You probably don't want
# to do this in production.
file(GLOB all_srcs src/*.c* src/*.h*)

# Build the game. Hope you enjoy!
add_executable(${PROJECT_NAME} ${all_srcs})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_NAME}/bin)
install(DIRECTORY assets DESTINATION ${PROJECT_NAME})

# TODO: Turn on compile warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall
        -Wextra
        -Werror
        -fPIC>
    $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        /WX>)

# Compile our dependencies

# SFML
set(DEPS_DIR src/3rdparty)
set(SFML_DIR ${DEPS_DIR}/SFML)
set(SFML_STATIC_LIBRARIES TRUE)
set(BUILD_SHARED_LIBS FALSE)

# EntityX
set(ENTITYX_DIR ${DEPS_DIR}/entityx)
set(ENTITYX_BUILD_SHARED 0 CACHE BOOL "Build entityx statically")
set(ENTITYX_BUILD_TESTING 0 CACHE BOOL "Don't build entityx tests")

add_subdirectory(${SFML_DIR}    EXCLUDE_FROM_ALL)
add_subdirectory(${ENTITYX_DIR} EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${ENTITYX_DIR})

target_link_libraries(
    ${PROJECT_NAME}
    sfml-system
    sfml-audio
    sfml-window
    sfml-graphics
    entityx)
