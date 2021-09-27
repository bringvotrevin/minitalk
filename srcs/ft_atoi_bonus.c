/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:31:57 by dim               #+#    #+#             */
/*   Updated: 2021/09/25 18:18:01 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f' || c == ' ');
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int	ft_atoi(char *str)
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
