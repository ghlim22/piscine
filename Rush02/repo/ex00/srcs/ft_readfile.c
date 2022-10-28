/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:29:09 by gylim             #+#    #+#             */
/*   Updated: 2022/10/16 23:27:34 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_string.h"
#include "ft_readfile.h"
#include "ft_list.h"
#include "ft_char.h"

int	ft_get_line(char buffer[], char **idx, char **key, int cur_idx)
{
	int	i;
	int	j;

	i = cur_idx;
	while (ft_isspace(buffer[i]))
	{
		i++;
	}
	j = i;
	while (ft_isdigit(buffer[j]))
	{
		j++;
	}
	*idx = ft_strndup(&buffer[i], j - i);
	while (ft_isspace(buffer[j]) || buffer[j] == ':')
	{
		j++;
	}
	i = j;
	while (buffer[j] != '\n')
	{
		j++;
	}
	*key = ft_strndup(&buffer[i], j - i);
	return (j);
}

int	ft_read_dic_all(t_list *list, char *buffer)
{
	int		size;
	int		fd;
	int		i;
	char	*idx;
	char	*key;

	fd = open("numbers.dict.txt", O_RDONLY);
	size = read(fd, buffer, BUF_SIZE);
	i = 0;
	while (i + 1 < size)
	{
		i = ft_get_line(buffer, &idx, &key, i);
		ft_add_list(list, idx, key);
		
	}
	close(fd);
	return (1);
}
