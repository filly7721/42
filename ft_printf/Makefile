
SRCS	=	ft_puthex.c ft_putstr.c ft_putnbr.c ft_printf.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CFLAGS	=	-Wextra -Wall -Werror

all		:	${NAME}

%.o		:	%.c
	cc ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS}
	ar rcs ${NAME} ${OBJS}

clean	:
	rm -f ${OBJS}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
