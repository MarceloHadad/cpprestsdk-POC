cmake_minimum_required(VERSION 3.20.0)

project(${CMAKE_PROJECT_NAME})

include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_package(cpprestsdk CONFIG REQUIRED)
find_package(hidapi CONFIG REQUIRED)

add_executable(${CMAKE_PROJECT_NAME})

set(SRC_Main
    main.cpp
    pch.cpp
    pch.hpp
)
source_group("\\" FILES ${SRC_Main})

set(SRC_Api
    api.cpp
    api.hpp
)
source_group("Api" FILES ${SRC_Api})

set(SRC_Hid
    hid.hpp
)
source_group("Hid" FILES ${SRC_Hid})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    ${SRC_Main}
    ${SRC_Api}
    ${SRC_Hid}
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE cpprestsdk::cpprest OpenSSL::SSL OpenSSL::Crypto hidapi::libusb)
