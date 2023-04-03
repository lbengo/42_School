/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/03 17:40:10 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Si el primer número es mayor que todos los de la lista lo cambia a la lista B. Ej: 431(lista a). -> 31(lista a) 4(lista b)
//Si no, lo rota al último de la misma lista. Ej: 143 -> 431

static void	find_move_top(t_lst **lst_a)
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

/* static void	find_move_b(t_lst **lst_a, t_lst **lst_b)
{

} */

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
		find_move_top(lst_a);
		//find_move_b(&lst_a, &lst_b);
	}
}

int	main(int argc, char *argv[])
{
	t_lst	*lst_a;
	t_lst	*lst_b;

	if (argc == 1)
	{
		printf("Error\nAdd a number");
		return (0);
	}
	lst_a = add_to_lst(--argc, ++argv);
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
