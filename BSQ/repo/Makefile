# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:22:26 by gylim             #+#    #+#              #
#    Updated: 2022/10/19 20:53:58 by gylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/ft_data.c srcs/ft_line.c srcs/ft_input.c srcs/ft_solve.c srcs/ft_solve_backend.c
OBJCS = $(SRCS:.c=.o)
NAME = bsq

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

all: $(NAME)
$(NAME): $(OBJCS)
	$(CC) $(CFLAGS) $(OBJCS) -o $@ -I includes/
debug: $(OBJCS)
	$(CC) $(CFLAGS) $(OBJCS) -o $@ -I includes/ -g3 -fsanitize=address

clean: 
	rm -f $(OBJCS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
