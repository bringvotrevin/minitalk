/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 01:06:02 by dher              #+#    #+#             */
/*   Updated: 2021/01/20 01:00:12 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_index;
	size_t	copy_index;

	src_index = 0;
	copy_index = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[src_index] != 0)
		src_index++;
	if (siz != 0)
	{
		while (src[copy_index] != 0 && copy_index < siz - 1)
		{
			dst[copy_index] = src[copy_index];
			copy_index++;
		}
		dst[copy_index] = 0;
	}
	return (src_index);
}
