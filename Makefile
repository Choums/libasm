NAME = libasm

LIB = libasm.a

SRCS = 	ft_read.s \
		ft_write.s \
		ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s

DEBUG = test.s

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NASM = nasm

NASMFLAGS = -f elf64

OBJ = $(SRCS:.s=.o)

OBJD = $(DEBUG:.s=.o)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(LIB) $(OBJ)
	ranlib $(LIB)

c:
	$(CC) $(CFLAGS) -o program main.c -L. $(LIB) -lasm -fPIE

asm: $(OBJ) $(OBJD)
	ld -o program $(OBJ) $(OBJD) 

MODE = c

debug:
ifeq ($(MODE), asm)
	@make asm
else ifeq ($(MODE), c)
	@make all c
else
	@echo "Only mode [asm] or [c] are accepted !\n"
	exit 1
endif
	gdb program

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f *.o
	rm -f program

re: fclean all