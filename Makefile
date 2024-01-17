NAME = libasm

LIB = libasm.a

SRCS = 	ft_write.s \
		ft_strlen.s \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NASM = nasm

NASMFLAGS = -f elf64 -g -F dwarf

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(LIB) $(OBJ)

c :
	$(CC) $(CFLAGS) main.c $(LIB)
	
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB)
	rm -f ./a.out

re : fclean all