SRCS		=	main.c utils.c

BONUS_SRCS	=	bonus.c utils.c

LIBFT_DIR	=	./libft

LIBFT		=	${LIBFT_DIR}/libft.a

OBJS		=	${SRCS:.c=.o}

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

NAME		=	pipex

BONUS_NAME	=	pipex_bonus

CFLAGS		=	-Wall -Wextra -Werror -g3

all				:	${NAME}

bonus			:	${BONUS_NAME}

%.o				:	%.c
		cc ${CFLAGS} -I ${LIBFT_DIR} -c $< -o $@

${LIBFT}		:
		make -C ${LIBFT_DIR}

${NAME}			:	${LIBFT} ${OBJS}
		cc ${CFLAGS} -I ${LIBFT_DIR} ${OBJS} ${LIBFT} -o ${NAME}

${BONUS_NAME}	: ${LIBFT} ${BONUS_OBJS}
		cc ${CFLAGS} -I ${LIBFT_DIR} ${BONUS_OBJS} ${LIBFT} -o ${BONUS_NAME}

clean			:
		rm -f ${OBJS} ${BONUS_OBJS}
		make -C ${LIBFT_DIR} clean

fclean			:	clean
		rm -f ${NAME} ${BONUS_NAME}
		make -C ${LIBFT_DIR} fclean

re				:	fclean all

.PHONY			:	all clean fclean re bonus