/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:12:17 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/03/29 08:12:43 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* reverse rotate a - desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero. */
void reverse_rotate(t_lst **lst)
{
	t_lst *penultimate;
	t_lst *curr;

	penultimate = ft_lstpenultimate(*lst);
	curr = ft_lstlast(*lst);
	curr->next = *lst;
	*lst = curr;
	penultimate->next = NULL;
}