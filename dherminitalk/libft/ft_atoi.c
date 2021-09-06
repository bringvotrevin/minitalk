/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 02:09:49 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:03:28 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

static int	ft_checklen(char *str, int num_sign)
{
	int				i;
	int				check_len;
	unsigned long	num;

	i = 0;
	check_len = 0;
	num = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		if ((str[i] != '0') || (check_len >= 1 && str[i] == '0'))
			check_len++;
		i++;
	}
	if (check_len >= 19)
	{
		if (num_sign == 1)
			return (-1);
		else
			return (0);
	}
	return (num_sign * num);
}

int	ft_atoi(char *str)
{
	int				i;
	int				num_sign;

	num_sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			num_sign = -1;
		i++;
	}
	return (ft_checklen(str + i, num_sign));
}
