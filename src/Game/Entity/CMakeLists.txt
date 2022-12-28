target_sources(LIB PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/object.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/animal.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/animal.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/vehicle.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/vehicle.hpp"
)

target_include_directories(LIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")