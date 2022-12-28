target_sources(LIB PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/loading.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/menu.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/pause.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/playing.cpp"
)

target_include_directories(LIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")