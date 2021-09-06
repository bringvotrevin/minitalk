/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:48:53 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:51:49 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	int		s_len;

	s_len = ft_strlen((char *)s);
	s_copy = malloc(s_len + 1);
	if (!s_copy)
		return (NULL);
	ft_memcpy(s_copy, (char *)s, s_len);
	s_copy[s_len] = 0;
	return (s_copy);
}
