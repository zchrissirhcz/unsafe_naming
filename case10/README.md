# call to 'swap' is ambiguous

## 问题描述
当使用了 `using namespace std` 后，又声明和定义如下的模板函数 `swap()`，会发生冲突：
```cpp
#include<iostream>
using namespace std;
template <typename T>
void swap(T &a,T &b);

int main(){
    int a=5,b=3;
    swap(a,b);
    cout<<a<<b<<endl;
    return 0;

}
template<typename T>
void swap(T &a,T &b){
    T temp;
    temp=a;
    a=b;
    b=temp;
}
```

报错关键字是 "ambiguous":
```bash
<source>:8:5: error: call to 'swap' is ambiguous
    swap(a,b);
    ^~~~
/opt/compiler-explorer/gcc-9.3.0/lib/gcc/x86_64-linux-gnu/9.3.0/../../../../include/c++/9.3.0/bits/move.h:182:5: note: candidate function [with _Tp = int]
    swap(_Tp& __a, _Tp& __b)
    ^
<source>:4:6: note: candidate function [with T = int]
void swap(T &a,T &b);
     ^
1 error generated.
Compiler returned: 1
```

https://en.cppreference.com/w/cpp/algorithm/swap
```cpp
template< class T >
void swap( T& a, T& b ) noexcept( /* see below */ );
```

## Solution

1. 删除 `using namespace std`

2. 使用 `::swap` 替代 `swap`

3. 修改自定义的函数 `swap` 为别的名字，例如 `my_swap`.

## 参考

https://blog.csdn.net/weixin_44798518/article/details/102749850

https://godbolt.org/z/roe115daM
