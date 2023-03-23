/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/23 12:08:24 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void check_error(char *temp[])
{
	check_num(temp);
	//check_duplicate(temp);
} */

static void change_to_str(int argc, char *argv[])
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
			ft_lstadd_back(&lst_1, ft_lstnew(ft_atoi(temp[a])));
			a++;
		}
		ft_free(temp);
		i++;
	}
	//check_error();

	t_lst *curr;

	curr = lst_1;
	while (curr != NULL)
	{
		printf("lista = %d\n", curr->content);
		curr = curr -> next;
	}
	deallocate(&lst_1);
}

int main (int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("argc = %d\n", argc);
		printf("argv = %s\n\n", argv[0]);
		change_to_str(--argc, ++argv);
		//check_error(temp);
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
