char *strncpy(char *dst, const char *src, size_t n){
    __CPROVER_precondition(
        __CPROVER_POINTER_OBJECT(dst) != __CPROVER_POINTER_OBJECT(src) ||
            ((const char *)src >= (const char *)dst + n) || ((const char *)dst >= (const char *)src + n),
        "strncpy src/dst overlap");
    __CPROVER_precondition(src != NULL && __CPROVER_r_ok(src, n), "strncpy source region readable");
    __CPROVER_precondition(dst != NULL && __CPROVER_w_ok(dst, n), "strncpy destination region writeable");

    if (n > 0) {
        size_t index;
        __CPROVER_assume(index < n);
        dst[index] = nondet_char();
    }
    return dst;
}