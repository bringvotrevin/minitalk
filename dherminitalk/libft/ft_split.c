/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:53:17 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 01:10:17 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c)
{
	int	index;

	index = 0;
	while (s[index] != c && s[index])
		index++;
	return (index);
}

static int	count_words(char const *s, char c)
{
	int	count_word;
	int	index;

	index = 0;
	count_word = 0;
	while (s[index])
	{
		if (index == 0 && s[index] != c)
			count_word++;
		else if (index != 0
			&& s[index] != '\0'
			&& s[index - 1] == c
			&& s[index] != c)
			count_word++;
		index++;
	}
	return (count_word);
}

static void	*free_buffer(char **buffer, int index)
{
	while (index >= 0)
		free(buffer[index--]);
	free(buffer);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	int const	str_num = count_words(s, c);
	int			str_idx;
	int			word_idx;

	ret = malloc(sizeof(*ret) * (str_num + 1));
	if (!ret)
		return (NULL);
	str_idx = 0;
	while (str_idx < str_num)
	{
		while (*s == c)
			s++;
		ret[str_idx] = malloc(word_len(s, c) + 1);
		if (!ret[str_idx])
			return (free_buffer(ret, str_idx - 1));
		word_idx = 0;
		while (*s != '\0' && *s != c)
			ret[str_idx][word_idx++] = *(s++);
		ret[str_idx++][word_idx] = '\0';
	}
	ret[str_idx] = NULL;
	return (ret);
}
