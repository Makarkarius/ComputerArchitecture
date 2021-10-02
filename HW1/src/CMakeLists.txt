cmake_minimum_required(VERSION 3.0)
project(HW1)

set(CMAKE_CXX_STANDARD 17)

# Source files list
set(SOURCE_FILES
        # Headers
        rnd.h
        constant.h
        flower.h
        shrub.h
        tree.h
        plant.h
        container.h

        # Sources
        flower.cpp
        shrub.cpp
        tree.cpp
        plant.cpp
        container.cpp
        main.cpp
)

add_executable(HW1 ${SOURCE_FILES})