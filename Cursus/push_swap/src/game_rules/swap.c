/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 07:29:35 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/03/30 10:18:23 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* swap - intercambia los dos primeros elementos de la lista. No hace nada si
hay uno o menos elementos. Ej: 1234 -> 2134 */
static void swap(t_lst **lst)
{
	t_lst *second_nbr;

	second_nbr = (*lst)->next;
	(*lst)->next = second_nbr->next;
	second_nbr->next = *lst;
	*lst = second_nbr;
}

// swap a - intercambia los dos primeros elementos encima de la lista a.
void swap_a(t_lst **lst_a)
{
	swap(lst_a);
	ft_putstr("sa\n");
}

// swap b - intercambia los dos primeros elementos encima de la lista b.
void swap_b(t_lst **lst_b)
{
	swap(lst_b);
	ft_putstr("sb\n");
}

// swap a y b - hace swap de la lista a y b a la vez.
void swap_a_b(t_lst **lst_a, t_lst **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	ft_putstr("ss\n");
}
