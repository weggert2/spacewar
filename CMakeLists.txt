cmake_minimum_required (VERSION 3.3)

project(spacewar)
set (CMAKE_CXX_STANDARD 17)

# Shortcut - get all of the sources. You probably don't want
# to do this in production.
file(
    GLOB all_srcs
    src/main.cpp
    src/core/*.c*       src/core/*.h*
    src/components/*.c* src/components/*.h*
    src/systems/*.c*    src/systems/*.h*
)

# Build the game. Hope you enjoy!
add_executable(${PROJECT_NAME} ${all_srcs})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_NAME}/bin)
install(DIRECTORY assets DESTINATION ${PROJECT_NAME})

# Turn on compile warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall
        -Wextra
        -Werror
        -Wdouble-promotion
        -Wshadow
        -Wformat=2
        -Wno-narrowing
        -fPIC
        >
    $<$<CXX_COMPILER_ID:MSVC>:
        /W3
        /WX
        >
)

# target_compile_options(${PROJECT_NAME} PRIVATE
#     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
#         >
#     $<$<CXX_COMPILER_ID:MSVC>:
#         _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS=1
#         >
# )

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

# Json
set(JSON_DIR ${DEPS_DIR}/nlohmann_json)

# Windows compatibility for EntityX
set_directory_properties(
    PROPERTIES COMPILE_DEFINITIONS
    _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS=1)

add_subdirectory(${SFML_DIR}    EXCLUDE_FROM_ALL)
add_subdirectory(${ENTITYX_DIR} EXCLUDE_FROM_ALL)
add_subdirectory(${JSON_DIR}    EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${SFML_DIR}/include)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${ENTITYX_DIR})
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${JSON_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE src src/core)

target_link_libraries(
    ${PROJECT_NAME}
    sfml-system
    sfml-audio
    sfml-window
    sfml-graphics
    entityx
    nlohmann_json)
