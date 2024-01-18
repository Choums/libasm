#include "./libasm.h"

// #define OG \033[0;32m
// \033[0m
void try_strlen(void);


int main(void)
{
	try_strlen();
	return (0);
}

void try_strlen(void) {
	char* str = "Salut ca va ?";

	printf("-----\tstrlen\t-----\n");
	printf("\033[0;31m[OG]\t \'%s\'\033[0m \033[0;33m[%lu]\033[0m\n", str, strlen(str));
	printf("\033[0;34m[ASM]\t \'%s\'\033[0m \033[0;33m[%lu]\033[0m\n", str, ft_strlen(str));

	printf("---------------------\n\n");
}