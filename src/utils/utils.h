#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

void print(const char *message);
void println(const char *message);
int read_int();
bool read_string(char *buffer, int size);
void clear_input_buffer();

#endif
