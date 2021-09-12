/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:06:05 by dim               #+#    #+#             */
/*   Updated: 2021/09/12 13:51:10 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sighandler(int signum, siginfo_t *siginfo, void *non)
{
	
}

int		main(int argc, char *argv[])
{
	struct sigaction	sigact;
	int					serverpid;
	char				*msg;

	if (argc != 3)
		return (0);
	serverpid = ft_atoi(argv[1]);
	msg = argv[2];
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
