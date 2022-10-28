/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:40:24 by gylim             #+#    #+#             */
/*   Updated: 2022/10/08 14:51:43 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	_ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	_ft_putstr(char *str)
{
	int	len;

	len = _ft_strlen(str);
	write(1, str, len);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		;
	_ft_putstr(argv[0]);
	write(1, "\n", 1);
	return (0);
}
