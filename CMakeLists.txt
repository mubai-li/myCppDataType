cmake_minimum_required(VERSION 3.24)

# 定义 MYAPP_NAME 变量 这个是项目名字
set(MYAPP_NAME mycppDataType)
set(MY_LIBRARY ValueType)

project(${MYAPP_NAME})

set(CMAKE_CXX_STANDARD 17)

# 添加QT

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


add_library(${MY_LIBRARY} SHARED ValueLibrary/Value.cpp)
#set_target_properties(${MY_LIBRARY} PROPERTIES WIN32_EXECUTABLE TRUE)

add_executable(${MYAPP_NAME} main.cpp)

find_package(Qt5 COMPONENTS Widgets REQUIRED)


# 添加第三方库
find_package(Boost REQUIRED)

# 添加tool目标
add_library(tool OBJECT "ValueLibrary/tool/tool.cpp")

# 添加StringValue目标
add_library(stringValue OBJECT "ValueLibrary/StringValue.cpp")

# 添加FloatValue目标
add_library(floatValue OBJECT "ValueLibrary/FloatValue.cpp")

# 添加IntValue目标
add_library(intValue OBJECT "ValueLibrary/IntValue.cpp")


# 添加ListValue目标
add_library(listValue OBJECT "ValueLibrary/ListValue.cpp")

# 添加DictValue目标
add_library(dictValue OBJECT "ValueLibrary/DictValue.cpp")

# 添加CharValue目标
add_library(charValue OBJECT "ValueLibrary/CharValue.cpp")

# 添加Value目标
add_library(value OBJECT "ValueLibrary/Value.cpp")



target_link_libraries(${MY_LIBRARY} PRIVATE tool stringValue floatValue intValue listValue dictValue charValue)
target_link_libraries(${MYAPP_NAME} PRIVATE Qt5::Widgets Boost::boost ${MY_LIBRARY})