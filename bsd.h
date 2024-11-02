#ifndef BSD_H
#define BSD_H

#include <stdarg.h>
#include "types.h"
#include "stat.h"
#include "user.h"

// #include "getopt.c"
#include "limits.h"
#include "errno.h"

#define stdin               0
#define stdout              1
#define stderr              2
#define _POSIX2_LINE_MAX    2048                    // as appears in many UNIX clibs
#define NULL                0
#define EOF                 (-1) //('D' - '@')

extern char *optarg;

// bsd.c
int fopen(char* filename, char* options);
void fclose(int fd);
void putchar(char c);
char* strerror(int err);
char getc(int fd);
char* fgets(char *buff, int size, int fd);
void fprintf(int fd, const char *fmt, ...);
void vfprintf(int fd, const char *fmt, ...);
void bsd__printf(const char *fmt, ...);

// getopt.c
struct opt {  // TODO: why doesn't think work when I just do `struct opt`
	int opterr;
	int optind;
	int optopt;
	char* optarg;
};
void optinit(struct opt* optstuct);
int getopt(int argc, char **argv, char *optstuct);

#endif BSD_H
