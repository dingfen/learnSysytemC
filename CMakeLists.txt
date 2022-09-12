# 要求cmake版本最小为 3.4
cmake_minimum_required(VERSION 3.4)

project(learnSystemC)

set(CMAKE_PREFIX_PATH ~/systemc)

# 命名变量
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)

# 控制输出的二进制文件位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${CMAKE_PREFIX_PATH}/include)
find_package(SystemCLanguage CONFIG REQUIRED)
link_directories(${CMAKE_PREFIX_PATH}/lib-linux64)

add_executable(hello hello.cpp)
target_link_libraries(hello SystemC::systemc)

add_executable(sc_module systemcmodule.cpp)
target_link_libraries(sc_module SystemC::systemc)

add_executable(process process.cpp)
target_link_libraries(process SystemC::systemc)

add_executable(stage stage.cpp)
target_link_libraries(stage SystemC::systemc)