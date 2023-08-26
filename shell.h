#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>

#define PROMPT "$ "
#define ERROR_CODE 70
#define MAX_ARGS 20

typedef char *string;
typedef char **array;
extern array environ;
/* free_array.c */
void _free(array arr);
/* errors.c */
void _print_error(string pg_name, string cmd_name, int process_no);
/* write.c */
int _write(string str);
/* string.c */
size_t _strlen(const string src);
void num_to_string(string str, int num);
/* exec_cmd.c */
void exec_cmd(array cmd_args, array argv);
/* split_string.c */
array split_string(string buffer, string split_con);

#endif /* SHELL_H */
