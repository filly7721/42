SRCSDIR		= ./srcs/

SRCS		= ${shell find . ${SRSCDIR} -name '*.c'}

OBJS		= ${SRCS:.c=.o}

INC			= ./includes/

NAME		= do-op

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			cc ${CFLAGS} -I ${INC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			cc -o ${NAME} ${OBJS} ${CFLAGS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
