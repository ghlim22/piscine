/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:11:30 by gylim             #+#    #+#             */
/*   Updated: 2022/10/01 22:46:00 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print(int x, int y)
{
	int		col;
	int		row;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{	
			if (row == 0 && col == 0)
				ft_putchar('/');
			else if (row == y - 1 && col == x - 1 && row != 0 && col != 0)
				ft_putchar('/');
			else if ((row == 0 && col == x - 1) || (row == y - 1 && col == 0))
				ft_putchar('\\');
			else if (row == 0 || row == y - 1 || col == 0 || col == x -1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	ft_print(x, y);
}
