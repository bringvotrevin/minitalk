/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:19:13 by dher              #+#    #+#             */
/*   Updated: 2021/01/31 22:19:33 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	const char	*dest_start = dest;

	if (dest == source)
		return (NULL);
	while (num--)
		*((char *)dest++) = *((char *)source++);
	return ((char *)dest_start);
}
