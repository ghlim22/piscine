/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:25:10 by jinhyeop          #+#    #+#             */
/*   Updated: 2022/10/16 23:32:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_list.h"
#include "ft_string.h"
#include "ft_char.h"
#include "ft_readfile.h"

int		cut_number(int argc, char *input, char *arr);
void	ft_print_list(t_list *list);

int	main(int argc, char *argv[])
{
	char	*input;
	t_list	*initial_list;
	char	buffer[4096];

	initial_list = ft_init_list();
	initial_list->head = NULL;
	ft_read_dic_all(initial_list, buffer);
	input = (char *)malloc(sizeof(char) * 100);
	if (input == NULL)
		return (0);
	if (cut_number(argc, input, argv[argc - 1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_strlen(input) > 39)
		write(2, "Dict Error\n", 11);
	else
		ft_convert(initial_list, input);
	free(input);
	ft_free_list(initial_list);
	write(1, "\n", 1);
	system("leaks rush-02");
	return (0);
}

int	cut_number(int argc, char *input, char *arr)
{
	int	i;

	i = 0;
	if (!(argc == 2 || argc == 3))
		return (0);
	while ((*arr >= 9 && *arr <= 13) || *arr == ' ')
		arr++;
	if (*arr == '-')
		return (0);
	if (*arr == '+')
		arr++;
	if (!(*arr >= '0' && *arr <= '9'))
		return (0);
	while (*arr == '0')
		arr++;
	while (*arr >= '0' && *arr <= '9')
		input[i++] = *arr++;
	input[i] = '\0';
	return (1);
}
