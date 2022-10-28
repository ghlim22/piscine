/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:12:25 by gylim             #+#    #+#             */
/*   Updated: 2022/10/01 22:49:59 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(int c);

void	rush(int x, int y)
{
	int		col;
	int		row;

	row = -1;
	while (++row < y)
	{
		col = -1;
		while (++col < x)
		{
			if (row == 0 && col == 0)
				ft_putchar('A');
			else if (row != 0 && col != 0 && row == y -1 && col == x -1)
				ft_putchar('A');
			else if ((row == 0 && col == x -1) || (col == 0 && row == y -1))
				ft_putchar('C');
			else if (col == 0 || row == 0 || row == y -1 || col == x -1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
