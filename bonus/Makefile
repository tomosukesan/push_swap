# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 21:06:16 by ttachi            #+#    #+#              #
#    Updated: 2023/03/25 13:18:26 by ttachi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = bonus
NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

#SRCS
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

#all: $(NAME)
#$(NAME): $(OBJS)
#	ar r $(NAME) $(OBJS)
#	mv $(NAME) checker

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
