//char * s given of a string ,get its length

#include <stddef.h> /* for size_t */
size_t strlen(const char *s) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) ;
    return i;
}

//
int len=0;
while(s[len]!= '\0') len++;

//method 2
#include <stddef.h> /* for size_t */
size_t strlen(const char *s) {
    const char *p = s;
    while (*s) ++s;
    return s - p;
}