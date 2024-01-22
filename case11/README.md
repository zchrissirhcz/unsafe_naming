# call to 'sum' is ambiguous

https://blog.csdn.net/creambean/article/details/97431580

在 MSVC 下的报错， 会提示说是重载函数的 ambiguous 二义性: (https://godbolt.org/z/4Gq8h9W5f)
```batch
example.cpp
<source>(14): error C2668: 'sum': ambiguous call to overloaded function
<source>(9): note: could be 'int sum(float,float)'
<source>(5): note: or       'int sum(int,int)'
<source>(14): note: while trying to match the argument list '(double, double)'
<source>(14): error C2088: built-in operator '<<' cannot be applied to an operand of type 'std::ostream'
cl : Command line warning D9002 : ignoring unknown option '-O0'
cl : Command line warning D9002 : ignoring unknown option '-std=c++11'
Compiler returned: 2
```

Linux Clang 17.0 则报错为：  call to 'sum' is ambiguous (https://godbolt.org/z/G8TKb5dEx )
```bash
<source>:14:12: error: call to 'sum' is ambiguous
   14 |    cout << sum(1.3, 2.7);
      |            ^~~
<source>:5:5: note: candidate function
    5 | int sum(int a,int b){
      |     ^
<source>:9:5: note: candidate function
    9 | int sum(float a, float b){
      |     ^
1 error generated.
Compiler returned: 1
```

错误原因是因为 sum(1.3, 2.7) 的调用在编译器看来, 1.3 和 2.7 是 double 类型, 因此sum(int a, int b) 和 sum(float a, float b) 都是合适的候选调用对象.
编译器不知道你到底想要哪一种, 因此就会报该错误.

解决方式就是显示的指定你要哪一种. 例如本例中, 可以在 1.3 后面加上 f 后缀就可以了
