#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define PROMPT "$ "
#define ERROR_CODE 70
#define MAX_ARGS 20

typedef char *string;
typedef char **array;
extern array environ;

/* check_cmd */
int check_cmd(array cmd_args, array argv, int process_no);

/* memory.c */
void free_array(array args);

/* errors.c */
void _print_error(string pg_name, string cmd_name, int process_no);

/* write.c */
int _write(string str);
int _ewrite(string str);

/* string.c */
int _strlen(const string str);
char *_strdup(const string str);
void num_to_string(string str, int num);
int _strncmp(string first_str, string second_str, int n);

/* string2.c */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
array split_string(string buffer, string split_con);

/* exec_cmd.c */
void exec_cmd(array cmd_args, array argv);

/* split_string.c */
array split_string(string buffer, string split_con);

/* path.c */
string search_path(string cmd);

#endif /* SHELL_H */
