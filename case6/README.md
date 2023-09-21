
## 报错信息

```
MSBuild version 17.6.3+07e294721 for .NET Framework

  main.cpp
D:\github\unsafe_naming\case6\main.cpp(6,64): warning C4003: 类函数宏的调用“max”参数不足 [D:\github\unsafe_naming\case6\build\testbed.vcxproj]
D:\github\unsafe_naming\case6\main.cpp(6,64): error C2589: “(”:“::”右边的非法标记 [D:\github\unsafe_naming\case6\build\testbed.vcxproj]
D:\github\unsafe_naming\case6\main.cpp(6,64): error C2062: 意外的类型“unknown-type” [D:\github\unsafe_naming\case6\build\testbed.vcxproj]
D:\github\unsafe_naming\case6\main.cpp(6,64): error C2059: 语法错误:“)” [D:\github\unsafe_naming\case6\build\testbed.vcxproj]
```

## 原因

Windows.h 引入了 min, max 宏, 导致再使用 `std::numeric_limits<unsigned int>::max()` 时，编译报错。

## 解决

使用 [windows.hpp](windows.hpp) 即可。