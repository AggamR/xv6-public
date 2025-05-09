#include "bsd.h"

#include "types.h"
#include "user.h"
#include "fcntl.h"

int fopen(char* filename, char* options) {
    char r = 0, w = 0;
    while (*options != 0) {
        if (*options == 'r') r = 1;
        if (*options == 'w') w = 1;
    }
    // no valid options
    if (r + w == 0) return -1;

    return open(
        filename,
        // fancy-ass bitwise to get int option - could do if but that'd be multiple lines
        r && w ? O_RDWR : (r & O_RDONLY) | (w & O_WRONLY)
    );
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
    fgets(&result, 1, fd);
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
