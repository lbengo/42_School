/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 07:29:35 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/03/29 07:29:37 by laurabengoe      ###   ########.fr       */
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