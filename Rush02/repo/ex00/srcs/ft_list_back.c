/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:59:40 by gylim             #+#    #+#             */
/*   Updated: 2022/10/16 18:09:40 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_list.h"
#include "ft_string.h"
#include "ft_char.h"

void	ft_print_digit_one(t_list *list, char num)
{
	t_node	*cur;
	char	temp[2];

	temp[0] = num;
	temp[1] = '\0';
	cur = list->head;
	while (cur)
	{
		if (!ft_strcmp(cur->index, temp))
		{
			ft_putstr(cur->key);
			return ;
		}
		cur = cur->next;
	}
}

void	ft_print_digit_two(t_list *list, char num1, char num2)
{
	t_node	*cur;
	char	temp[3];

	temp[0] = num1;
	temp[1] = num2;
	temp[2] = '\0';
	cur = list->head;
	while (cur)
	{
		if (!ft_strcmp(cur->index, temp))
		{
			ft_putstr(cur->key);
			return ;
		}
		cur = cur->next;
	}
}

void	ft_print_scale(t_list *list, int i, int len)
{
	int		check;
	t_node	*cur;

	cur = list->head;
	check = len - i;
	while (cur)
	{
		if (cur->len == check)
		{
			ft_putstr(cur->key);
			return ;
		}
		cur = cur->next;
	}
}

/* where i != 0,1,2 and i != last 3 */
void	ft_get_key(t_list *list, char *num, int i, int len)
{
	if (num[i - 2] != '0')
	{
		ft_print_digit_one(list, num[i - 2]);
		ft_putchar(' ');
		ft_print_scale(list, 0, 3);
		ft_putchar(' ');
	}
	if (num[i - 1] == '1')
	{
		ft_print_digit_two(list, num[i - 1], num[i]);
		ft_putchar(' ');
	}
	else if (num[i - 1] != '0')
	{
		ft_print_digit_two(list, num[i - 1], '0');
		ft_putchar(' ');
	}
	if (num[i - 1] != '1' && num[i] != '0')
	{
		ft_print_digit_one(list, num[i]);
		ft_putchar(' ');
	}
	if ((num[i - 2] != '0' || num[i - 1] != '0') && (i != len - 1))
		ft_print_scale(list, i, len);
}

void	ft_get_key_front(t_list *list, char *num, int i, int len)
{
	if (i == 0)
	{
		ft_print_digit_one(list, num[i]);
		ft_putchar(' ');
		if (i != len - 1)
			ft_print_scale(list, i, len);
	}
	else if (i == 1 && num[i - 1] == '1')
	{
		ft_print_digit_two(list, num[i - 1], num[i]);
		ft_putchar(' ');
		if (i != len - 1)
			ft_print_scale(list, i, len);
	}
	else if (i == 1)
	{
		ft_print_digit_two(list, num[i - 1], '0');
		ft_putchar(' ');
		if (num[i] != '0')
			ft_print_digit_one(list, num[i]);
		ft_putchar(' ');
		if (i != len - 1)
			ft_print_scale(list, i, len);
	}
}
