/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:06:05 by dim               #+#    #+#             */
/*   Updated: 2021/09/12 19:08:51 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(1000);
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

}

int		main(int argc, char *argv[])
{
	struct sigaction	sigact;
	int					server_pid;

	if (argc != 3)
		return (0);
	server_pid = ft_atoi(argv[1]);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		ft_error("error");
	if (sigaction(SIGUSR2, &sigact, NULL) == -1);
		ft_error("error");
	to_server(server_pid, argv[2]);
	while (1)
		pause();
	return (0);
}
