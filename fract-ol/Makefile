SRCS			=	main.c fractol.c render.c control.c utils.c 

MAND_SRCS		=	${addprefix mandatory/,${SRCS}}

BONUS_SRCS		=	${addprefix bonus/,${SRCS}}

MAND_OBJS		=	${MAND_SRCS:.c=.o}

BONUS_OBJS		=	${BONUS_SRCS:.c=.o}

NAME			=	fractol

BONUS_NAME		=	fractol_bonus

MLX_DIR			=	./mlx

MLX				=	${MLX_DIR}/libmlx.a

C_FLAGS			=	-Wextra -Wall -Werror

all				:	${NAME}

bonus			:	${BONUS_NAME}

%.o				:	%.c
		${CC} ${C_FLAGS} -I ${MLX_DIR} -c $<  -o $@

${MLX}			:
		make -C ${MLX_DIR}

${NAME}			:	${MLX} ${MAND_OBJS}
		${CC} ${C_FLAGS} ${MAND_OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

${BONUS_NAME}	:	${MLX} ${BONUS_OBJS}
		${CC} ${C_FLAGS} ${BONUS_OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${BONUS_NAME}

clean			:
		rm -f ${BONUS_OBJS}
		rm -f ${MAND_OBJS}

fclean			:	clean
		rm -f ${NAME}
		rm -f ${BONUS_NAME}
		make -C ${MLX_DIR} clean

re				:	fclean all

.PHONY			:	all clean fclean re