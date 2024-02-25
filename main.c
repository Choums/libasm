#include "./libasm.h"

void try_strcmp(char* s1, char* s2);
void try_strdup(char* str);
void try_strcpy(char* str);
void try_strlen(char* str);
void try_write(int fd, char* str);
void try_read(int fd);

int main(void)
{
	// int fd = open("./file.txt", O_RDWR | O_APPEND);
	try_strdup("salut");

	// close(fd);
	return (0);
}

void try_strlen(char* str) {
	printf("\t------- strlen -------\n");
	
	printf("\033[0;31m[OG]\t \'%s\'\033[0m \033[0;33m[%zd]\033[0m\n", str, strlen(str));
	/*	--------------------------------- */
	printf("\033[0;34m[ASM]\t \'%s\'\033[0m \033[0;33m[%zd]\033[0m\n", str, ft_strlen(str));

	printf("\t----------------------\n\n");
}

void try_write(int fd, char* str) {
	printf("\t------- write -------\n");

	char* buf1 = "\033[0;31m[OG]\t [";
	write(fd, buf1, strlen(buf1));

	ssize_t ret = write(fd, str, strlen(str));
	
	char buf2[1000] = "]\033[0m \033[0;33m[";
	write(fd, buf2, strlen(buf2));
	sprintf(buf2, "%zd", ret);
	write(fd, buf2, strlen(buf2));

	char* buf3 = "]\033[0m\n";
	write(fd, buf3, strlen(buf3));

	/*	--------------------------------- */

	char* buf4 = "\033[0;34m[ASM]\t [";
	write(fd, buf4, strlen(buf4));

	ssize_t ret2 = ft_write(fd, str, strlen(str));

	char buf5[1000] = "]\033[0m \033[0;33m[";
	write(fd, buf5, strlen(buf5));
	sprintf(buf5, "%zd", ret2);
	write(fd, buf5, strlen(buf5));


	char* buf6 = "]\033[0m\n";
	write(fd, buf6, strlen(buf6));

	printf("\t----------------------\n\n");
}

void try_read(int fd) {
	printf("\t------- read -------\n");
	// (void)fd;
	
	char buf[1000];
	size_t buffer_size = 1000;
	size_t bytes = read(fd, buf, buffer_size);


	printf("\033[0;31m[OG]\t\033[0m \033[0;33m[%s] [%lu]\033[0m\n", buf, bytes);
	
	/*	--------------------------------- */

	char buf2[1000];
	size_t buffer_size2 = 1000;
	size_t bytes2 = ft_read(fd, buf2, buffer_size2);

	printf("\033[0;34m[ASM]\t\033[0m \033[0;33m[%s] [%lu]\033[0m\n", buf2, bytes2);

	printf("\t----------------------\n\n");
}

void try_strcpy(char* str) {
	printf("\t------- strcpy -------\n");
	
	char buf[1000];

	printf("\033[0;31m[OG]\t \'%s\'\033[0m \033[0;33m[%s]\033[0m\n", str, strcpy(buf, str));
	/*	--------------------------------- */
	printf("\033[0;34m[ASM]\t \'%s\'\033[0m \033[0;33m[%s]\033[0m\n", str, ft_strcpy(buf, str));

	printf("\t----------------------\n\n");
}

void try_strcmp(char* s1, char* s2) {
	printf("\t------- strcmp -------\n");

	int ret = strcmp(s1, s2);
	char buf[50];
	if (!ret)
		sprintf(buf, "\033[0;32m[SAME]\033[0m");
	else
		sprintf(buf, "\033[0;31m[DIFF]\033[0m");

	printf("\033[0;31m[OG]\t \'%s\' \'%s\'\033[0m %s \033[0;33m[%i]\033[0m\n", s1, s2, buf, ret);
	/*	--------------------------------- */

	int ret2 = strcmp(s1, s2);
	char buf2[50];
	if (!ret2)
		sprintf(buf2, "\033[0;32m[SAME]\033[0m");
	else
		sprintf(buf2, "\033[0;31m[DIFF]\033[0m");

	printf("\033[0;34m[ASM]\t \'%s\' \'%s\'\033[0m %s \033[0;33m[%i]\033[0m\n", s1, s2, buf2, ret2);

	printf("\t-----------------------\n\n");
}

void try_strdup(char* str) {
	printf("\t------- strdup -------\n");

	char* new = strdup(str);
	printf("\033[0;31m[OG]\t \'%s\'\033[0m \033[0;33m[%s] [%zd]\033[0m\n", str, new, strlen(new));
	free(new);
	/*	--------------------------------- */
	char* new2 = ft_strdup(str);
	printf("\033[0;34m[ASM]\t \'%s\'\033[0m \033[0;33m[%s] [%zd]\033[0m\n", str, new2, strlen(new2));
	free(new2);

	printf("\t----------------------\n\n");
}