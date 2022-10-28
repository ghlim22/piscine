# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:22:26 by gylim             #+#    #+#              #
#    Updated: 2022/10/11 18:05:42 by gylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJCS = $(SRCS:.c=.o)
NAME = libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

all: $(NAME)
$(NAME): $(OBJCS)
	ar rcs $(NAME) $(OBJCS)

clean: 
	rm -f $(OBJCS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
