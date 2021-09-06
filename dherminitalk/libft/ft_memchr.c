/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:01:37 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 05:23:09 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*re_ptr;

	re_ptr = (unsigned char *)s;
	while (n--)
	{
		if (*(char *)re_ptr == (char)c)
			return ((void *)re_ptr);
		re_ptr++;
	}
	return (NULL);
}
