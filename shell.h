#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>

#define PROMPT "$ "
#define MAX_ARGS 64

typedef char *string;
typedef string *array;
extern array environ;

/* memory.c */
void _free(array args);

/* errors.c */
int _ewrite(const string str);
void _print_error(const string program, const string cmd, int count);

/* write.c */
int _write(const string str);

/* string.c */
char *_strdup(const string str);
int _strlen(const string str);
void num_to_string(string str, int num);
int _strncmp(string first_str, string second_str, int n);
char *_concatenate(string str1, string str2, string str3);

/* string2.c */
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
array split_string(string buffer, const string split_con);

/* exec_cmd.c */
void exec_cmd(array cmd_args, array argv);
void exec_full_cmd(string full_cmd, array cmd_args, array argv);

/* get_path.c */
string valid_cmd(string cmd);
string get_full_cmd(string cmd);
bool is_valid_cmd(array cmd_args);

/* builtins.c */
int is_builtin(array args);

int _atoi(char *s);
#endif /* SHELL_H */
