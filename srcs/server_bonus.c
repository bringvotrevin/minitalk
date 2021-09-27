/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:33:12 by dim               #+#    #+#             */
/*   Updated: 2021/09/25 18:17:16 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

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
}

int	main(int argc, char *argv[])
{
	struct sigaction	sigact;

	(void)argv;
	if (argc > 1)
		ft_error("too many arguments\n");
	ft_putstr("[server pid : ");
	ft_putnbr(getpid());
	ft_putstr("]\n");
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		ft_error("sigaction error\n");
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
		ft_error("sigaction error\n");
	while (1)
		pause();
	return (0);
}
