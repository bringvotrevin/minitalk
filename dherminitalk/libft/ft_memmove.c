/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:01:56 by dher              #+#    #+#             */
/*   Updated: 2021/02/13 22:24:11 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t num)
{
	char		*tmp;
	const char	*s;

	if (str1 == str2 || num == 0)
		return (str1);
	if (str1 < str2)
	{
		tmp = str1;
		s = str2;
		while (num--)
			*(tmp++) = *(s++);
	}
	else
	{
		tmp = str1;
		tmp += num;
		s = str2;
		s += num;
		while (num--)
			*(--tmp) = *(--s);
	}
	return ((char *)str1);
}
