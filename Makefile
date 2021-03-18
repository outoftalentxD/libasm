NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_read.s \
		ft_write.s \
		ft_strcmp.s \

OBJS = $(SRCS:.s=.o)

CC = gcc

ASMFLAGS = -f elf64

%.o:%.s
		nasm -f elf64 $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


test:
	$(CC) main.c $(NAME) && ./a.out

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all