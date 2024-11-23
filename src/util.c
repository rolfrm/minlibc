#include <sys/types.h>
#include <string.h>

void *memmove(void *dst, const void *src, size_t n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    if (d < s) while (n--) *d++ = *s++;
    else {
        d += n;
        s += n;
        while (n--) *--d = *--s;
    }
    return dst;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    while (n-- && *s1 && (*s1 == *s2)) s1++, s2++;
    return n == (size_t)-1 ? 0 : *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *strrchr(const char *s, int c) {
    const char *last = NULL;
    while (*s) {
        if (*s == c) last = s;
        s++;
    }
    return (char *) (c == '\0' ? s : last);
}

size_t strcspn(const char *s1, const char *s2) {
    const char *p1, *p2;
    for (p1 = s1; *p1; p1++) {
        for (p2 = s2; *p2; p2++) {
            if (*p1 == *p2) return p1 - s1;
        }
    }
    return p1 - s1;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = s1, *p2 = s2;
    while (n--) {
        if (*p1 != *p2) return *p1 - *p2;
        p1++, p2++;
    }
    return 0;
}

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) s1++, s2++;
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void *memcpy(void *dst, const void *src, size_t n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    while (n--) *d++ = *s++;
    return dst;
}

void *memset(void *s, int c, size_t n) {
    unsigned char *p = s;
    while (n--) *p++ = (unsigned char)c;
    return s;
}