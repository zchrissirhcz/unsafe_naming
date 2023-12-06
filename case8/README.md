# case8: zcnn and std::vector on MSVC

https://godbolt.org/z/MKexa9Yav

```cpp
#include <vector>

namespace zcnn {

int bubbleSort(std::vector<int>& data);

}
```

> 命名空间 "zcnn::std" 没有成员 "vector"

Solution: replace `std::vector` with `::std::vector`:
```cpp
#include <vector>

namespace zcnn {

int bubbleSort(::std::vector<int>& data);

}
```