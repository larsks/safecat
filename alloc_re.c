#include "alloc.h"
#include "byte.h"

int alloc_re(char **x,size_t m,size_t n)
{
  char *y;
 
  y = alloc(n);
  if (!y) return 0;
  byte_copy(y,m,*x);
  alloc_free(*x);
  *x = y;
  return 1;
}
