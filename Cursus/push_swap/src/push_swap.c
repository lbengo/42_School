/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/05 12:45:40 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Si el primer número es mayor que todos los de la lista lo cambia a la lista B. Ej: 431(lista a). -> 31(lista a) 4(lista b)
//Si no, lo rota al último de la misma lista. Ej: 143 -> 43

// Columna derecha
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

static int	check_max_min(t_lst *lst, t_lst *nbr)
{
	t_lst	*curr;
	int		nbr_max;
	int		nbr_min;
	int		max_min;

	curr = lst;
	max_min = 0;
	nbr_max = nbr->content;
	nbr_min = nbr->content;
	while (curr != NULL)
	{
		if (nbr_min > curr->content)
			nbr_min = curr->content;
		else if (nbr_max < curr->content)
			nbr_max = curr->content;
		curr = curr->next;
	}
	if (nbr->content >= nbr_max || nbr->content <= nbr_min)
			max_min = 1;
	return(max_min);
}


static int	find_max_min(t_lst *lst, int len)
{
	int		nbr_max;
	int		nbr_min;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = lst->content;
	end = ft_lstlast(lst)->content;
	nbr_max = lst->content;
	nbr_min = lst->content;
	while (lst != NULL)
	{
		if (nbr_min > lst->content)
		{
			if (len < i)
				len = i;
			nbr_min = lst->content;
		}
		else if (nbr_max < lst->content)
		{
			if (len < i)
				len = i;
			nbr_max = lst->content;
		}
		i++;
		lst = lst->next;
	}
	if (start == nbr_min && end == nbr_max)
		len = 0;
	return (len);
}

// Columna izquierda
static int	find_move_b(t_lst *lst, t_lst *nbr)
{
	t_lst *next;
	int len;
	int i;

	i = 0;
	len = ft_lstsize(lst);
	if (len < 2)
		return (i);

	printf("------------");
	printf("\nnbr = %d\n", nbr->content);

	if (check_max_min(lst, nbr) == 1)
		i = find_max_min(lst, i);
	else
	{
		while (lst->next != NULL)
		{
			next = lst->next;
			if (lst->content > nbr->content && lst->content < next->content)
				break;
			//else if (lst->content < nbr->content && lst->content > next->content)
			//	break;
			i++;
			lst = lst->next;
		}
	}
	if (i > len/2)
		i = i - len;
	return (i);
}

static void	find_moves(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*stack_a;
	t_lst	*curr;
	int		move_top;
	int		move_b;

	stack_a = *lst_a;
	// Colocar las columnas
	while (stack_a != NULL)
	{
		stack_a->move_top = find_move_top(*lst_a, stack_a);
		stack_a->move_b = find_move_b(*lst_b, stack_a);
		//printf("lista = %d\n", stack_a->content);
		printf("top = %d\n", stack_a->move_top);
		printf("b = %d\n", stack_a->move_b);
		stack_a = stack_a->next;
	}

	curr = *lst_a;
	// Sumar las columnas y guardar el resultado
	while (curr != NULL)
	{
		move_top = curr->move_top;
		move_b = curr->move_b;

		if (move_top < 0)
			move_top = move_top * (-1);
		if (move_b < 0)
			move_b = move_b * (-1);
		curr->count = move_top + move_b;
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
		//------------------------------
		// comprobación de 2 listas
		t_lst *curr_a1;

		curr_a1 = *lst_a;
		while (curr_a1) {
			printf("aaaaaaaaa = %d\n", curr_a1->content);
			curr_a1 = curr_a1->next;
		}

		t_lst *curr_b1;
		curr_b1 = *lst_b;
		while (curr_b1) {
			printf("bbbbb = %d\n", curr_b1->content);
			curr_b1 = curr_b1->next;
		}
		printf("------------------------------------------\n");
		//------------------------------

		find_moves(lst_a, lst_b);
		select_and_move(lst_a, lst_b);

		//------------------------------
		// comprobación de 2 listas
		t_lst *curr_a2;

		curr_a2 = *lst_a;
		while (curr_a2) {
			printf("aaaaaaaaa = %d\n", curr_a2->content);
			curr_a2 = curr_a2->next;
		}

		t_lst *curr_b2;
		curr_b2 = *lst_b;
		while (curr_b2) {
			printf("bbbbb = %d\n", curr_b2->content);
			curr_b2 = curr_b2->next;
		}
		printf("------------------------------------------\n");
		//------------------------------

		find_moves(lst_a, lst_b);
		select_and_move(lst_a, lst_b);

		//------------------------------
		// comprobación de 2 listas
		t_lst *curr_a3;

		curr_a3 = *lst_a;
		while (curr_a3) {
			printf("aaaaaaaaa = %d\n", curr_a3->content);
			curr_a3 = curr_a3->next;
		}

		t_lst *curr_b3;
		curr_b3 = *lst_b;
		while (curr_b3) {
			printf("bbbbb = %d\n", curr_b3->content);
			curr_b3 = curr_b3->next;
		}
		printf("------------------------------------------\n");
		//------------------------------
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

/* 	// comprobación de 2 listas
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
	} */

	//Free de la lista
	deallocate(&lst_a);
	deallocate(&lst_b);

	return(0);
}
