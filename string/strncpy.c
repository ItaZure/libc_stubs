#include <stddef.h>
#include <stdint.h>

char *strncpy(char *dst, const char *src, size_t n){
    // strncpy src/dst overlap 
    __CPROVER_assume(
        __CPROVER_POINTER_OBJECT(dst) != __CPROVER_POINTER_OBJECT(src) || 
        ((const char *)src >= (const char *)dst + n) || ((const char *)dst >= (const char *)src + n));
    // strncpy source region readable
    __CPROVER_assume(src != NULL && __CPROVER_r_ok(src, n));
    // strncpy destination region writeable
    __CPROVER_assume(dst != NULL && __CPROVER_w_ok(dst, n));

    if (n > 0) {
        size_t index;
        __CPROVER_assume(index < n);
        ((uint8_t *)dst)[index] = nondet_uint8_t();
    }
    return dst;
}