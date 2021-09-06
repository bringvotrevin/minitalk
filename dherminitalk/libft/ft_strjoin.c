/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:49:46 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:52:43 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		index;
	int		i;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	index = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	sum = malloc(sizeof(char) * index);
	if (!sum)
		return (NULL);
	while (i != index - 1)
	{
		if (i < ft_strlen((char *)s1))
			sum[i] = (char)s1[i];
		else
			sum[i] = (char)s2[i - ft_strlen((char *)s1)];
		i++;
	}
	sum[i] = '\0';
	return (sum);
}
