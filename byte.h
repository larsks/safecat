#ifndef BYTE_H
#define BYTE_H

extern unsigned int byte_chr();
extern unsigned int byte_rchr();
extern void byte_copy(register char *to, register unsigned int n, const register char *from);
extern void byte_copyr(register char *to, register unsigned int n, register char *from);
extern int byte_diff(register char *s, register unsigned int n, register char *t);
extern void byte_zero(char *s, register unsigned int n);

#define byte_equal(s,n,t) (!byte_diff((s),(n),(t)))

#endif
