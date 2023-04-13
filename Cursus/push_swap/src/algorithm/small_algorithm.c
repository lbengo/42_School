/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:13 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 09:37:47 by lbengoec         ###   ########.fr       */
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

static int	cost2a(t_lst *lst, int nbr)
{
	t_lst	*pre;
	int		max;
	int		min;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(lst);
	pre = ft_lstlast(lst);
	max = check_max_min(lst, nbr, 'M');
	min = check_max_min(lst, nbr, 'm');
	while (lst != NULL)
	{
		if ((nbr == max && lst->content == min) \
		|| (pre->content < nbr && nbr < lst->content))
			break ;
		i++;
		if (nbr == min && lst->content == max)
			break;
		pre = lst;
		lst = lst->next;
	}
	if (i > len / 2)
		i = i - len;
	return (i);
}

static void	order_lst(t_lst **lst, int i)
{
	while (i != 0)
	{
		if (i > 0)
		{
			rotate_a(lst);
			i--;
		}
		else if (i < 0)
		{
			reverse_rotate_a(lst);
			i++;
		}
	}
}

static void	send2a(t_lst **lst_a, t_lst **lst_b)
{
	int i;

	i = cost2a(*lst_a, (*lst_b)->content);
	order_lst(lst_a, i);
	push_a(lst_a, lst_b);
}

// Algorithm for 5 numbers
void	five_nbr(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *curr;
	int i;

	push_b(lst_a, lst_b);
	push_b(lst_a, lst_b);
	three_nbr(lst_a);
	send2a(lst_a, lst_b);
	send2a(lst_a, lst_b);
	curr = *lst_a;
	i = 0;
	while (curr->content != check_max_min(*lst_a, (*lst_a)->content, 'm'))
	{
		i++;
		curr = curr->next;
	}

	order_lst(lst_a, i);
}
