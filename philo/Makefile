SRCS	=	main.c init.c utils.c print.c philo.c

OBJS	=	${SRCS:.c=.o}

NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror -pthread

all		:	${NAME}

%.o		:	%.c
		cc ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS}
		cc ${CFLAGS} ${OBJS} -o ${NAME}

clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re bonus