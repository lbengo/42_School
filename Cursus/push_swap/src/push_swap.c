/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/24 13:16:44 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void check_error(char *temp[])
{

	//check_duplicate(temp);
} */

int main (int argc, char *argv[])
{
	t_lst	*lst_1;

	if (argc > 1)
	{
		lst_1 = add_to_lst(--argc, ++argv);
		check_duplicate(lst_1);

		//Comprobación de lista
		t_lst *curr;

		curr = lst_1;
		while (curr != NULL)
		{
			printf("lista = %d\n", curr->content);
			curr = curr -> next;
		}
		//Free de la lista
		deallocate(&lst_1);
	}
	else
		printf("Error\nAdd a number");

	return(0);
}
