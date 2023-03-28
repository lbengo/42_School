/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/28 10:45:13 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Si el primer número es mayor que todos los de la lista lo cambia a la lista B. Ej: 431(lista a). -> 31(lista a) 4(lista b)
//Si no, lo rota al último de la misma lista. Ej: 143. -> 431

void rotate_a(t_lst **lst)
{
	t_lst *curr;
	__unused t_lst *temp;

	curr = (*lst)->next;
	ft_lstlast(*lst)->next = *lst;
	(*lst)->next = NULL;
	(*lst) = curr;
}



int main (int argc, char *argv[])
{
	t_lst	*lst;

	if (argc == 1)
	{
		printf("Error\nAdd a number");
		return (0);
	}
	lst = add_to_lst(--argc, ++argv);
	check_duplicate(lst);

	//Comprobación de lista
	t_lst *curr;

	curr = lst;
	while (curr != NULL)
	{
		printf("lista = %d\n", curr->content);
		curr = curr -> next;
	}

	//rotación y comprobación de lista
	rotate_a(&lst);
		while (lst) {
		printf("aaaaaaaaa = %d\n", lst->content);
		lst = lst->next;
	}




	//Free de la lista
	deallocate(&lst);

	return(0);
}
