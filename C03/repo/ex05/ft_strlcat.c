/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:40:24 by gylim             #+#    #+#             */
/*   Updated: 2022/10/04 16:35:37 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	__ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	j;

	dest_len = __ft_strlen(dest);
	i = dest_len;
	j = 0;
	if (size <= dest_len || size == 0)
		return (size + __ft_strlen(src));
	while (src[j] && j + dest_len + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < size && dest_len < size)
		dest[i] = '\0';
	return (dest_len + __ft_strlen(src));
}
