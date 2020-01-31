cmake_minimum_required(VERSION 3.12.3)
project(Rain_Engine)

find_package(OpenGL REQUIRED)

if(CMAKE_SOURCE_DIR MATCHES " ")
    message("Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause.")
endif()
if(CMAKE_BINARY_DIR MATCHES " ")
    message("Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause.")
endif()

include_directories(
        external/glm
        external/glew
        external/glfw
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW
)

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rain_Engine src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})