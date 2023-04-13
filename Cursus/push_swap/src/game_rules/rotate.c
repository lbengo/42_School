/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:11:36 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/04/13 12:57:15 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rotate - el primer elemento de la lista pasa al último. Ej: 1234 -> 2341
static void	rotate(t_lst **lst)
{
	t_lst	*second_nbr;

	second_nbr = (*lst)->next;
	ft_lstlast(*lst)->next = *lst;
	(*lst)->next = NULL;
	(*lst) = second_nbr;
}

// rotate a - el primer elemento de la lista a pasa al último.
void	rotate_a(t_lst **lst_a)
{
	rotate(lst_a);
	ft_putstr("ra\n");
}

// rotate b - el primer elemento de la lista b pasa al último.
void	rotate_b(t_lst **lst_b)
{
	rotate(lst_b);
	ft_putstr("rb\n");
}

// rotate a y b - los primeros elementos de la lista a y b pasan al último.
void	rotate_a_b(t_lst **lst_a, t_lst **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	ft_putstr("rr\n");
}
