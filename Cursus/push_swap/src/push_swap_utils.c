/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:48:24 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/23 11:38:49 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)-> next = new;
}

void deallocate(t_lst **lst_1)
{
	t_lst *curr;
	t_lst *aux;

	curr = *lst_1;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr -> next;
		free(aux);
	}
	*lst_1 = NULL;
}
