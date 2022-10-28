/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:39:07 by gylim             #+#    #+#             */
/*   Updated: 2022/10/16 23:32:08 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_list.h"
#include "ft_list_back.h"
#include "ft_string.h"
#include "ft_char.h"

t_list	*ft_init_list(void)
{
	t_list	*new_list;

	new_list = malloc(sizeof(*new_list));
	return (new_list);
}

t_node	*ft_gen_node(char *index, char *key)
{
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->index = ft_strdup(index);
	new_node->key = ft_strdup(key);
	new_node->len = ft_strlen(index);
	free(new_node->key);
	free(new_node->index);
	return (new_node);
}

int	ft_add_list(t_list *list, char *index, char *key)
{
	t_node	*new_node;
	t_node	*cur;

	new_node = ft_gen_node(index, key);
	if (new_node == NULL)
	{
		free(index);
		free(key);
		return (0);
	}	
	if (list->head == NULL)
	{
		list->head = new_node;
	}
	else
	{
		cur = list->head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = new_node;
	}
	return (1);
}

void	ft_free_list(t_list *list)
{
	t_node	*cur;
	t_node	*next;

	cur = list->head;
	while (cur)
	{
		next = cur->next;
		free(cur->index);
		free(cur->key);
		free(cur);
		cur = next;
	}
	free(list);
}

void	ft_convert(t_list *list, char *num)
{
	int	len;
	int	check;
	int	i;

	len = ft_strlen(num);
	i = 0;
	if (num[i] == '\0')
	{
		ft_print_digit_one(list, '0');
		return ;
	}
	while (num[i])
	{
		check = (len - i) % 3;
		if (i < 2 && check == 1)
			ft_get_key_front(list, num, i, len);
		else if (check == 1)
			ft_get_key(list, num, i, len);
		if (i != len - 1 && num[i] != '0')
			ft_putchar(' ');
		i++;
	}
}
