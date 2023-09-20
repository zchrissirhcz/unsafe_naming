# 不要使用 y0, y1, yn, j0, j1, jn 作为全局变量

## 报错原因

math.h 中定义了 Bessel 曲线相关的函数。

ref:
- https://blog.csdn.net/hurmishine/article/details/53293102
- https://www.zhihu.com/question/52901649

## 复现代码
```cpp
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int y0 = 6;
int y1 = 7;
int j0 = 8;
int j1 = 9;

int main() {
  cout << y0 << "," << y1 << "," << yn << endl; // 1,1,1
  cout << j0 << "," << j1 << "," << jn << endl; // 1,1,1
  return 0;
}
```

## G++ 编译报错

G++ 11.3.0 (ubuntu22.04)

```
t3.cpp:6:5: error: ‘int y0’ redeclared as different kind of entity
    6 | int y0 = 6;
      |     ^~
In file included from /usr/include/features.h:486,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/os_defines.h:39,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h:586,
                 from /usr/include/c++/11/cmath:41,
                 from t3.cpp:1:
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:223:1: note: previous declaration ‘double y0(double)’
  223 | __MATHCALL (y0,, (_Mdouble_));
      | ^~~~~~~~~~
t3.cpp:7:5: error: ‘int y1’ redeclared as different kind of entity
    7 | int y1 = 7;
      |     ^~
In file included from /usr/include/features.h:486,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/os_defines.h:39,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h:586,
                 from /usr/include/c++/11/cmath:41,
                 from t3.cpp:1:
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:224:1: note: previous declaration ‘double y1(double)’
  224 | __MATHCALL (y1,, (_Mdouble_));
      | ^~~~~~~~~~
t3.cpp:8:5: error: ‘int j0’ redeclared as different kind of entity
    8 | int j0 = 8;
      |     ^~
In file included from /usr/include/features.h:486,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/os_defines.h:39,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h:586,
                 from /usr/include/c++/11/cmath:41,
                 from t3.cpp:1:
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:220:1: note: previous declaration ‘double j0(double)’
  220 | __MATHCALL (j0,, (_Mdouble_));
      | ^~~~~~~~~~
t3.cpp:9:5: error: ‘int j1’ redeclared as different kind of entity
    9 | int j1 = 9;
      |     ^~
In file included from /usr/include/features.h:486,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/os_defines.h:39,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h:586,
                 from /usr/include/c++/11/cmath:41,
                 from t3.cpp:1:
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:221:1: note: previous declaration ‘double j1(double)’
  221 | __MATHCALL (j1,, (_Mdouble_));
      | ^~~~~~~~~~
```

## Clang 编译报错

Clang 16.0.0

```
t3.cpp:6:5: error: redefinition of 'y0' as different kind of symbol
int y0 = 6;
    ^
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:223:13: note: previous definition is here
__MATHCALL (y0,, (_Mdouble_));
            ^
t3.cpp:7:5: error: redefinition of 'y1' as different kind of symbol
int y1 = 7;
    ^
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:224:13: note: previous definition is here
__MATHCALL (y1,, (_Mdouble_));
            ^
t3.cpp:8:5: error: redefinition of 'j0' as different kind of symbol
int j0 = 8;
    ^
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:220:13: note: previous definition is here
__MATHCALL (j0,, (_Mdouble_));
            ^
t3.cpp:9:5: error: redefinition of 'j1' as different kind of symbol
int j1 = 9;
    ^
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:221:13: note: previous definition is here
__MATHCALL (j1,, (_Mdouble_));
            ^
t3.cpp:12:37: warning: address of function 'yn' will always evaluate to 'true' [-Wpointer-bool-conversion]
  cout << y0 << "," << y1 << "," << yn << endl; // 1,1,1
                                 ~~ ^~
t3.cpp:12:37: note: prefix with the address-of operator to silence this warning
  cout << y0 << "," << y1 << "," << yn << endl; // 1,1,1
                                    ^
                                    &
t3.cpp:12:24: warning: address of function 'y1' will always evaluate to 'true' [-Wpointer-bool-conversion]
  cout << y0 << "," << y1 << "," << yn << endl; // 1,1,1
                    ~~ ^~
t3.cpp:12:24: note: prefix with the address-of operator to silence this warning
  cout << y0 << "," << y1 << "," << yn << endl; // 1,1,1
                       ^
                       &
t3.cpp:12:11: warning: address of function 'y0' will always evaluate to 'true' [-Wpointer-bool-conversion]
  cout << y0 << "," << y1 << "," << yn << endl; // 1,1,1
       ~~ ^~
t3.cpp:12:11: note: prefix with the address-of operator to silence this warning
  cout << y0 << "," << y1 << "," << yn << endl; // 1,1,1
          ^
          &
t3.cpp:13:37: warning: address of function 'jn' will always evaluate to 'true' [-Wpointer-bool-conversion]
  cout << j0 << "," << j1 << "," << jn << endl; // 1,1,1
                                 ~~ ^~
t3.cpp:13:37: note: prefix with the address-of operator to silence this warning
  cout << j0 << "," << j1 << "," << jn << endl; // 1,1,1
                                    ^
                                    &
t3.cpp:13:24: warning: address of function 'j1' will always evaluate to 'true' [-Wpointer-bool-conversion]
  cout << j0 << "," << j1 << "," << jn << endl; // 1,1,1
                    ~~ ^~
t3.cpp:13:24: note: prefix with the address-of operator to silence this warning
  cout << j0 << "," << j1 << "," << jn << endl; // 1,1,1
                       ^
                       &
t3.cpp:13:11: warning: address of function 'j0' will always evaluate to 'true' [-Wpointer-bool-conversion]
  cout << j0 << "," << j1 << "," << jn << endl; // 1,1,1
       ~~ ^~
t3.cpp:13:11: note: prefix with the address-of operator to silence this warning
  cout << j0 << "," << j1 << "," << jn << endl; // 1,1,1
          ^
          &
6 warnings and 4 errors generated.
```


## VS2022 报错

```
D:\github\unsafe_naming\case5\main.cpp(6,5): error C2365: “y0”: 重定义；以前的定义是“函数” [D:\github\unsafe_naming\case5\build\vs2
022-x64\testbed.vcxproj]
C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\ucrt\corecrt_math.h(988,76): message : 参见“y0”的声明 [D:\github
\unsafe_naming\case5\build\vs2022-x64\testbed.vcxproj]
D:\github\unsafe_naming\case5\main.cpp(7,5): error C2365: “y1”: 重定义；以前的定义是“函数” [D:\github\unsafe_naming\case5\build\vs2
022-x64\testbed.vcxproj]
C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\ucrt\corecrt_math.h(989,76): message : 参见“y1”的声明 [D:\github
\unsafe_naming\case5\build\vs2022-x64\testbed.vcxproj]
D:\github\unsafe_naming\case5\main.cpp(8,5): error C2365: “j0”: 重定义；以前的定义是“函数” [D:\github\unsafe_naming\case5\build\vs2
022-x64\testbed.vcxproj]
C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\ucrt\corecrt_math.h(985,76): message : 参见“j0”的声明 [D:\github
\unsafe_naming\case5\build\vs2022-x64\testbed.vcxproj]
D:\github\unsafe_naming\case5\main.cpp(9,5): error C2365: “j1”: 重定义；以前的定义是“函数” [D:\github\unsafe_naming\case5\build\vs2
022-x64\testbed.vcxproj]
```