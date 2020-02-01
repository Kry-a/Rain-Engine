cmake_minimum_required(VERSION 3.12.3)
project(Rain_Engine)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

if(CMAKE_SOURCE_DIR MATCHES " ")
    message("Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause.")
endif()
if(CMAKE_BINARY_DIR MATCHES " ")
    message("Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause.")
endif()

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(UNIX AND APPLE)
    set(MACOS TRUE)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(external/glfw)
#add_subdirectory(external/glew-cmake)

include_directories(
        external/glm
        external/glfw/include
        ${GLEW_INCLUDE_DIRS}
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        glfw
        ${GLFW_LIBRARIES}
        ${GLEW_LIBRARIES}
)

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rain_Engine src/main.cpp src/engine/glfw_utils.hpp src/engine/GameObject.hpp src/engine/GameObject.cpp src/engine/GameScript.hpp src/engine/GameScript.cpp src/scripts/test_script.cpp src/scripts/test_script.hpp src/engine/Level.cpp src/engine/Level.hpp)
target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})