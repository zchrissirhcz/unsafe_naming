# `ERROR` is not safe as an variable name

## Error message
编译报错为：
```
 error C2059: 语法错误:“常数”
```

## Root Cause
`wingdi.h` defines:
```c
#define ERROR               0
```

and `wingdi.h` is indirectly included by `Windows.h`


## How to verify
```
zz9555@zz9555-02712 MINGW64 /c/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um
$ ag 'ERROR' | ag 'define' | ag '\sERROR\s'
esent.h:3225:#define JET_wrnSkipThisRecord                564  /* INTERNAL ERROR */
mfplay.h:1240:#define MFP_GET_ERROR_EVENT( pHdr )                                     __MFP_CAST_EVENT( pHdr, ERROR )
mfplay.idl:799:cpp_quote( "#define MFP_GET_ERROR_EVENT( pHdr )                                     __MFP_CAST_EVENT( pHdr, ERROR )" )
wingdi.h:118:#define ERROR               0
```

## More examples
在使用 ceres 时， `glog/logging.h` 中使用到了 `ERROR`。 若包含头文件时， 先 windows.h, 再 ceres, 会导致报错。
```c++
#include <Windows.h>
#include "ceres/ceres.h"
#include "glog/logging.h"
```
解决方法是改为如下包含顺序:
```c++
#include "ceres/ceres.h"
#include "glog/logging.h"

#include <Windows.h> // 放在最后， 或者干脆不要包含
```