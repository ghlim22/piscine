/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwlee <dongwlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:35:10 by gylim             #+#    #+#             */
/*   Updated: 2022/10/19 21:07:18 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_struct.h"
#include "ft_data.h"
#include "ft_line.h"

int	ft_get_info(int fd, t_data *map);
int	ft_get_width(int fd, t_data *data);
int	ft_read_map(int fd, t_data *map);
int	ft_get_map(t_data *map, t_line *line);

int	ft_get_info(int fd, t_data *map)
{
	int	temp;

	temp = 0;
	while ((read(fd, &temp, 1) == 1) && (temp >= '0' && temp <= '9'))
		map->info[0][0] = map->info[0][0] * 10 + (temp - '0');
	if (map->info[0][0] == 0)
		return (-1);
	map->info[2][0] = temp;
	if (read(fd, &(map->info[2][1]), 1) < 1)
		return (-1);
	if (read(fd, &(map->info[2][2]), 1) < 1)
		return (-1);
	if (map->info[2][0] == '\n' || map->info[2][1] == '\n'\
		|| map->info[2][2] == '\n')
		return (-1);
	if (map->info[2][0] == map->info[2][1] || \
	map->info[2][1] == map->info[2][2] || map->info[2][0] == map->info[2][2])
		return (-1);
	if (map->info[2][0] < 32 || map->info[2][0] == 127 || \
			map->info[2][1] < 32 || map->info[2][1] == 127 || \
			map->info[2][2] < 32 || map->info[2][2] == 127)
		return (-1);
	if (ft_get_width(fd, map) == -1)
		return (-1);
	return (0);
}

int	ft_get_width(int fd, t_data *map)
{
	int	temp;
	int	res;

	temp = 0;
	map->info[0][1] = 0;
	if (read(fd, &temp, 1) < 1 || temp != '\n')
		return (-1);
	while (1)
	{
		res = read(fd, &temp, 1);
		if (res < 1)
			return (-1);
		if (temp == '\n')
			break ;
		map->info[0][1]++;
	}
	return (0);
}

int	ft_read_map(int fd, t_data *map)
{
	int		len;
	int		cnt;
	t_line	*line;
	t_line	*first;

	line = ft_init_line(map);
	first = line;
	cnt = 0;
	while (1)
	{
		len = read(fd, line->content, map->info[0][1] + 1);
		if (len <= 0 || len - 1 != map->info[0][1])
			break ;
		ft_link_line(map, &line, len);
		cnt++;
	}
	if (cnt != map->info[0][0] || ft_get_map(map, first) == -1)
	{
		ft_free_line(first);
		return (-1);
	}
	ft_free_line(first);
	return (0);
}

int	ft_get_map(t_data *map, t_line *line)
{
	int		i;
	int		j;
	t_line	*cur;

	cur = line;
	if (ft_malloc_map(map) == -1)
		return (-1);
	i = 0;
	while (cur && cur->next && i < map->info[0][0])
	{
		j = 0;
		while (j < map->info[0][1])
		{
			map->map[i][j] = cur->content[j];
			if (!(map->map[i][j] == map->info[2][0] || \
						map->map[i][j] == map->info[2][1]))
				return (-1);
			j++;
		}
		cur = cur->next;
		i++;
	}
	if (i == map->info[0][0])
		return (0);
	return (-1);
}

int	ft_read(int fd, char *path, t_data *map)
{
	int	temp;

	temp = 0;
	if (ft_get_info(fd, map) == -1)
		return (-1);
	close(fd);
	if (open(path, O_RDONLY) == -1)
		return (-1);
	while (read(fd, &temp, 1) == 1 && temp != '\n')
		;
	if (ft_read_map(fd, map) == -1)
		return (-1);
	return (0);
}
