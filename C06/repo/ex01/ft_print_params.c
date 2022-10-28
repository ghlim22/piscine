/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:45:29 by gylim             #+#    #+#             */
/*   Updated: 2022/10/08 14:50:03 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	__ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	__ft_putstr(char *str)
{
	int	len;

	len = __ft_strlen(str);
	write(1, str, len);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		__ft_putstr(argv[i]);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
