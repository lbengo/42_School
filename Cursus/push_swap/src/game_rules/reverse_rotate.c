/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:12:17 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/04/13 12:57:35 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* reverse_rotate - el último elemento de la lista pasa al primero.
Ej: 1234 -> 4123 */
void	reverse_rotate(t_lst **lst)
{
	t_lst	*penultimate;
	t_lst	*curr;

	penultimate = ft_lstpenultimate(*lst);
	curr = ft_lstlast(*lst);
	curr->next = *lst;
	*lst = curr;
	penultimate->next = NULL;
}

// reverse_rotate a - el último elemento de la lista a pasa al primero.
void	reverse_rotate_a(t_lst **lst_a)
{
	reverse_rotate(lst_a);
	ft_putstr("rra\n");
}

// reverse_rotate b - el último elemento de la lista a pasa al primero.
void	reverse_rotate_b(t_lst **lst_b)
{
	reverse_rotate(lst_b);
	ft_putstr("rrb\n");
}

// reverse_rotate a y b - los últimos elementos de las listas a pasan al primero.
void	reverse_rotate_a_b(t_lst **lst_a, t_lst **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	ft_putstr("rrr\n");
}
