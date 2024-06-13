SRCS	=	${shell find . -name '*.c'}

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CFLAGS	=	-Wextra -Wall -Werror

all		:	${NAME}

.c		:	.o
	cc ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

clean	:
	rm -f ${OBJS}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re