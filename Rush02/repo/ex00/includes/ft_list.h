/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:57:31 by gylim             #+#    #+#             */
/*   Updated: 2022/10/16 18:02:18 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H

# define FT_LIST_H

# define BUF_SIZE (100000)

typedef struct s_node
{
	char			*index;
	char			*key;
	int				len;
	struct s_node	*next;

}	t_node;

typedef struct s_list
{
	t_node	*head;
}	t_list;

t_list	*ft_init_list(void);
t_node	*ft_gen_node(char *index, char *key);
int		ft_add_list(t_list *list, char *index, char *key);
void	ft_free_list(t_list *list);
void	ft_convert(t_list *list, char *num);

#endif