/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 07:29:35 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/03/29 08:32:20 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push - toma el primer elemento de la lista y lo situa encima de la otra.
static void push(t_lst **lst, t_lst **dest)
{
	t_lst *curr;

	curr = *lst;
	*lst = (*lst)->next;
	curr->next = *dest;
	*dest = curr;
}

// push a - toma el primer elemento de la lista b y lo situa encima de la a.
void push_a(t_lst **lst_a, t_lst **lst_b)
{
	push(lst_b, lst_a);
	write(1, "pa", 1);
}

// push b - toma el primer elemento de la lista a y lo situa encima de la b.
void push_a(t_lst **lst_a, t_lst **lst_b)
{
	push(lst_a, lst_b);
	write(1, "pb", 1);
}