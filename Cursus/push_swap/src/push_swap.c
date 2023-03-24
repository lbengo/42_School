/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/24 12:52:43 by lbengoec         ###   ########.fr       */
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

/* static int	ft_compare(char *number, char **list)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	j;

	i = 0;
	while (list[i] != NULL)
	{
		a = 0;
		while (list[i][a] != '\0')
		{
			j = 0;
			while (list[i][a + j] == number[a + j])
			{
				if (number[a + j] == '\0')
					return (1);
				j++;
			}
			a++;
		}
		i++;
	}
	return (0);
}

static void check_duplicate(char **temp)
{
	unsigned int	i;
	unsigned int	duplicate;

	i = 0;
	duplicate = 0;
	while (temp[i] != NULL)
	{
		duplicate = ft_compare(temp[i], temp);
		if (duplicate > 1)
		{
			printf("Error\nDuplicate numbers");
			exit(0);
		}
		printf("duplicate = %d\n", ft_compare(temp[i], temp));
		i++;
	}
} */
