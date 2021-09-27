/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_util_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:32:22 by dim               #+#    #+#             */
/*   Updated: 2021/09/25 18:17:11 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	ft_putnbr(int nbr)
{
	char			c;
	unsigned int	num;

	if (nbr < 0)
	{
		write(1, "-", 1);
		num = nbr * -1;
	}
	else
		num = nbr;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_error(char *str)
{
	if (str != NULL)
		ft_putstr(str);
	exit(1);
}
