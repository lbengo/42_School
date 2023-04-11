/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:17:25 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/11 14:49:47 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Cost of moving a number in stack A. From the middle of the stack up it is
positive and from the middle of the stack down it is negative. Used to know
if whether to use "rotate" or "rotate backwards". */
int	find_move_top(t_lst *lst, int nbr)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (lst != NULL)
	{
		if (lst->content == nbr)
			break;
		i++;
		lst = lst->next;
	}
	if (i > len/2)
		i = i - len;
	return (i);
}

/* Cost of moving a number in stack B. From the middle of the stack up it is
positive and from the middle of the stack down it is negative. Used to know
if whether to use "rotate" or "rotate backwards". */
int	find_move_b(t_lst *lst, int nbr)
{
	t_lst	*next;
	int		max;
	int		min;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(lst);
	max = check_max_min(lst, nbr, 'M');
	min = check_max_min(lst, nbr, 'm');
	while (lst != NULL)
	{
		next = lst->next;
		if (nbr > lst->content && nbr < max)
			break;
		if (lst->content == max && nbr == min)
			break;
		i++;
		if ((nbr == max && !next) || (nbr == max && lst->content < next->content))
			break;
		lst = lst->next;
	}
	if (i > len/2)
		i = i - len;
	return(i);
}

/* Checks the order from smallest to largest (a) or from largest to smallest (b)
 of a list. */
int	check_order(t_lst **lst, char c)
{
	t_lst *curr;
	t_lst *next;

	curr = *lst;
	next = (*lst)->next;
	while(next != NULL)
	{
		if(curr->content > next->content && c == 'a')
			return(1);
		if(curr->content < next->content && c == 'b')
			return(1);
		curr = curr->next;
		next = next->next;
	}
	return(0);
}

// Sends the smallest or largest value in a list
int	check_max_min(t_lst *lst, int nbr, char c)
{
	int max;
	int min;

	max = nbr;
	min = nbr;
	while (lst != NULL)
	{
		if (max < lst->content)
			max = lst->content;
		if (min > lst->content)
			min = lst->content;
		lst = lst->next;
	}
	if (c == 'M')
		return (max);
	return (min);
}

// Executes the movements of the lists
void	move_lst(t_lst **lst_a, t_lst **lst_b, int move, char c)
{
	while (move != 0)
	{
		if (move > 0)
		{
			if (c == 'a')
				rotate_a(lst_a);
			else if (c == 'b')
				rotate_b(lst_b);
			move--;
		}
		else if (move < 0)
		{
			if (c == 'a')
				reverse_rotate_a(lst_a);
			else if (c == 'b')
				reverse_rotate_b(lst_b);
			move++;
		}
	}
}
