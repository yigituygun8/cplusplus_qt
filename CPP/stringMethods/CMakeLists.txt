cmake_minimum_required(VERSION 3.16)

project(stringMethods LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stringMethods main.cpp)

include(GNUInstallDirs)
install(TARGETS stringMethods
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
