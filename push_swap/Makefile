SRCS		=	main.c parse.c init.c check.c small.c sort.c \
				push.c reverse_rotate.c rotate.c stack.c swap.c

LIBFT_DIR	=	./libft

LIBFT		=	${LIBFT_DIR}/libft.a

OBJS		=	${SRCS:.c=.o}

NAME		=	push_swap

CFLAGS		=	-Wall -Wextra -Werror

all			:	${NAME}

%.o			:	%.c
		cc ${CFLAGS} -I ${LIBFT_DIR} -c $< -o $@

${LIBFT}	:
		make -C ${LIBFT_DIR}

${NAME}		:	${LIBFT} ${OBJS}
		cc ${CFLAGS} -I ${LIBFT_DIR} ${OBJS} ${LIBFT} -o ${NAME}

clean		:
		rm -f ${OBJS}
		make -C ${LIBFT_DIR} clean

fclean		:	clean
		rm -f ${NAME}
		make -C ${LIBFT_DIR} fclean

re			:	fclean all

.PHONY		:	all clean fclean re