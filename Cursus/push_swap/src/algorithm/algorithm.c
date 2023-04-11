/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:16:33 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/11 17:37:42 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Finds the cost of moving each number in both list_a and list_b, and saves
the result value */
static void	find_moves(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*stack_a;
	t_lst	*curr;
	int		move_top;
	int		move_b;

	stack_a = *lst_a;
	while (stack_a != NULL)
	{
		stack_a->move_top = find_move_top(*lst_a, stack_a->content);
		stack_a->move_b = find_move_b(*lst_b, stack_a->content);
		stack_a = stack_a->next;
	}
	curr = *lst_a;
	while (curr != NULL)
	{
		move_top = curr->move_top;
		move_b = curr->move_b;
		if (move_top < 0)
			move_top = move_top * (-1);
		if (move_b < 0)
			move_b = move_b * (-1);
		curr->count = move_top + move_b;
		curr = curr->next;
	}
}

// Selects which number requires fewer moves and passes them to list_b
static void	select_and_move(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *curr;
	t_lst *select;

	curr = *lst_a;
	select = curr;
	while (curr != NULL)
	{
		if(select->count > curr->count)
			select = curr;
		curr = curr->next;
	}
	move_lst(lst_a, lst_b, select->move_top, 'a');
	move_lst(lst_a, lst_b, select->move_b, 'b');
	push_b(lst_a, lst_b);
}

// Sorts list_b and sends it to list_a
static void	push_to_a(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *curr;
	int len;
	int i;

	i = 0;
	curr = *lst_b;
	len = ft_lstsize(curr);
	while (curr != NULL)
	{
		if (curr->content == (check_max_min(curr, curr->content, 'M')))
			break;
		i++;
		curr = curr->next;
	}
	while (check_order(lst_b, 'b') == 1)
	{
		if (i > len/2)
			reverse_rotate_b(lst_b);
		else
			rotate_b(lst_b);
	}
	while (len-- > 0)
		push_a(lst_a, lst_b);

}

// Detect how many numbers there are and choose which algorithm to use.
void	algorithm(t_lst **lst_a, t_lst **lst_b)
{
	int	len;

	*lst_b = NULL;
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
	{
		while (*lst_a != NULL)
		{
			find_moves(lst_a, lst_b);
			select_and_move(lst_a, lst_b);
		}
		push_to_a(lst_a, lst_b);
	}
}
