﻿# myCppDataType
# myCppDataType

项目目的，用来对c++需要返回复杂类型的声明，减少开发中需要书写过多的代码，并且在对python开放中也可以很好的使用

这个项目是模仿python的数据类型来进行处理数据，参考了pyside6中QVarit的代码书写成的

里面定义的很多类似于python的方法

数据的声明

```cpp
// 原来的类型声明
// c++字符串
std::string a = "123";
// 自己的类型声明
value a = "123";
// c++ int
int a = 1;
Value a = 1;
// 其他的基础也是如此
// 容器类型
Value a = {1,2,"sdf"};

// 字典类型
Value c = DictValue();

c.changeOrSetDefault("123",a);
c.setDefault("123",a);

```

