cmake_minimum_required(VERSION 3.16)

project(tic-tac-toe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tic-tac-toe main.cpp)

include(GNUInstallDirs)
install(TARGETS tic-tac-toe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
