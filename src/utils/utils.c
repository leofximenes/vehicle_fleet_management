#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "utils/utils.h"

void print(const char *message) {
    printf("%s", message);
}

void println(const char *message) {
    printf("%s\n", message);
}

int read_int(void) {
    char buffer[64];
    if (!fgets(buffer, sizeof(buffer), stdin))
        return -1;

    const size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    char *endptr;
    errno = 0;
    const long value = strtol(buffer, &endptr, 10);

    if (errno != 0 || *endptr != '\0')
        return -1;

    if (value < INT_MIN || value > INT_MAX)
        return -1;

    return value;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool read_string(char *buffer, const int size) {
    if (buffer == NULL || size <= 0)
        return false;
    if (fgets(buffer, size, stdin)) {
        const size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
        else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
        return true;
    }
    return false;
}





