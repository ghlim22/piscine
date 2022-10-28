/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwlee <dongwlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:24:23 by gylim             #+#    #+#             */
/*   Updated: 2022/10/19 20:33:07 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_struct.h"
#include "ft_line.h"

t_line	*ft_init_line(t_data *map)
{
	t_line	*new_line;

	new_line = malloc(sizeof(t_line));
	if (new_line == NULL)
		return (NULL);
	new_line->content = malloc(sizeof(char) * (map->info[0][1]) + 1);
	if (new_line->content == NULL)
		return (NULL);
	new_line->len = 0;
	new_line->next = 0;
	return (new_line);
}

void	ft_free_line(t_line *head)
{
	t_line	*cur;
	t_line	*next;
	int		i;

	i = 0;
	cur = head;
	if (!head)
		return ;
	while (cur)
	{
		next = cur->next;
		free(cur->content);
		free(cur);
		cur = next;
		i++;
	}
}

void	ft_link_line(t_data *map, t_line **cur, int len)
{
	(*cur)->len = len - 1;
	(*cur)->content[len - 1] = 0;
	(*cur)->next = ft_init_line(map);
	*cur = (*cur)->next;
}
