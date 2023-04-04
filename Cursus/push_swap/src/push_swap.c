/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/04 18:22:42 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Si el primer número es mayor que todos los de la lista lo cambia a la lista B. Ej: 431(lista a). -> 31(lista a) 4(lista b)
//Si no, lo rota al último de la misma lista. Ej: 143 -> 43

static int	find_move_top(t_lst *lst, t_lst *nbr)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (lst != NULL)
	{
		if (lst->content == nbr->content)
			break;
		i++;
		lst = lst->next;
	}
	if (i > len/2)
		i = i - len;
	return (i);
}

/* static int	find_move_b(t_lst *lst, t_lst *nbr)
{
	t_lst *next;
	int len;
	int i;

	i = 0;
	printf("aaaa\n");
	len = ft_lstsize(lst);
	while (lst != NULL)
	{
		next = lst->next;
		if (lst->content > nbr->content && lst->content < next->content)
			break;
		i++;
		lst = lst->next;
	}
	if (i >= len/2)
		i = i - len;
	return (i);
} */

static void	find_moves(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*stack_a;
	t_lst	*curr;
	int		move_top;
	int		move_b;

	lst_b = NULL;
	stack_a = *lst_a;
	while (stack_a != NULL)
	{
		stack_a->move_top = find_move_top(*lst_a, stack_a);
		//printf("lista = %d\n", stack_a->content);
		//printf("top = %d\n", stack_a->move_top);
		//printf("b = %d\n", stack_a->move_b);
		//stack_a->move_b = find_move_b(*lst_b, stack_a); //es aquiiii el errorsitoo
		//printf("aaaa\n");
		stack_a = stack_a->next;
	}
	curr = *lst_a;
	while (curr != NULL)
	{
		move_top = curr->move_top;
		move_b = curr->move_b;

		if (move_top < 0)
			move_top = move_top * (-1);
		if (move_b < 0)
			move_b = move_b * (-1);
		curr->count = move_top + move_b;
		/* printf("lista = %d\n", curr->content);
		printf("top = %d\n", curr->move_top);
		printf("b = %d\n", curr->move_b);
		printf("count = %d\n\n", curr->count); */
		curr = curr->next;
	}
}

static void	select_and_move(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *curr;
	t_lst *select;

	curr = *lst_a;
	select = curr;
	while (curr != NULL)
	{
		if(select->count > curr->count)
			select = curr;
		curr = curr->next;
	}
/* 	while (select->move_top < 0)
	{
		ra....
	} */
	/* printf("aaaaaa =%d\n", select->content);
	printf("move_top =%d\n", select->move_top);
	printf("move_b =%d\n", select->move_b); */
	push_b(lst_a, lst_b);

}

// --------------------------------------------------------------------------------
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
		else if (first->content > second->content && first->content > third->content)
			rotate_a(lst);
		else if (first->content < second->content && first->content > third->content)
			reverse_rotate_a(lst);
		else if (first->content < second->content && first->content < third->content)
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
	else if (len > 3)
	{
		find_moves(lst_a, lst_b);
		select_and_move(lst_a, lst_b);
	}
}

int	main(int argc, char *argv[])
{
	t_lst	*lst_a;
	t_lst	*lst_b;

	lst_a = add_to_lst(--argc, ++argv);
	lst_b = NULL;
	if (argc == 0 || !lst_a)
	{
		printf("Error\nAdd a number\n");
		return (0);
	}
	check_duplicate(lst_a);
	move_lst(&lst_a, &lst_b);

	//Comprobación de lista
/* 	t_lst *curr;

	curr = lst_a;
	while (curr != NULL)
	{
		printf("lista = %d\n", curr->content);
		printf("top = %d\n", curr->move_top);
		//printf("top = %d\n", curr->move_b);
		curr = curr -> next;
	} */

	// comprobación de 2 listas
	t_lst *curr_a;

	curr_a = lst_a;
	while (curr_a) {
		printf("aaaaaaaaa = %d\n", curr_a->content);
		curr_a = curr_a->next;
	}

	t_lst *curr_b;
	curr_b = lst_b;
	while (curr_b) {
		printf("bbbbb = %d\n", curr_b->content);
		curr_b = curr_b->next;
	}

	//Free de la lista
	deallocate(&lst_a);
	deallocate(&lst_b);

	return(0);
}
