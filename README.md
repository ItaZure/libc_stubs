## 说明
用于对libc中的若干标准函数编写stub，使其更方便被W-AVC验证。

规范：
1. 添加新函数前，检查该函数stub是否已存在；
2. 用函数名称对文件进行命名，如memset函数用memset.c文件中，并放置到对应的头文件文件夹下（本例为string。被多个头文件声明时，任选一个）。函数和stub文件一一对应；

## 已完成harness

<table>
    <tr>
        <th>header</th><th>function name</th><th>status</th><th>Occurance in CWE</th>
    </tr>
    <!-- string.h -->
    <tr>
        <td rowspan="2"> string </td><td> memcpy</td><td>✅</td><td> CWE_134 </td>
    </tr>
    <tr>
        <td> strncpy </td><td>✅</td><td>CWE_415</td>
    </tr>

</table>


## 相关链接
CBMC built-in library：https://github.com/diffblue/cbmc/tree/develop/src/ansi-c/library


