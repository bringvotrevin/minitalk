/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:59:20 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:12:45 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_julemojalla(char *buffer, int num, int minus, int fd)
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
	ft_putstr_fd(buffer + i, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	const int	minus = (nb < 0);
	char		buffer[12];
	int			i;

	if (nb == 0)
	{
		ft_putstr_fd("0", fd);
		return ;
	}
	i = 0;
	while (i < 12)
		buffer[i++] = '\0';
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else
	{
		itoa_julemojalla(buffer, nb, minus, fd);
		return ;
	}
}
