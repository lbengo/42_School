/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:04:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/26 19:35:14 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_limits(int i, int a, char *temp)
{
	char *int_max;
	
	int_max = "2147483647";
	if (strlen(temp) >= 10)
	{
		if (temp[i] > int_max[a])
		{
			if (i == 10 && temp[0] == '-' && temp[10] == '8')
			{
				i++;
				return(0);
			}
			return (1);
		}
	}
	return (0);
}

void check_digit_and_limit(char *temp)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (temp[0] == '-' || temp[0] == '+')
		i++;
	while (temp[i] != '\0')
	{
		if (ft_isdigit(temp[i]) == 0)
		{
			printf("Error\nEverything must be numbers");
			exit(0);
		}
		if (check_limits(i, a, temp) == 1)
		{
			printf("Error\nNumerito máximo superado");
			exit(0);
		}
		i++;
		a++;
	}
}

void check_duplicate(t_lst *lst_1)
{
	t_lst *curr;
	t_lst *temp;

	curr = lst_1;
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
