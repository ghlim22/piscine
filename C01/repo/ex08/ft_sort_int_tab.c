/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:37:37 by gylim             #+#    #+#             */
/*   Updated: 2022/10/02 14:06:38 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;
	int	pivot;

	i = 0;
	while (i < size - 1)
	{
		pivot = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[pivot] > tab[j])
				pivot = j;
			j++;
		}
		temp = tab[pivot];
		tab[pivot] = tab[i];
		tab[i] = temp;
		i++;
	}
}
