/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/27 11:18:40 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	//Free de la lista
	deallocate(&lst);
	
	return(0);
}
