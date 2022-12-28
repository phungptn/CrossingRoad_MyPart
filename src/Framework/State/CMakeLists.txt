target_sources(LIB PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/state.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/manager.cpp"
)

target_include_directories(LIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
