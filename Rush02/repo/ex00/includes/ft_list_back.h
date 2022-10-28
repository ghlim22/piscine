/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_back.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:03:06 by gylim             #+#    #+#             */
/*   Updated: 2022/10/16 18:08:30 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_BACK_H

# define FT_LIST_BACK_H

void	ft_print_digit_one(t_list *list, char num);
void	ft_print_digit_two(t_list *list, char num1, char num2);
void	ft_print_scale(t_list *list, int i, int len);
void	ft_get_key(t_list *list, char *num, int i, int len);
void	ft_get_key_front(t_list *list, char *num, int i, int len);

#endif