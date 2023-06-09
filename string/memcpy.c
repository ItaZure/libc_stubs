#include <stddef.h>
#include <stdint.h>

void *memcpy(void *dst, const void *src, size_t n) {
    // memcpy src/dst overlap
    __CPROVER_precondition(
        __CPROVER_POINTER_OBJECT(dst) != __CPROVER_POINTER_OBJECT(src) ||
            ((const char *)src >= (const char *)dst + n) || ((const char *)dst >= (const char *)src + n));
    // memcpy source region readable
    __CPROVER_precondition(src != NULL && __CPROVER_r_ok(src, n));
    // memcpy destination region writeable
    __CPROVER_precondition(dst != NULL && __CPROVER_w_ok(dst, n));

    if (n > 0) {
        size_t index;
        __CPROVER_assume(index < n);
        ((uint8_t *)dst)[index] = nondet_uint8_t();
    }
    return dst;
}