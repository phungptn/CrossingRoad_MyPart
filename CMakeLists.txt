cmake_minimum_required(VERSION 3.21)

include(FetchContent)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY      https://github.com/SFML/SFML.git
    GIT_TAG             2.5.1
)

set(BUILD_SHARED_LIBS ON)

set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_DOC OFF)

set(SFML_BUILD_NETWORK OFF)

set(SFML_BUILD_AUDIO ON)
set(SFML_BUILD_GRAPHICS ON)
set(SFML_BUILD_WINDOW ON)

FetchContent_MakeAvailable(sfml)

project(cs202 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(src)

add_custom_target(assets ALL
    COMMAND 
    ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:road>/assets
)
