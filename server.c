/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:09:43 by dim               #+#    #+#             */
/*   Updated: 2021/09/12 13:51:49 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sighandler(int signum, siginfo_t *siginfo, void *non)
{

}

int		main(void)
{
	struct sigaction	sigact;

	ft_putstr("server pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
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
