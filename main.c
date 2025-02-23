#include "./libasm.h"

void try_strcmp(char* s1, char* s2);
void try_strdup(char* str);
void try_strcpy(char* str);
void try_strlen(char* str);
void try_write(char* str);
void try_read();

int main(void)
{	
	try_strlen("Salut");
	try_strlen("");

	printf("------------------------------------------------------------------\n\n");

	try_strcmp("Salut", "Salut");
	try_strcmp("Salut", "saluut");
	try_strcmp("", "");

	printf("------------------------------------------------------------------\n\n");

	try_strcpy("Hellooo");
	try_strcpy("");

	printf("------------------------------------------------------------------\n\n");
	
	try_strdup("Bonjouuuur");
	try_strdup("");

	printf("------------------------------------------------------------------\n\n");

	try_read();

	printf("------------------------------------------------------------------\n\n");

	try_write("\nca va bien et toi ?");

	return (0);
}

void try_strlen(char* str) {
	printf("\t------- strlen -------\n");
	
	printf("\033[0;31m[OG]\t \'%s\'\033[0m \033[0;33m[%zd]\033[0m\n", str, strlen(str));
	/*	--------------------------------- */
	printf("\033[0;34m[ASM]\t \'%s\'\033[0m \033[0;33m[%zd]\033[0m\n", str, ft_strlen(str));

	printf("\t----------------------\n\n");
}

void try_write(char* str) {
	printf("\t------- write -------\n");
	{
		int fd = open("./file.txt", O_RDWR | O_APPEND);

		int ret = write(fd, str, strlen(str));
		printf("\033[0;31m[OG]\t\033[0m \033[0;33m[%d]\033[0m\n",ret);
		close(fd);
	}
	/*	--------------------------------- */
	{
		int fd = open("./file.txt", O_RDWR | O_APPEND);

		int ret2 = ft_write(fd, str, strlen(str));
		printf("\033[0;31m[OG]\t\033[0m \033[0;33m[%d]\033[0m\n",ret2);

		close(fd);
	}

	printf("\t----------------------\n\n");
}

void try_read() {
	printf("\t------- read -------\n");
	{
		int fd = open("./file.txt", O_RDWR | O_APPEND);
		
		char buf[1000];
		size_t buffer_size = 1000;
		int bytes = read(fd, buf, buffer_size);


		printf("\033[0;31m[OG]\t\033[0m \033[0;33m[%s] [%d]\033[0m\n", buf, bytes);
		
		close(fd);
	}
	/*	--------------------------------- */
	{
		int fd = open("./file.txt", O_RDWR | O_APPEND);

		char buf2[1000];
		size_t buffer_size2 = 1000;
		int bytes2 = ft_read(fd, buf2, buffer_size2);

		printf("\033[0;34m[ASM]\t\033[0m \033[0;33m[%s] [%d]\033[0m\n", buf2, bytes2);
		close(fd);
	}
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