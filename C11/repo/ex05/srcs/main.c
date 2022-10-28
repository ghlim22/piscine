/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:04:10 by gylim             #+#    #+#             */
/*   Updated: 2022/10/13 19:46:07 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_putnbr.h"
#include "ft_atoi.h"
#include "ft_arithmetic.h"

int	is_valid_op(char *str)
{
	char	op;

	if (!str || !str[0] || (str[0] && str[1]))
		return (0);
	if (!str[1])
	{
		op = str[0];
		if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
			return (1);
		else
			return (0);
	}
	return (0);
}

void	set_arr(int (*arr[])(int, int))
{
	arr[0] = ft_add;
	arr[1] = ft_subtract;
	arr[2] = ft_multiply;
	arr[3] = ft_divide;
	arr[4] = ft_mod;
}

int	calculate(int a, int b, char op, int (*arr[])(int, int))
{
	if (op == '+')
		return ((arr[0])(a, b));
	else if (op == '-')
		return ((arr[1])(a, b));
	else if (op == '*')
		return ((arr[2])(a, b));
	else if (op == '/')
		return ((arr[3])(a, b));
	else if (op == '%')
		return ((arr[4])(a, b));
	else
		return (0);
}

int	check_calc(int num, char op)
{
	if (num == 0)
	{
		if (op == '/')
		{
			write(1, "Stop : division by zero\n", 24);
			return (0);
		}
		else if (op == '%')
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		num1;
	int		num2;
	int		(*arr[5])(int, int);

	if (argc != 4)
		return (0);
	set_arr(arr);
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if (!is_valid_op(argv[2]))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (!check_calc(num2, argv[2][0]))
		return (0);
	ft_putnbr(calculate(num1, num2, argv[2][0], arr));
	write(1, "\n", 1);
	return (0);
}
