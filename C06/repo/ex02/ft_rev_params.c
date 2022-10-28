/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:50:33 by gylim             #+#    #+#             */
/*   Updated: 2022/10/07 22:52:19 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	___ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	___ft_putstr(char *str)
{
	int	len;

	len = ___ft_strlen(str);
	write(1, str, len);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc <= 1)
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		___ft_putstr(argv[i]);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
