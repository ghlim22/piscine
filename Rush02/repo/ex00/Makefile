# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:22:26 by gylim             #+#    #+#              #
#    Updated: 2022/10/18 12:55:00 by gylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_char.c srcs/ft_list.c srcs/ft_list_back.c srcs/ft_string.c srcs/ft_string2.c srcs/ft_readfile.c srcs/main.c
OBJCS = $(SRCS:.c=.o)
NAME = rush-02

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

all: $(NAME)
$(NAME): $(OBJCS)
	$(CC) $(CFLAGS) $(OBJCS) -o $@ -I includes/
debug: $(OBJCS)
	$(CC) $(CFLAGS) $(OBJCS) -o $@ -I includes/ -g

clean: 
	rm -f $(OBJCS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
