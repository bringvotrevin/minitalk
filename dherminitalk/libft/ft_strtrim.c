/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:52:57 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:57:56 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s1_new;

	if (!(s1 && set))
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[j]) && j != 0)
		j--;
	if (j < i)
		return (ft_strdup(""));
	s1_new = malloc(sizeof(char) * (j - i + 2));
	if (!s1_new)
		return (NULL);
	s1_new = ft_memcpy(s1_new, s1 + i, j - i + 1);
	s1_new[j - i + 1] = '\0';
	return (s1_new);
}
