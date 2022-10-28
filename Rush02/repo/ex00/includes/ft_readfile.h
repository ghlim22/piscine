/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:31:09 by gylim             #+#    #+#             */
/*   Updated: 2022/10/16 18:11:55 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READFILE_H

# define FT_READFILE_H

typedef struct s_list	t_list;

int	ft_get_line(char buffer[], char **idx, char **key, int cur_idx);
int	ft_read_dic_all(t_list *list, char *buffer);

#endif