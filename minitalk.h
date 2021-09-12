/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 06:28:41 by dim               #+#    #+#             */
/*   Updated: 2021/09/11 06:32:49 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>

void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_error(char *str);

#endif