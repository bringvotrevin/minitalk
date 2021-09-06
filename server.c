/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:09:43 by dim               #+#    #+#             */
/*   Updated: 2021/08/29 04:40:49 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		main(int argc, char *argv[])
{
	struct sigaction	sigact;

	if (argc > 1)
		return (0);
	ft_putstr("server pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_handler;
	while (1)
		pause();
	return (0);
}
