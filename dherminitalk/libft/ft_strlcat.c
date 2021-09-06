/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 02:04:40 by dher              #+#    #+#             */
/*   Updated: 2021/01/15 00:41:24 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	const size_t	dstlen = ft_strlen(dst);
	const size_t	srclen = ft_strlen((char *)src);

	i = dstlen;
	if (dstlen >= size)
		return (size + srclen);
	while (i < size - 1 && src[i - dstlen])
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
