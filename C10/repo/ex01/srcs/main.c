/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:56:19 by gylim             #+#    #+#             */
/*   Updated: 2022/10/13 21:45:13 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> /* close(), read(), write() */
#include <fcntl.h> /* open() */
#include <string.h> /* strerror() */
#include <libgen.h> /* basename() */
#include <errno.h> /* errno */

#define B_SIZE (30000)


int	ft_strlen(char *str);
void	ft_print(int fd, char *str);
void	ft_display(int fd, char *path);
void ft_printerr(char *path);
int ft_is_error(char *path);

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

void	ft_display(int fd, char *path)
{
	char buffer[B_SIZE];
	int	size;

	size = read(fd, buffer, B_SIZE);	
	if (!ft_is_error(path))
			ft_print(1, buffer);
}

void ft_printerr(char *path)
{
	ft_print(2, "ft_cat: ");
	ft_print(2, basename(path));
	ft_print(2, ": ");
	ft_print(2, strerror(errno));
	ft_print(2, "\n");
}

int ft_is_error(char *path)
{
	if (errno)
	{
		ft_printerr(path);
		return (1);
	}
	else
	{
		return (0);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (!ft_is_error(argv[i]))
			ft_display(fd, argv[i]);
		close(fd);
		++i;
	}
}
