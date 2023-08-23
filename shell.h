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

#define PROMPT "$ "
#define ERROR_CODE 70

typedef char *string;
typedef char **array;

typedef struct program_info
{
	int process_no;
	string program_name;
	array envp;
} info_t;

int _write(string str);
int _strcmp(string s1, string s2);
string get_buf(void);
size_t _strlen(const string src);
void exec_cmd(string buffer, info_t info);
char **split_string(string src, char delim);
char *_strcpynn(string dest, const string src, int dest_from, int src_from);

#endif /* SHELL_H */
