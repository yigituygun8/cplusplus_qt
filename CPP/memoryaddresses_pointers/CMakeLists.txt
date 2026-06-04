cmake_minimum_required(VERSION 3.16)

project(memoryaddresses_pointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(memoryaddresses_pointers main.cpp)

include(GNUInstallDirs)
install(TARGETS memoryaddresses_pointers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
