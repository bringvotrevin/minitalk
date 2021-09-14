/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:09:43 by dim               #+#    #+#             */
/*   Updated: 2021/09/15 06:16:57 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	ft_sighandler(int signum, siginfo_t *siginfo, void *non)
{
	static int				bitnum = 0;
	static unsigned char	bit = 0b00000000;

	(void)siginfo;
	(void)non;
	if (signum == SIGUSR1)
		bit += 1 << (7 - bitnum);
	bitnum++;
	if (bitnum == 8)
	{
		if (bit == '\0')
			ft_putchar('\n');
		ft_putchar(bit);
		bitnum = 0;
		bit = 0b00000000;
	}
	usleep(1000);
}

int		main(void)
{
	struct sigaction	sigact;

	ft_putstr("[server pid : ");
	ft_putnbr(getpid());
	ft_putstr("]\n");
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		ft_error("error");
	if (sigaction(SIGUSR2, &sigact, NULL) == -1);
		ft_error("error");
	while (1)
		pause();
	return (0);
}
