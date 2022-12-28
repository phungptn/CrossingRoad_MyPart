target_sources(LIB PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/context.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/identifier.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/utility.cpp"
)

target_include_directories(LIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")