# case1: don't use `small` as variable name

Captured on Windows System. Any variable named `small` will cause an error:
```
2>D:\work\unsafe_naming\case1\testbed.cpp(6,9): error C2632: “int”后面的“char”非法
2>D:\work\unsafe_naming\case1\testbed.cpp(6,15): error C2513: “int”: 在“=”前没有声明变量
```