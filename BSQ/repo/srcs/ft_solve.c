/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:41:08 by gylim             #+#    #+#             */
/*   Updated: 2022/10/20 12:41:15 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ft_data.h>
#include "ft_struct.h"
#include "ft_data.h"

#define BUF_SIZE (4096)

int		ft_find_bsq(t_data *map, int row, int col);
void	ft_print(t_data *map);
int		ft_read(int fd, char *path, t_data *map);

void	ft_solve(t_data *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->info[0][0] - map->info[1][2])
	{
		col = 0;
		while (col < map->info[0][1] - map->info[1][2])
		{
			if (map->map[row][col] == map->info[2][0])
			{
				col += ft_find_bsq(map, row, col);
			}
			col++;
		}
		row++;
	}
	ft_print(map);
}

int	ft_solve_stdin(void)
{
	int		fd;
	int		read_byte;
	int		buffer[BUF_SIZE];
	t_data	*map;

	map = ft_init_data();
	fd = open("user_input.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (!map || fd == -1)
		return (-1);
	while (1)
	{
		read_byte = read(0, buffer, BUF_SIZE);
		if (read_byte <= 0)
			break ;
		write(fd, buffer, read_byte);
	}
	close(fd);
	fd = open("user_input.txt", O_RDONLY);
	if (fd == -1 || ft_read(fd, "user_input.txt", map) == -1)
		return (-1);
	else
		ft_solve(map);
	close(fd);
	ft_free_data(&map);
	return (0);
}

int	ft_solve_argv(int argc, char **argv)
{
	int		i;
	int		fd;
	t_data	*map;

	i = 1;
	while (i < argc)
	{
		map = ft_init_data();
		fd = open(argv[i], O_RDONLY);
		if (!map || fd == -1 || ft_read(fd, argv[i], map) == -1)
			write(1, "map error\n", 10);
		else
		{
			ft_solve(map);
		}
		if (i < argc - 1)
			write(1, "\n", 1);
		close(fd);
		if (map)
			ft_free_data(&map);
		i++;
	}
	return (0);
}
