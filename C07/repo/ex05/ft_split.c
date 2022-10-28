/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:58:45 by gylim             #+#    #+#             */
/*   Updated: 2022/10/10 10:43:00 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*get_word(char *str, char *charset, int *len);
int		ft_count_words(char *str, char *charset);
void	ft_fillword(char *dst, char *src, int word_len);
int		ft_is_sep(char c, char *charset);

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word_len;
	int		word_cnt;
	char	*word;
	char	**arr;

	i = 0;
	word_cnt = ft_count_words(str, charset);
	arr = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	while (*str && i < word_cnt)
	{
		word = get_word(str, charset, &word_len);
		if (!word)
			break ;
		arr[i] = malloc(word_len + 1);
		ft_fillword(arr[i], word, word_len);
		str = word + word_len;
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void	ft_fillword(char *dst, char *src, int word_len)
{
	int	i;

	i = 0;
	while (i < word_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*get_word(char *str, char *charset, int *len)
{
	char	*word;

	*len = 0;
	word = NULL;
	while (ft_is_sep(*str, charset))
		++str;
	if (*str)
	{
		word = str;
		while (*str && !ft_is_sep(*str, charset))
		{
			++*len;
			++str;
		}
	}
	return (word);
}

int	ft_is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
		{
			return (1);
		}
		charset++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && ft_is_sep(*str, charset))
			str++;
		if (*str)
		{
			cnt++;
			while (*str && !ft_is_sep(*str, charset))
				str++;
		}	
	}
	return (cnt);
}
