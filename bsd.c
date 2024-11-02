#include "bsd.h"

#include "types.h"
#include "user.h"

int fopen(char* filename, char* options) {
    return open(filename, options);
}

void fclose(int fd) {
    close(fd);
}

void putchar(char c) {
    write(stdout, &c, 1);
}

char* strerror(int err) {
    // TODO: make add err num
    return "ERROR";
}  

char getc(int fd) {
    char result;
    fgets(fd, &result, 1);
    return result;
}

char* fgets(char *buff, int size, int fd) {
    read(fd, buff, size);
    return buff;
}

void fprintf(int fd, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(fd, fmt, ap);
    va_end(ap);
}

void vfprintf(int fd, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(fd, fmt, ap);
    va_end(ap);
}

void bsd__printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(stdout, fmt, ap);
    va_end(ap);
}
