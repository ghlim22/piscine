/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:47:55 by gylim             #+#    #+#             */
/*   Updated: 2022/10/17 21:37:33 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **tab, int i, int j)
{
	char	*tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;
	int	i;
	int	j;

	size = 0;
	while (tab[size])
		size++;
	if (size <= 1)
		return ;
	i = -1;
	while (++i + 1 < size)
	{
		j = 0;
		while (++j < size)
		{
			if ((*cmp)(tab[j - 1], tab[j]) > 0)
				ft_swap(tab, j - 1, j);
		}
	}
}
