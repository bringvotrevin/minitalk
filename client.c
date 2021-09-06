/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:06:05 by dim               #+#    #+#             */
/*   Updated: 2021/08/30 17:09:25 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sighandler(int signum, siginfo_t *newact, void *oldact)
{
	
}

int		main(void)
{
	struct sigaction	sigact;

	sigcat.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	while (1)
		pause();
	return (0);
}
