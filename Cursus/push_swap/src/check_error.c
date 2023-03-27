/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:04:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/27 11:17:16 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_limits(int i, int a, char *str_nbr)
{
	char *int_max;
	
	int_max = "2147483647";
	if (strlen(str_nbr) >= 10)
	{
		if (str_nbr[i] > int_max[a])
		{
			if (i == 10 && str_nbr[0] == '-' && str_nbr[10] == '8')
			{
				i++;
				return(0);
			}
			return (1);
		}
	}
	return (0);
}

void check_digit_and_limit(char *str_nbr)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (str_nbr[0] == '-' || str_nbr[0] == '+')
		i++;
	while (str_nbr[i] != '\0')
	{
		if (ft_isdigit(str_nbr[i]) == 0)
		{
			printf("Error\nEverything must be numbers");
			exit(0);
		}
		if (check_limits(i, a, str_nbr) == 1)
		{
			printf("Error\nNumerito máximo superado");
			exit(0);
		}
		i++;
		a++;
	}
}

void check_duplicate(t_lst *lst)
{
	t_lst *curr;
	t_lst *temp;

	curr = lst;
	while (curr != NULL)
	{
		temp = curr -> next;
		while (temp != NULL)
		{
			if (curr -> content ==  temp -> content)
			{
				printf("Error\nDuplicate numbers");
				exit(0);
			}
			temp = temp -> next;
		}
		curr = curr -> next;
	}
}
