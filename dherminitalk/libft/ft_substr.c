/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:49:16 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:54:44 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_new;

	if (!(s))
		return (NULL);
	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	s_new = malloc(sizeof(char) * (len + 1));
	if (!s_new)
		return (NULL);
	s_new = ft_memcpy(s_new, s + start, len);
	s_new[len] = '\0';
	return (s_new);
}
