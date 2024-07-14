SRCS	=	stack/push.c stack/reverse_rotate.c stack/rotate.c stack/stack.c stack/swap.c stack/utils.c test.c

OBJS	=	${SRCS:.c=.o}

NAME	=	output

HEAD	=	stack

CFLAGS	=	-g

all	:	${OBJS}
		cc ${CFLAGS} ${OBJS} -o ${NAME} -I ${HEAD}

%.o	:	%.c
		cc ${CFLAGS} -I ${HEAD} -c $< -o $@

clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}