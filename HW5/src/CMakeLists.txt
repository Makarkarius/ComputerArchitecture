# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(HW4 LANGUAGES CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Source files list
set(SOURCE_FILES
        # Headers
        hotel.h
        visitor.h

        # Sources
        hotel.cpp
        visitor.cpp
        main.cpp
        )

add_executable(HW5 ${SOURCE_FILES})
target_link_libraries(HW5 PRIVATE Threads::Threads)