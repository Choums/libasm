#include "./libasm.h"

void try_strcpy(char* str);
void try_strlen(char* str);
void try_write(int fd, char* str);
void try_read(int fd);

int main(void)
{
	// int fd = open("./file.txt", O_RDWR | O_APPEND);
	
	try_strcpy("salut comment ca va ???????");
	
	// close(fd);
	return (0);
}

void try_strlen(char* str) {
	printf("-----\tstrlen\t-----\n");
	
	printf("\033[0;31m[OG]\t \'%s\'\033[0m \033[0;33m[%zd]\033[0m\n", str, strlen(str));
	/*	--------------------------------- */
	printf("\033[0;34m[ASM]\t \'%s\'\033[0m \033[0;33m[%zd]\033[0m\n", str, ft_strlen(str));

	printf("---------------------\n\n");
}

void try_write(int fd, char* str) {
	printf("-----\twrite\t-----\n");

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

	printf("---------------------\n\n");
}

void try_read(int fd) {
	printf("-----\tread\t-----\n");
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

	printf("---------------------\n\n");
}

void try_strcpy(char* str) {
	printf("-----\tstrcpy\t-----\n");
	
	char buf[1000];

	printf("\033[0;31m[OG]\t \'%s\'\033[0m \033[0;33m[%s]\033[0m\n", str, strcpy(buf, str));
	/*	--------------------------------- */
	printf("\033[0;34m[ASM]\t \'%s\'\033[0m \033[0;33m[%s]\033[0m\n", str, ft_strcpy(buf, str));

	printf("---------------------\n\n");
}