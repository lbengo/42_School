/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/28 13:46:45 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Si el primer número es mayor que todos los de la lista lo cambia a la lista B. Ej: 431(lista a). -> 31(lista a) 4(lista b)
//Si no, lo rota al último de la misma lista. Ej: 143. -> 431

void rotate_a(t_lst **lst)
{
	t_lst *curr;

	curr = (*lst)->next;
	ft_lstlast(*lst)->next = *lst;
	(*lst)->next = NULL;
	(*lst) = curr;
}

/* push b - toma el primer elemento del stack a y lo pone encima del stack b.
No hace nada si a está vacío */

static void push_b(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *last_nbr;

	last_nbr = ft_lstlast(*lst_a);
	(ft_lstpenultimate(*lst_a))->next = NULL;
	if (lst_b)
	last_nbr->next = *lst_b;
	*lst_b = last_nbr;


}

int main (int argc, char *argv[])
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

	//Comprobación de lista
	t_lst *curr;

	curr = lst_a;
	while (curr != NULL)
	{
		printf("lista = %d\n", curr->content);
		curr = curr -> next;
	}

	//rotación y comprobación de lista
	push_b(&lst_a, &lst_b);

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
