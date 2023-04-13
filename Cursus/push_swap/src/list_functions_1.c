/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:00:47 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:03:17 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew(int data)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (0);
	new -> data = data;
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

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
	new -> next = lst[0];
	lst[0] = new;
}

void	deallocate(t_lst **lst_1)
{
	t_lst	*curr;
	t_lst	*aux;

	curr = *lst_1;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr -> next;
		free(aux);
	}
	*lst_1 = NULL;
}
