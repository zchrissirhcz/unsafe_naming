# `using namespace std` caused variable name conflict

## Compile error
```
main.cpp:9:22: error: called object type 'int' is not a function or function pointer
    double res = sqrt(x);
                 ~~~~^
1 error generated.
```

## Solution

Remove `using namespace std`.

## Solution2

Explicitly write `std::` before occurance of `sqrt`.
```cpp
    double res = sqrt(x);
```

## Solution3

Renaming `sqrt` variable to other.
