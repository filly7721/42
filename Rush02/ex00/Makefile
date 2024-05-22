# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 20:18:42 by bugadzhi          #+#    #+#              #
#    Updated: 2024/05/18 20:18:44 by bugadzhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	rush-02

CMPL	=	cc
FLAGS	=	-Wall -Wextra -Werror

S_DIR	=	./

SRCS	=	$(S_DIR)main.c		\
			$(S_DIR)converter.c	\
			$(S_DIR)parser.c	\
			$(S_DIR)validator.c	\
			$(S_DIR)utils_1.c	\
			$(S_DIR)utils_2.c	\
			$(S_DIR)utils_3.c	\
			$(S_DIR)utils_4.c	\
			$(S_DIR)rush02.c

all: $(NAME)

$(NAME):
	$(CMPL) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean
	
re: fclean all

.PHONY: all clean fclean re