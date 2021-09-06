/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:53:35 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:07:40 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_julemojalla(char *buffer, int num, int minus)
{
	size_t	i;

	i = 10;
	if (minus)
		num *= -1;
	while (num > 0)
	{
		buffer[i--] = "0123456789"[num % 10];
		num /= 10;
	}
	if (minus)
		buffer[i] = '-';
	i = 0;
	while (buffer[i] == '\0')
		i++;
	return (ft_strdup(buffer + i));
}

char	*ft_itoa(int num)
{
	const int	minus = (num < 0);
	char		buffer[12];
	int			i;

	if (num == 0)
		return (ft_strdup("0"));
	i = 0;
	while (i < 12)
		buffer[i++] = '\0';
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (itoa_julemojalla(buffer, num, minus));
}
