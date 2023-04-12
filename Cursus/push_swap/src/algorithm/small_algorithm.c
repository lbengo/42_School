/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:13 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/12 16:43:15 by laurabengoe      ###   ########.fr       */
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

/* static int	find_space(t_lst *lst_a, t_lst *lst_b)
{
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(lst_a);
	while (lst_a != NULL)
	{
		if (lst_b->content < lst_a->content)
			break;
		i++;
		lst_a = lst_a->next;
	}
	if (i > len/2)
		i = i - len;
	return (i);
}

static void	order_lst_a(t_lst **lst)
{
	t_lst	*curr;
	int		len;
	int		i;

	i = 0;
	curr = *lst;
	len = ft_lstsize(curr);
	while (curr != NULL)
	{
		if (curr->content == (check_max_min(curr, curr->content, 'M')))
			break;
		i++;
		curr = curr->next;
	}
	while (check_order(lst, 'a') == 1)
	{
		if (i >= len/2)
			reverse_rotate_a(lst);
		else
			rotate_a(lst);
	}
}

static void	send_to_a(t_lst **lst_a, t_lst **lst_b)
{
	int i;

	i = find_space (*lst_a, *lst_b);
	while (i != 0)
	{
		if (i > 0)
		{
			rotate_a(lst_a);
			i--;
		}
		else if (i < 0)
		{
			reverse_rotate_a(lst_a);
			i++;
		}
	}
	push_a(lst_a, lst_b);
	order_lst_a(lst_a);
} */

/* static int	find_space(t_lst *lst_a, t_lst *lst_b)
{
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(lst_a);
	while (lst_a != NULL)
	{
		if (lst_b->content < lst_a->content)
			break;
		i++;
		lst_a = lst_a->next;
	}
	if (i > len/2)
		i = i - len;
	return (i);
} */

static void	send_to_a(t_lst **lst_a, t_lst **lst_b)
{
	int i;

	i = find_move_b(*lst_a, (*lst_b)->content);
	printf("content = %d\n", (*lst_b)->content);
	printf("i = %d\n\n", i);
	while (i != 0)
	{
		if (i > 0)
		{
			rotate_a(lst_a);
			i--;
		}
		else if (i < 0)
		{
			reverse_rotate_a(lst_a);
			i++;
		}
	}
	push_a(lst_a, lst_b);
}

// Algorithm for 5 numbers
void	five_nbr(t_lst **lst_a, t_lst **lst_b)
{
	push_b(lst_a, lst_b);
	push_b(lst_a, lst_b);
	three_nbr(lst_a);
	send_to_a(lst_a, lst_b);
	send_to_a(lst_a, lst_b);
}
