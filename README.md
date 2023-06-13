## 说明
用于对libc中的若干标准函数编写stub，使其更方便被W-AVC验证。

规范：
1. 添加新函数前，检查该函数stub是否已存在；
2. 用函数名称对文件进行命名，如memset函数用memset.c文件中，并放置到对应的头文件文件夹下（本例为string。被多个头文件声明时，任选一个）。函数和stub文件一一对应；
3. 用`__CPROVER_precondition(bool, const char*)`对前置条件进行声明和描述

## 已完成harness
|header| function name| Status | Occurs in CWE|
|---|---|---|---|
|string|memcpy| DONE | CWE_134| 



## 相关链接
CBMC built-in library：https://github.com/diffblue/cbmc/tree/develop/src/ansi-c/library


