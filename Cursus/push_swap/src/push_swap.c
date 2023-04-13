/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 09:37:57 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_lst	*lst_a;
	t_lst	*lst_b;

	lst_a = add_to_lst(--argc, ++argv);
	lst_b = NULL;
	if (argc == 0 || !lst_a)
	{
		//ft_putstr_fd("Error\n", 2);
		return (0);
	}
	check_duplicate(lst_a);
	algorithm(&lst_a, &lst_b);

	// comprobación de 2 listas
/* 	t_lst *curr_a;

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
