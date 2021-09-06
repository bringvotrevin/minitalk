/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 01:15:26 by dher              #+#    #+#             */
/*   Updated: 2021/02/04 03:13:26 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_buffer;

	if (lst)
	{
		while (*lst)
		{
			lst_buffer = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lst_buffer;
		}
	}
	*lst = NULL;
}
