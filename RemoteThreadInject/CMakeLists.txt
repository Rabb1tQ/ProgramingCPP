cmake_minimum_required(VERSION 3.26)
project(RemoteThreadInject)

set(CMAKE_CXX_STANDARD 17)

add_executable(RemoteThreadInject
        InjectDll.cpp
        InjectDll.cpp
        AdjustTokenPrivileges.cpp
        CreateRemoteThread_Main.cpp)

if (WIN32)
    target_link_libraries(RemoteThreadInject PRIVATE kernel32.lib)
    link_libraries(RemoteThreadInject PRIVATE kernel32.lib)
endif()