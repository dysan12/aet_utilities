cmake_minimum_required(VERSION 3.9)
project(ConnectionManager)

set(CMAKE_CXX_STANDARD 17)
link_libraries(ws2_32 wsock32)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(TEMPLATE_SERVER Template/server_template.cpp Server/SocketManager.cpp Server/SocketManager.h Exception/InitializationException.h Exception/SocketException.h Exception/Exception.h Client/SocketManager.cpp Client/SocketManager.h)
add_executable(TEMPLATE_CLIENT Template/client_template.cpp Client/SocketManager.cpp ConnectionManager.h)