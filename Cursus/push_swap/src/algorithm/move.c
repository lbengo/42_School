/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:19:51 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/19 13:38:25 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Execute list movements together
void	move_together(t_lst **lst_a, t_lst **lst_b, t_lst *curr)
{
	if ((curr->cost_a > 0 && curr->cost_b > 0))
	{
		while (curr->cost_a != 0 || curr->cost_b != 0)
		{
			if (curr->cost_a == 0 || curr->cost_b == 0)
				break ;
			rotate_a_b(lst_a, lst_b);
			curr->cost_a = curr->cost_a - 1;
			curr->cost_b = curr->cost_b - 1;
		}
	}
	else if ((curr->cost_a < 0 && curr->cost_b < 0))
	{
		while (curr->cost_a != 0 || curr->cost_b != 0)
		{
			if (curr->cost_a == 0 || curr->cost_b == 0)
				break ;
			reverse_rotate_a_b(lst_a, lst_b);
			curr->cost_a = curr->cost_a + 1;
			curr->cost_b = curr->cost_b + 1;
		}
	}
}

// Execute the list_a movements
void	move_a(t_lst **lst_a, int move_top)
{
	while (move_top != 0)
	{
		if (move_top > 0)
		{
			rotate_a(lst_a);
			move_top--;
		}
		if (move_top < 0)
		{
			reverse_rotate_a(lst_a);
			move_top++;
		}
	}
}

// Execute the list_b movements
void	move_b(t_lst **lst_b, int move_b)
{
	while (move_b != 0)
	{
		if (move_b > 0)
		{
			rotate_b(lst_b);
			move_b--;
		}
		if (move_b < 0)
		{
			reverse_rotate_b(lst_b);
			move_b++;
		}
	}
}
