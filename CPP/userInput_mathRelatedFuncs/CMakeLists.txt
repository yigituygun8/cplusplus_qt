cmake_minimum_required(VERSION 3.16)

project(userInput_mathRelatedFuncs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(userInput_mathRelatedFuncs main.cpp)

include(GNUInstallDirs)
install(TARGETS userInput_mathRelatedFuncs
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
