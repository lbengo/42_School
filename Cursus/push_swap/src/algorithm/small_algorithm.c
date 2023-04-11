/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:13 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/11 17:39:07 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Algorithm for 3 numbers
void	three_nbr(t_lst **lst)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*third;

	while(check_order(lst, 'a') == 1)
	{
		first = (*lst);
		second = (*lst)->next;
		third = second->next;
		if (first->content > second->content && first->content < third->content)
			swap_a(lst);
		else if (first->content > second->content && first->content > third->content)
			rotate_a(lst);
		else if (first->content < second->content && first->content > third->content)
			reverse_rotate_a(lst);
		else if (first->content < second->content && first->content < third->content)
			swap_a(lst);
	}
}

// Algorithm for 5 numbers
void	five_nbr(t_lst **lst_a, t_lst **lst_b)
{
	lst_a = NULL;
	lst_b = NULL;
	printf("start\n");
}
