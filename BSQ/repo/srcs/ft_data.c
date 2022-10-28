/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwlee <dongwlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:13:55 by gylim             #+#    #+#             */
/*   Updated: 2022/10/20 12:37:57 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_struct.h"
#include "ft_data.h"

t_data	*ft_init_data(void)
{
	int		i;
	int		j;
	t_data	*new_data;

	new_data = (t_data *)malloc(sizeof(t_data));
	if (new_data == NULL)
		return (NULL);
	new_data->map = NULL;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			new_data->info[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new_data);
}

int	ft_malloc_map(t_data *data)
{
	int	i;

	data->map = malloc(sizeof(char *) * (data->info[0][0]));
	if (!(data->map))
		return (-1);
	(data->map)[0] = malloc(sizeof(char) * data->info[0][0] * data->info[0][1]);
	if (!(data->map))
	{
		free(data->map);
		return (-1);
	}
	i = 1;
	while (i < data->info[0][0])
	{
		data->map[i] = data->map[i - 1] + data->info[0][1];
		i++;
	}
	return (0);
}

int	ft_free_data(t_data **data)
{
	if ((*data)->map)
	{
		free(((*data)->map)[0]);
		free((*data)->map);
	}
	free(*data);
	return (0);
}
