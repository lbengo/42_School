/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/29 08:48:18 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Si el primer número es mayor que todos los de la lista lo cambia a la lista B. Ej: 431(lista a). -> 31(lista a) 4(lista b)
//Si no, lo rota al último de la misma lista. Ej: 143. -> 431

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
	swap_a(&lst_a);

	t_lst *curr_a;

	curr_a = lst_a;
	while (curr_a) {
		printf("\naaaaaaaaa = %d", curr_a->content);
		curr_a = curr_a->next;
	}

	/* t_lst *curr_b;

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
