#ifndef SUBSTDIO_H
#define SUBSTDIO_H

typedef struct substdio {
  char *x;
  int p;
  int n;
  int fd;
  int (*op)(int, const char *, int);
} substdio;

#define SUBSTDIO_FDBUF(op,fd,buf,len) { (buf), 0, (len), (fd), (int (*)(int, const char *, int))(op) }

extern void substdio_fdbuf(register substdio *s, register int (*op)(int, const char *, int), register int fd, register char *buf, register int len);

extern int substdio_flush(register substdio *s);
extern int substdio_put(register substdio *s, const char *buf, register int len);
extern int substdio_bput(register substdio *s, const char *buf, register int len);
extern int substdio_putflush(register substdio *s, const char *buf, register int len);
extern int substdio_puts(register substdio *s, const char *buf);
extern int substdio_bputs(register substdio *s, const char *buf);
extern int substdio_putsflush(register substdio *s, const char *buf);

extern int substdio_get(register substdio *s, register char *buf, register int len);
extern int substdio_bget(register substdio *s, register char *buf, register int len);
extern int substdio_feed(register substdio *s);

extern char *substdio_peek(substdio *s);
extern void substdio_seek(register substdio *s, register int len);

#define substdio_fileno(s) ((s)->fd)

#define SUBSTDIO_INSIZE 8192
#define SUBSTDIO_OUTSIZE 8192

#define substdio_PEEK(s) ( (s)->x + (s)->n )
#define substdio_SEEK(s,len) ( ( (s)->p -= (len) ) , ( (s)->n += (len) ) )

#define substdio_BPUTC(s,c) \
  ( ((s)->n != (s)->p) \
    ? ( (s)->x[(s)->p++] = (c), 0 ) \
    : substdio_bput((s),&(c),1) \
  )

extern int substdio_copy(register substdio *ssout, register substdio *ssin);

#endif
