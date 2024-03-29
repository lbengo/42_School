/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:37:01 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/19 13:38:14 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks the order from smallest to largest (a) or from largest to smallest (b)
 of a list. */
int	check_order(t_lst **lst, char c)
{
	t_lst	*curr;
	t_lst	*next;

	curr = *lst;
	next = (*lst)->next;
	while (next != NULL)
	{
		if (curr->data > next->data && c == 'a')
			return (1);
		if (curr->data < next->data && c == 'b')
			return (1);
		curr = curr->next;
		next = next->next;
	}
	return (0);
}

// Sends the smallest or largest value in a list
int	check_max_min(t_lst *lst, int nbr, char c)
{
	int	max;
	int	min;

	max = nbr;
	min = nbr;
	while (lst != NULL)
	{
		if (max < lst->data)
			max = lst->data;
		if (min > lst->data)
			min = lst->data;
		lst = lst->next;
	}
	if (c == 'M')
		return (max);
	return (min);
}

void	send_to_a(t_lst **lst_a, t_lst **lst_b)
{
	int		i;

	while (*lst_b != NULL)
	{
		i = cost_to_a(*lst_a, (*lst_b)->data);
		move_a(lst_a, i);
		push_a(lst_a, lst_b);
	}
}

void	order_a(t_lst **lst_a)
{
	t_lst	*curr;
	int		len;
	int		i;

	curr = *lst_a;
	len = ft_lstsize(*lst_a);
	i = 0;
	while (curr->data != check_max_min(*lst_a, (*lst_a)->data, 'm'))
	{
		i++;
		curr = curr->next;
	}
	if (i > len / 2)
		i = i - len;
	move_a(lst_a, i);
}

void	order_b(t_lst **lst_b)
{
	t_lst	*curr;
	int		len;
	int		i;

	curr = *lst_b;
	len = ft_lstsize(*lst_b);
	i = 0;
	while (curr->data != check_max_min(*lst_b, (*lst_b)->data, 'M'))
	{
		i++;
		curr = curr->next;
	}
	if (i > len / 2)
		i = i - len;
	move_b(lst_b, i);
}
