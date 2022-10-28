/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:45:34 by gylim             #+#    #+#             */
/*   Updated: 2022/10/01 22:42:22 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c);
void	rush(int x, int y);

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\n');
}

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *num_str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (num_str[i] && ft_isspace(num_str[i]))
		i++;
	if (num_str[i] == '-')
		return (-1);
	while (num_str[i] && ft_isnum(num_str[i]))
	{
		res = res * 10 + (num_str[i] - '0');
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int		x;
	int		y;

	if (argc != 3)
	{
		write(1, "usage: rush x y\n", 16);
		return (0);
	}
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	rush(x, y);
	return (0);
}
