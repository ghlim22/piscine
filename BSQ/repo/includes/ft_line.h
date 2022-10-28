/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwlee <dongwlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:29:02 by gylim             #+#    #+#             */
/*   Updated: 2022/10/19 20:28:13 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINE_H

# define FT_LINE_H

t_line	*ft_init_line(t_data *map);
void	ft_free_line(t_line *head);
void	ft_link_line(t_data *map, t_line **cur, int len);

#endif
