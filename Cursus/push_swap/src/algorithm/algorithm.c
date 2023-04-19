/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:16:33 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/19 13:38:18 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Algorithm for 3 numbers
static void	three_nbr(t_lst **lst)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*third;

	while (check_order(lst, 'a') == 1)
	{
		first = (*lst);
		second = (*lst)->next;
		third = second->next;
		if (first->data > second->data && first->data < third->data)
			swap_a(lst);
		else if (first->data > second->data && first->data > third->data)
			rotate_a(lst);
		else if (first->data < second->data && first->data > third->data)
			reverse_rotate_a(lst);
		else if (first->data < second->data && first->data < third->data)
			swap_a(lst);
	}
}

// Algorithm for 5 numbers
static void	five_nbr(t_lst **lst_a, t_lst **lst_b)
{
	push_b(lst_a, lst_b);
	push_b(lst_a, lst_b);
	three_nbr(lst_a);
	send_to_a(lst_a, lst_b);
	order_a(lst_a);
}

// Algorithm for big numbers
static void	big_nbr(t_lst **lst_a, t_lst **lst_b)
{
	while (*lst_a != NULL)
	{
		find_moves(lst_a, lst_b);
		select_and_move(lst_a, lst_b);
	}
	push_to_a(lst_a, lst_b);
}

// Detect how many numbers there are and choose which algorithm to use.
void	algorithm(t_lst **lst_a, t_lst **lst_b)
{
	int	len;

	len = ft_lstsize(*lst_a);
	if (check_order(lst_a, 'a') == 0)
		exit (0);
	if (len == 2)
		swap_a(lst_a);
	else if (len == 3)
		three_nbr(lst_a);
	else if (len == 5)
		five_nbr(lst_a, lst_b);
	else
		big_nbr(lst_a, lst_b);
}
