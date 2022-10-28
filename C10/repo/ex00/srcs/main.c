/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:20:26 by gylim             #+#    #+#             */
/*   Updated: 2022/10/11 20:21:17 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> /* close(), write(), read() */
#include <fcntl.h> /* open() */

#define B_SIZE (4096)

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_print(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_display(int fd)
{
	int	buffer[B_SIZE];
	int	size;

	size = read(fd, buffer, B_SIZE);
	if (size == -1 || size == 0)
		ft_print(2, "Cannot read file.\n");
	else
		write(1, buffer, size);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		ft_print(2, "File name missing.\n");
	}
	else if (argc > 2)
	{
		ft_print(2, "Too many arguments.\n");
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_print(2, "Cannot read file.\n");
		else
			ft_display(fd);
			close(fd);
	}
	return (0);
}
