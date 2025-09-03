cmake_minimum_required(VERSION 3.10)
project(SFMLExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML")
set(PROJECT_NAME platformer)

file(GLOB source_files
"src/*.cpp")
message(STATUS "Source files: ${source_files}")

set(SOURCES ${source_files})
# Add SFML include and lib directories
include_directories("${SFML_ROOT}/include")
link_directories("${SFML_ROOT}/lib")

add_executable(play ${SOURCES})
target_include_directories(play PRIVATE "${CMAKE_SOURCE_DIR}/include")
set_target_properties(play PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output"
)

target_link_libraries(play sfml-graphics sfml-window sfml-system sfml-audio)

