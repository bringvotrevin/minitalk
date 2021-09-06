/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:54:38 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:54:10 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_buffer;
	unsigned int	i;

	if (!(s && f))
		return (NULL);
	s_buffer = malloc(sizeof(char) * (ft_strlen((char *)s)) + 1);
	if (!s_buffer)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_buffer[i] = f(i, s[i]);
		i++;
	}
	s_buffer[i] = '\0';
	return (s_buffer);
}
