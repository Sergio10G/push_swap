# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 19:45:21 by sdiez-ga          #+#    #+#              #
#    Updated: 2022/02/09 16:44:58 by sdiez-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	src/push_swap.c				\
				src/input_parse.c			\
				src/algorithm.c				\
				src/list_funcs.c			\
				src/utils.c					\
				src/mv_push.c				\
				src/mv_swap.c				\
				src/mv_rotate.c				\
				src/mv_reverse_rotate.c		\
				src/error_comp.c

LIBFT		=	libft/libft.a

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

GREEN		=	\033[1;32m
PINK		=	\033[1;35m
BLUE		=	\033[1;36m
RESET		=	\033[1;0m

MAKEFLAGS	+=	--silent

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
				@echo "$(BLUE)Compiling...$(RESET)"
				make -C libft/ all -s
				make -C libft/ bonus -s
				@echo "$(PINK)All and Bonus made for Libft!$(RESET)"
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a -fsanitize=address
				@echo "$(GREEN)push_swap succesfully compiled$(RESET)"

all			:	$(NAME)

clean		:	
				make -C libft/ clean -s
				@echo "$(BLUE)libft objs cleaned!$(RESET)"
				$(RM) $(OBJS)
				@echo "$(BLUE)push_swap objs cleaned!$(RESET)"

fclean		:	clean
				make -C libft/ fclean -s
				@echo "$(BLUE)libft.a removed!$(RESET)"
				$(RM) $(NAME)
				@echo "$(BLUE)push_swap removed!$(RESET)"

re			:	fclean all

.PHONY		:	all clean fclean re
