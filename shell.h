#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>

#define PROMPT "$ "
#define ERROR_CODE 70

typedef char *string;

size_t _strlen(const string src);
char **split_string(char *src, char split_char, int *count);
char *_strcpyn(char *dest, const char *src, int n);

#endif /* SHELL_H */
