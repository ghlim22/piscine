/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:45:52 by gylim             #+#    #+#             */
/*   Updated: 2022/10/16 18:51:00 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	ft_swap(char **tab, int i, int j)
{
	char	*tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void	ft_sort_string_tab(char **tab)
{
	int	size;
	int	i;
	int	j;
	int	pivot;

	size = 0;
	if (!tab)
		return ;
	while (tab[size])
		size++;
	if (size <= 1)
		return ;
	i = -1;
	while (++i + 1 < size)
	{
		j = i;
		pivot = i;
		while (++j < size)
		{
			if (ft_strcmp(tab[j], tab[pivot]) < 0)
				pivot = j;
		}
		if (pivot != i)
			ft_swap(tab, i, pivot);
	}
}
