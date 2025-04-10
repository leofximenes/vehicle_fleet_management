#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils/utils.h"

void print(const char *message) {
    printf("%s", message);
}

void println(const char *message) {
    printf("%s\n", message);
}

int read_int() {
    char buffer[100];
    char *endptr;
    int value;

    fgets(buffer, sizeof(buffer), stdin);
    value = (int)strtol(buffer, &endptr, 10);
    return value;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void read_string(char *buffer, int maxLength) {
    clear_input_buffer();
    fgets(buffer, maxLength, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}





