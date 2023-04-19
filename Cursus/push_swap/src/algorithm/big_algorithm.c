/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:28:10 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/19 13:38:20 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts list_b and sends it to list_a
void	push_to_a(t_lst **lst_a, t_lst **lst_b)
{
	int		len;

	order_b(lst_b);
	len = ft_lstsize(*lst_b);
	while (len-- > 0)
		push_a(lst_a, lst_b);
}

// Selects which number requires fewer moves and passes them to list_b
void	select_and_move(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*curr;
	t_lst	*select;

	curr = *lst_a;
	select = curr;
	while (curr != NULL)
	{
		if (select->count > curr->count)
			select = curr;
		curr = curr->next;
	}
	move_together(lst_a, lst_b, select);
	move_a(lst_a, select->cost_a);
	move_b(lst_b, select->cost_b);
	push_b(lst_a, lst_b);
}

// Finds the cost of moving each number in both list_a and list_b
void	find_moves(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*curr;

	curr = *lst_a;
	while (curr != NULL)
	{
		curr->cost_a = cost_in_a(*lst_a, curr->data);
		curr->cost_b = cost_to_b(*lst_b, curr->data);
		curr = curr->next;
	}
	total_cost(*lst_a);
}

int	change_positive(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}
