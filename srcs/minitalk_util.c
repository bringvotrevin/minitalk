/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 06:27:06 by dim               #+#    #+#             */
/*   Updated: 2021/09/15 16:39:31 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
			|| c == '\r' || c == '\f' || c == ' ');
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int		ft_atoi(char *str)
{
	int		nbr;

	nbr = 0;
	while (ft_isspace(*str) != 0)
		str++;
	if (*str == '+')
		str++;
	while (ft_isdigit(*str) != 0)
	{
		nbr = (nbr * 10) + *str - '0';
		str++;
	}
	return (nbr);
}

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
	int i;
	
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
