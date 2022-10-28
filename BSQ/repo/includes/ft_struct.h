/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwlee <dongwlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:20:55 by gylim             #+#    #+#             */
/*   Updated: 2022/10/19 20:07:43 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H

# define FT_STRUCT_H

typedef struct s_data
{
	char	**map;
	int		info[3][3];
}	t_data;

typedef struct s_line
{
	char			*content;
	int				len;
	struct s_line	*next;
}	t_line;

#endif
