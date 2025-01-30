cmake_minimum_required(VERSION 3.10)
project(examples)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (WIN32)
    message(FATAL_ERROR "Windows is not supported. You may consider installing a virtual linux environment such as Linux Mint or Ubuntu through Virtualbox.")
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)
set(NFO_INC_DIR "../include")
set(NFO_LIB_DIR "../lib")

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.4)
    message(FATAL_ERROR "GCC (g++) version must be at least 9.4")
endif()

find_package(Eigen3 3.4 QUIET NO_MODULE)
if (Eigen3_FOUND)
else ()
    message(FATAL_ERROR "Eigen 3.4 cannot be found. Go to: https://gitlab.com/libeigen/eigen/-/releases, download the Eigen 3.4 source code, and follow the 2nd Method inside the 'INSTALL' file.")
endif()

include_directories(${EIGEN_INCLUDE_DIR})
include_directories(${NFO_INC_DIR})
link_directories(${NFO_LIB_DIR})
link_libraries(NFO)
add_compile_options(-DNDEBUG -O3)

add_executable(basic basic.cpp)
add_executable(rosenbrock rosenbrock.cpp)
add_executable(hs071 hs071.cpp)
add_executable(arm arm.cpp)
