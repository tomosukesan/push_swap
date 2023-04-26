# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 21:06:16 by ttachi            #+#    #+#              #
#    Updated: 2023/04/25 16:30:45 by ttachi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	push_swap.c \
		push_swap_utils.c \
		make_circular_list.c \
		conv_num_list.c \
		ft_strtol.c \
		list_num_utils.c \
		list_str_utils.c \
		execute_cmd.c \
		each_process.c \
		cmd_swap.c
OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(NAME) main.c $(SRCS) $(LIB)

bonus:
	make -C bonus

debug: $(OBJS)
	$(MAKE) -C libft
	cc $(CFLAGS) -g -o $(NAME) main.c $(SRCS) $(LIB)
#clang -g -fsanitize=address,leak -o $(NAME) main.c $(SRCS) $(LIB)

clean:
#$(MAKE) clean -C libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
