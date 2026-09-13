#ifndef ALLOC_H
#define ALLOC_H

#include <stddef.h>

extern /*@null@*//*@out@*/char *alloc(size_t n);
extern void alloc_free(char *x);
extern int alloc_re(char **x,size_t m,size_t n);

#endif
