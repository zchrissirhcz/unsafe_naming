# `#` in cmake output path

如果是 add_subdirectory("#hello"):

在 Linux 下不会报错
在 Windows 下提示 Output 目录不能包含 #


如果是工程根目录包含了 #：

在 Linux 下不会报错
在 Windows 下提示 Output 目录不能包含 #，修改 RUNTIME_OUTPUT_DIRECTORY 为不带 # 的目录，仍然报错

https://gitlab.kitware.com/cmake/cmake/-/issues/25604