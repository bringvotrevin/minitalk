/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:15:59 by dim               #+#    #+#             */
/*   Updated: 2021/09/25 18:16:54 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	send_msg(int server_pid, char bit_msg)
{
	unsigned char	bit;
	int				count;

	count = 8;
	bit = 0b10000000;
	while (count--)
	{
		if (bit & bit_msg)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit >>= 1;
		usleep(100);
	}
}

void	to_server(int server_pid, char *msg)
{
	while (*msg)
	{
		send_msg(server_pid, *msg);
		msg++;
	}
	send_msg(server_pid, 0);
}

void	ft_sighandler(int signum, siginfo_t *siginfo, void *non)
{
	(void)signum;
	(void)siginfo;
	(void)non;
}

int	main(int argc, char *argv[])
{
	struct sigaction	sigact;
	int					server_pid;

	if (argc != 3)
		ft_error("argc error\n");
	server_pid = ft_atoi(argv[1]);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		ft_error("sigaction error\n");
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
		ft_error("sigaction error\n");
	to_server(server_pid, argv[2]);
	return (0);
}
