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

int _strlen(string src);

#endif /* SHELL_H */
