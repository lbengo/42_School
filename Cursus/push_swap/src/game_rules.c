/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 07:15:08 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/03/29 07:17:32 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa : swap a - intercambia los dos primeros elementos encima del stack a. No hace
nada si hay uno o menos elementos */
void swap_a(t_lst **lst)
{
	t_lst *second_nbr;
	
	second_nbr = (*lst)->next;
	(*lst)->next = second_nbr->next;
	second_nbr->next = *lst;
	*lst = second_nbr;
}

/* rotate a - desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último */
void rotate_a(t_lst **lst)
{
	t_lst *second_nbr;

	second_nbr = (*lst)->next;
	ft_lstlast(*lst)->next = *lst;
	(*lst)->next = NULL;
	(*lst) = second_nbr;
}

/* push b - toma el primer elemento del stack a y lo pone encima del stack b. */
void push_b(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *curr;

	curr = *lst_a;
	*lst_a = (*lst_a)->next;
	curr->next = *lst_b;
	*lst_b = curr;
}

/* reverse rotate a - desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero. */
void reverse_rotate_a(t_lst **lst)
{
	t_lst *penultimate;
	t_lst *curr;

	penultimate = ft_lstpenultimate(*lst);
	curr = ft_lstlast(*lst);
	curr->next = *lst;
	*lst = curr;
	penultimate->next = NULL;
}