SRCS	=	ft_printf.c ft_puthex.c ft_putnbr.c ft_putstr.c

OBJS	=	${SRCS:.c=.o}

NAME		=	libftprintf.a

CFLAGS	=	-Wextra -Wall -Werror

all		:	${NAME}

.c		:	.o
	cc ${CFLAGS} -c $< -o $@

test	:	${NAME}
	cc test.c ${NAME}

${NAME}	:	${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

clean	:
	rm -f ${OBJS}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re