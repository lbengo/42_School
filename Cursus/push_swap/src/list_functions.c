/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:48:24 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/30 10:43:10 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

int	ft_lstsize(t_lst *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

t_lst *ft_lstpenultimate(t_lst *lst)
{
	t_lst *curr;
	t_lst *prev;

	if(!lst)
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

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
	new -> next = lst[0];
	lst[0] = new;
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
