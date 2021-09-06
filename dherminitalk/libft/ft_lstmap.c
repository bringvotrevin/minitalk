/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 03:20:06 by dher              #+#    #+#             */
/*   Updated: 2021/07/07 00:08:44 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*lst_copy;
	t_list			*lst_new;

	if (!f)
		return (NULL);
	lst_copy = NULL;
	while (lst)
	{
		lst_new = ft_lstnew(f(lst->content));
		if (!lst_new)
		{
			ft_lstclear(&lst_copy, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_copy, lst_new);
		lst = lst->next;
	}
	return (lst_copy);
}
