/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwlee <dongwlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:09:26 by gylim             #+#    #+#             */
/*   Updated: 2022/10/20 12:17:38 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_struct.h"
#include "ft_data.h"
#include "ft_line.h"

int	ft_solve_stdin(void);
int	ft_solve_argv(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (ft_solve_stdin() == -1)
			write(1, "map error\n", 10);
	}
	else
	{
		ft_solve_argv(argc, argv);
	}
	return (0);
}
