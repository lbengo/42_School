/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:28:44 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/19 13:38:23 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Cost of moving a number in stack A. From the middle of the stack up it is
positive and from the middle of the stack down it is negative. Used to know
if whether to use "rotate" or "rotate backwards". */
int	cost_in_a(t_lst *lst, int nbr)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (lst != NULL)
	{
		if (lst->data == nbr)
			break ;
		i++;
		lst = lst->next;
	}
	if (i > len / 2)
		i = i - len;
	return (i);
}

/* Cost of moving a number in stack B. From the middle of the stack up it is
positive and from the middle of the stack down it is negative. Used to know
if whether to use "rotate" or "rotate backwards". */
int	cost_to_b(t_lst *lst, int nbr)
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
		if ((nbr == min && lst->data == max) \
		|| (pre->data > nbr && nbr > lst->data))
			break ;
		i++;
		if (nbr == max && lst->data == min)
			break ;
		pre = lst;
		lst = lst->next;
	}
	if (i > len / 2)
		i = i - len;
	return (i);
}

/* Cost of moving b number in stack A. From the middle of the stack up it is
positive and from the middle of the stack down it is negative. Used to know
if whether to use "rotate" or "rotate backwards". */
int	cost_to_a(t_lst *lst, int nbr)
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
		if ((nbr == max && lst->data == min) \
		|| (pre->data < nbr && nbr < lst->data))
			break ;
		i++;
		if (nbr == min && lst->data == max)
			break ;
		pre = lst;
		lst = lst->next;
	}
	if (i > len / 2)
		i = i - len;
	return (i);
}

// Sum of the costs
void	total_cost(t_lst *lst)
{
	int		cost_a;
	int		cost_b;

	while (lst != NULL)
	{
		cost_a = lst->cost_a;
		cost_b = lst->cost_b;
		if ((cost_a < 0 && 0 < cost_b) || (cost_a > 0 && 0 > cost_b))
		{
			cost_a = change_positive(cost_a);
			cost_b = change_positive(cost_b);
			lst->count = cost_a + cost_b;
		}
		else
		{
			cost_a = change_positive(cost_a);
			cost_b = change_positive(cost_b);
			if (cost_a > cost_b)
				lst->count = cost_a;
			else
				lst->count = cost_b;
		}
		lst = lst->next;
	}
}
