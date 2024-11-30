cmake_minimum_required(VERSION 3.10)

project(EasyYYJSON VERSION 1.1.0 LANGUAGES C CXX)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Use standard-compliant C++11

# yyjson release version
set(YYJSON_RELEASE_VER 0.10.0)
# Required yyjson release url
set(YYJSON_RELEASE_URL "https://github.com/ibireme/yyjson/archive/refs/tags/${YYJSON_RELEASE_VER}.zip")
# yyjson download path
set(YYJSON_RELEASE_DIR "${CMAKE_BINARY_DIR}/yyjson")
# Downloaded file name
set(YYJSON_RELEASE_FILE "${YYJSON_RELEASE_DIR}/yyjson.zip")

# Make sure yyjson directory exists
file(MAKE_DIRECTORY ${YYJSON_RELEASE_DIR})

# Download the release
file(DOWNLOAD ${YYJSON_RELEASE_URL} ${YYJSON_RELEASE_FILE} SHOW_PROGRESS)

# Extract the file (if necessary)
execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${YYJSON_RELEASE_FILE} WORKING_DIRECTORY ${YYJSON_RELEASE_DIR})

# Add the library path to the project
include_directories(${YYJSON_RELEASE_DIR}/yyjson-${YYJSON_RELEASE_VER}/src)

message(STATUS "Using C++ standard: ${CMAKE_CXX_STANDARD}")
