cmake_minimum_required(VERSION 3.14)
project(fridge-gen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Threads REQUIRED)

# Include FetchContent module
include(FetchContent)

# Fetch cpp-httplib
FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG v0.14.3
)
FetchContent_MakeAvailable(httplib)

# Create executable
add_executable(fridge-gen src/main.cpp src/server/server.cpp)

# Link libraries
target_link_libraries(fridge-gen PRIVATE httplib::httplib Threads::Threads)