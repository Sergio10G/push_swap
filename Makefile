# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 19:45:21 by sdiez-ga          #+#    #+#              #
#    Updated: 2022/11/03 20:26:21 by sdiez-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CHECKER		=	checker

PS_SRC		=	src/push_swap.c

SRCS		=	src/input_parse.c			\
				src/input_parse_extra.c		\
				src/algorithm.c				\
				src/list_funcs.c			\
				src/utils.c					\
				src/mv_push.c				\
				src/mv_swap.c				\
				src/mv_rotate.c				\
				src/mv_reverse_rotate.c		\
				src/error_comp.c

CHK_SRC		=	src/checker.c				\
				src/checker_utils.c

LIBFT		=	libft/libft.a

PS_OBJS		=	$(PS_SRC:.c=.o)

OBJS		=	$(SRCS:.c=.o)

CHK_OBJS	=	$(CHK_SRC:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address

RM			=	rm -f

GREEN		=	\033[1;32m
PINK		=	\033[1;35m
BLUE		=	\033[1;36m
RESET		=	\033[1;0m

MAKEFLAGS	+=	--silent

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(LIBFT) $(OBJS) $(PS_OBJS)
				@echo "$(BLUE)Compiling push_swap...$(RESET)"
				$(CC) $(CFLAGS) -o $(NAME) $(PS_OBJS) $(OBJS) $(LIBFT)
				@echo "$(GREEN)push_swap succesfully compiled$(RESET)"

$(LIBFT)	:
				@echo "$(PINK)Compiling libft...$(RESET)"
				make -C libft/ all -s
				make -C libft/ bonus -s
				@echo "$(PINK)All and Bonus made for Libft!$(RESET)"

$(CHECKER)	:	$(LIBFT) $(OBJS) $(CHK_OBJS)
				@echo "$(BLUE)Compiling checker...$(RESET)"
				$(CC) $(CFLAGS) -o $(CHECKER) $(CHK_OBJS) $(OBJS) $(LIBFT)
				@echo "$(GREEN)checker succesfully compiled$(RESET)"

all			:	$(NAME) $(CHECKER)

clean		:	
ifneq ("$(wildcard libft/*.o)","")
				make -C libft/ clean -s
				@echo "$(PINK)libft cleaned!$(RESET)"
endif
ifneq ("$(wildcard $(OBJS))","")
				$(RM) $(OBJS)
endif
ifneq ("$(wildcard $(PS_OBJS))","")
				$(RM) $(PS_OBJS)
				@echo "$(BLUE)push_swap objs cleaned!$(RESET)"
endif
ifneq ("$(wildcard $(CHK_OBJS))","")
				$(RM) $(CHK_OBJS)
				@echo "$(BLUE)checker objs cleaned!$(RESET)"
endif

fclean		:	clean
ifneq ("$(wildcard $(LIBFT))","")
				make -C libft/ fclean -s
				@echo "$(PINK)libft.a removed!$(RESET)"
endif
ifneq ("$(wildcard $(NAME))","")
				$(RM) $(NAME)
				@echo "$(BLUE)push_swap removed!$(RESET)"
endif
ifneq ("$(wildcard $(CHECKER))","")
				$(RM) checker
				@echo "$(BLUE)checker removed!$(RESET)"
endif

re			:	fclean all

.PHONY		:	all clean fclean re
