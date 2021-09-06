/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:48:33 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:06:04 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elt_count, size_t elt_size)
{
	char	*buffer;

	buffer = malloc(elt_count * elt_size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, elt_count * elt_size);
	return (buffer);
}
