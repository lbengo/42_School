/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:48:24 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:03:25 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

t_lst	*ft_lstpenultimate(t_lst *lst)
{
	t_lst	*curr;
	t_lst	*prev;

	if (!lst)
		return (0);
	prev = lst;
	while (prev->next != NULL)
	{
		curr = prev;
		prev = prev->next;
	}
	return (curr);
}

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)-> next = new;
}
