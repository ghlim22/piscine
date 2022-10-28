/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:22:15 by gylim             #+#    #+#             */
/*   Updated: 2022/10/13 19:42:16 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_ascending(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		++i;
	}
	return (1);
}

int	ft_is_descending(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		++i;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	is_ascending;
	int	is_descending;

	is_ascending = ft_is_ascending(tab, length, f);
	is_descending = ft_is_descending(tab, length, f);
	return (is_ascending || is_descending);
}
