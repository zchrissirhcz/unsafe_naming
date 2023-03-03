cmake_minimum_required(VERSION 3.20)
project(x)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    # C:\Program Files (x86)\IntelSWTools\system_studio_2020\OpenCL\sdk\include\CL
    find_package(OpenCL REQUIRED)

    add_executable(testbed testbed.cpp)
    target_link_libraries(testbed PUBLIC
        OpenCL::OpenCL
    )
else()
    message(FATAL_ERROR "only occurs on Windows")
endif()