/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:04:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/24 13:38:19 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_num(char *temp)
{
	int i;

	i = 0;
	if (temp[0] == '-' || temp[0] == '+')
		i++;
	while (temp[i] != '\0')
	{
		if (ft_isdigit(temp[i]) == 0)
		{
			printf("Error\nEverything must be numbers");
			exit(0);
		}
		i++;
	}
}

void check_limits(char *temp)
{
	char *int_max;
	int i;
	int a;

	i = 0;
	a = 0;
	int_max = "2147483647";

	if (strlen(temp) >= 10)
	{
		if (temp[0] == '-' || temp[0] == '+')
			i++;
		while (temp[i] != '\0')
		{
			printf("temp[%d]= %c yyy int_max[%d]= %c\n", i, temp[i], i, int_max[a]);
			//if (temp[0] == '-' && temp[i] > int_min[a])
			if ((temp[i] > int_max[a]) && (temp[0] == '-' && temp[10] > '8'))
			{
				printf("Error\nNumerito máximo superado");
				exit(0);
			}
			i++;
			a++;
		}
	}

}

t_lst *add_to_lst(int argc, char *argv[])
{
	t_lst	*lst_1;
	char	**temp;
	int		input;
	int		i;
	int		a;

	i = 0;
	input = 0;
	lst_1 = NULL;
	while (input++ < argc)
	{
		temp = ft_split(argv[i], ' ');
		a = 0;
		while(temp[a] != NULL)
		{
			check_num(temp[a]);
			check_limits(temp[a]);
			ft_lstadd_back(&lst_1, ft_lstnew(ft_atoi(temp[a])));
			a++;
		}
		ft_free(temp);
		i++;
	}
	return (lst_1);
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
