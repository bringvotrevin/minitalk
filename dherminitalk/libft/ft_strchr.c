/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 04:07:16 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 05:26:46 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)character)
			return ((char *)str + i);
		i++;
	}
	if (character == '\0')
		return ((char *)str + i);
	else
		return (NULL);
}
