/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:11:36 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/03/29 08:14:38 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* rotate a - desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último */
void rotate(t_lst **lst)
{
	t_lst *second_nbr;

	second_nbr = (*lst)->next;
	ft_lstlast(*lst)->next = *lst;
	(*lst)->next = NULL;
	(*lst) = second_nbr;
}