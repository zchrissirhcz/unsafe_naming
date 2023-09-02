In `rpcndr.h` (C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\shared), in-directly included via `Windows.h`, there is:
```cpp
#define  hyper           __int64
```

Thus, if you are writing:
```cpp
#include <Windows.h>

namespace hyper { // here `hyper` cannot be used, with error message: 应输入标识符
    ...
}
```