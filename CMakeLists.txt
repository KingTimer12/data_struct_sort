cmake_minimum_required(VERSION 3.21)
project(data_struct_sort)

# Set UTF-8 encoding for source files
if(MSVC)
    add_compile_options(/utf-8)
    # Add console encoding options for MSVC
    add_compile_definitions(_UNICODE UNICODE)
else()
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

# Collect all source files from src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h" "src/*.hpp")

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directory
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output encoding for Windows console
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE -D_UNICODE -DUNICODE)
endif()
