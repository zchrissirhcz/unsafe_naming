# case8: zcnn and std::vector on MSVC

https://godbolt.org/z/MKexa9Yav

```cpp
#include <vector>

namespace zcnn {

int bubbleSort(std::vector<int>& data);

}
```

> 命名空间 "zcnn::std" 没有成员 "vector"

Solution: replace `std::vector` with `::std::vector` (scope resolution operator):
```cpp
#include <vector>

namespace zcnn {

int bubbleSort(::std::vector<int>& data);

}
```

Ref: https://stackoverflow.com/questions/4269034/what-is-the-meaning-of-prepended-double-colon