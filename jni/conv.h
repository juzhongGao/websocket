/* use dl API include file */
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <setjmp.h>

int dl_icuuc_init();
int dl_icuuc_uninit();
int32_t dl_icuuc_gbk2utf8(char *outbuf, int32_t buflen, const char *instring, int32_t inlen);
int32_t dl_icuuc_utf82gbk(char *outbuf, int32_t buflen, const char *instring, int32_t inlen);
int32_t dl_icuuc_unicode2utf8(char *outbuf, int32_t buflen, const unsigned short *instring, int32_t inlen);
int32_t dl_icuuc_utf82unicode(unsigned short *outbuf, int32_t buflen, const char *instring, int32_t inlen);
