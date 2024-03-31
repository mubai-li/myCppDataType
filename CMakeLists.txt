cmake_minimum_required(VERSION 3.24)

# 定义 MYAPP_NAME 变量 这个是项目名字
set(MYAPP_NAME mycppDataType)

project(${MYAPP_NAME})

set(CMAKE_CXX_STANDARD 17)

# 添加QT
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${MYAPP_NAME} main.cpp)

target_link_libraries(${MYAPP_NAME} PRIVATE Qt5::Widgets)

# 添加第三方库
find_package(Boost REQUIRED)
target_link_libraries(${MYAPP_NAME} PRIVATE Boost::boost)

# 添加tool目标
add_library(tool OBJECT "ValueLibrary/tool/tool.cpp")
target_link_libraries(${MYAPP_NAME} PRIVATE tool)

# 添加StringValue目标
add_library(stringValue OBJECT "ValueLibrary/StringValue.cpp")
target_link_libraries(${MYAPP_NAME} PRIVATE stringValue)

# 添加FloatValue目标
add_library(floatValue OBJECT "ValueLibrary/FloatValue.cpp")
target_link_libraries(${MYAPP_NAME} PRIVATE floatValue)

# 添加IntValue目标
add_library(intValue OBJECT "ValueLibrary/IntValue.cpp")
target_link_libraries(${MYAPP_NAME} PRIVATE intValue)


# 添加ListValue目标
add_library(listValue OBJECT "ValueLibrary/ListValue.cpp")
target_link_libraries(${MYAPP_NAME} PRIVATE listValue)

# 添加DictValue目标
add_library(dictValue OBJECT "ValueLibrary/DictValue.cpp")
target_link_libraries(${MYAPP_NAME} PRIVATE dictValue)

# 添加CharValue目标
add_library(charValue OBJECT "ValueLibrary/CharValue.cpp")
target_link_libraries(${MYAPP_NAME} PRIVATE charValue)

# 添加Value目标
add_library(value OBJECT "ValueLibrary/Value.cpp")
target_link_libraries(${MYAPP_NAME} PRIVATE value)
