/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 04:10:41 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 05:26:29 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > -1)
	{
		if (str[i] == (char)character)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
