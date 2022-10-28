/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwlee <dongwlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:17:57 by gylim             #+#    #+#             */
/*   Updated: 2022/10/19 22:04:05 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H

# define FT_DATA_H

# include "ft_struct.h"

t_data	*ft_init_data(void);
int		ft_malloc_map(t_data *data);
int		ft_free_data(t_data **data);

#endif
