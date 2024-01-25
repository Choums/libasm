#ifndef LIBASM_H_
# define LIBASM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


ssize_t ft_strlen(const char* s);
char*	ft_strcpy(char* dest, const char* str);
ssize_t ft_write(int fd, const void* buf, size_t count);
ssize_t ft_read(int fd, const void* buf, size_t count);

#endif