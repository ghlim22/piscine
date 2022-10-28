# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:22:26 by gylim             #+#    #+#              #
#    Updated: 2022/10/13 18:57:33 by gylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/ft_atoi.c srcs/ft_arithmetic.c srcs/ft_putnbr.c
OBJCS = $(SRCS:.c=.o)
NAME = do-op

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

all: $(NAME)
$(NAME): $(OBJCS)
	$(CC) $(CFLAGS) $(OBJCS) -o $(NAME)

clean: 
	rm -f $(OBJCS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
