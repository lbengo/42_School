/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/04 14:45:43 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Si el primer número es mayor que todos los de la lista lo cambia a la lista B. Ej: 431(lista a). -> 31(lista a) 4(lista b)
//Si no, lo rota al último de la misma lista. Ej: 143 -> 431

/* static void	find_move_top(t_lst **lst_a)
{
	t_lst *curr;
	int	len;
	int	i;
	int	a;

	i = 0;
	curr = *lst_a;
	len = ft_lstsize(*lst_a);
	while (i <= len/2)
	{
		curr->move_top = i++;
		curr = curr->next;
	}
	a = (len/2);
	while (i++ < len)
	{
		curr->move_top = (--a) * (-1);
		curr = curr->next;
	}
}

static int	max_min_nbr(t_lst **lst, int nbr)
{

}

static int	find_nbr_b(t_lst **lst, int nbr)
{
	t_lst	*curr;
	t_lst	*next;
	int		i;

	i = 0;
	while (curr != NULL)
	{
		curr = *lst;
		next = (*lst)->next;
		//if (max_min_nbr(lst, nbr) == 1)
			//break;
		if (nbr > curr->content && nbr < next->content)
			break;
		i++;
		curr = curr->next;
	}
	return (i);
} */

static int	space_in_lst(t_lst *lst, t_lst *nbr)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		if (lst->content == nbr->content)
			return (i);
		i++;
		lst = lst->next;
	}
	return (i);
}

static int	find_move_top(t_lst *lst, t_lst *nbr)
{
	t_lst *curr;
	int	len;
	int	i;

	curr = lst;
	len = ft_lstsize(lst);
	i = space_in_lst(lst, nbr);
	if (i >= len/2)
		i = i - len;
	return (i);
}

static void	find_moves(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *stack_a;

	lst_b = NULL;
	stack_a = *lst_a;
	while (stack_a != NULL)
	{
		stack_a->move_top = find_move_top(*lst_a, stack_a);
		//stack_a->move_b = find_nbr_b(lst_b, stack_a->content);
		stack_a = stack_a->next;
	}
}

static int	check_order(t_lst **lst)
{
	t_lst *curr;
	t_lst *next;

	curr = *lst;
	next = (*lst)->next;
	while(next != NULL)
	{
		if(curr->content > next->content)
			return(1);
		curr = curr->next;
		next = next->next;
	}
	return(0);
}

// 3 numbers
static void	small_nbr(t_lst **lst)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*third;

	while(check_order(lst) == 1)
	{
		first = (*lst);
		second = (*lst)->next;
		third = second->next;
		if (first->content > second->content && first->content < third->content)
			swap_a(lst);
		if (first->content > second->content && first->content > third->content)
			rotate_a(lst);
		if (first->content < second->content && first->content > third->content)
			reverse_rotate_a(lst);
		if (first->content < second->content && first->content < third->content)
			swap_a(lst);
	}
}

static void	move_lst(t_lst **lst_a, t_lst **lst_b)
{
	int	len;

	*lst_b = NULL;
	len = ft_lstsize(*lst_a);
	if (len == 2 && check_order(lst_a) == 1)
		swap_a(lst_a);
	else if (len == 3)
		small_nbr(lst_a);
	else
	{
		find_moves(lst_a, lst_b);
		//find_move_b(&lst_a, &lst_b);
	}
}

int	main(int argc, char *argv[])
{
	t_lst	*lst_a;
	t_lst	*lst_b;

	lst_a = add_to_lst(--argc, ++argv);
	if (argc == 1 || !lst_a)
	{
		printf("Error\nAdd a number");
		return (0);
	}

	lst_b = NULL;
	check_duplicate(lst_a);
	move_lst(&lst_a, &lst_b);

	//Comprobación de lista
	t_lst *curr;

	curr = lst_a;
	while (curr != NULL)
	{
		printf("lista = %d\n", curr->content);
		printf("top = %d\n", curr->move_top);
		curr = curr -> next;
	}

/* 	//rotación y comprobación de lista
	swap_a(&lst_a);

	t_lst *curr_a;

	curr_a = lst_a;
	while (curr_a) {
		printf("\naaaaaaaaa = %d", curr_a->content);
		curr_a = curr_a->next;
	}

	t_lst *curr_b;

	curr_b = lst_b;
	while (curr_b) {
		printf("bbbbb = %d\n", curr_b->content);
		curr_b = curr_b->next;
	} */

	//Free de la lista
	deallocate(&lst_a);
	deallocate(&lst_b);

	return(0);
}
