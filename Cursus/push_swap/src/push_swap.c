/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/23 11:15:36 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void deallocate(t_lst **lst_1)
{
	t_lst *curr;
	t_lst *aux;

	curr = *lst_1;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr -> next;
		free(aux);
	}
	*lst_1 = NULL;
}

static void change_to_str(int argc, char *argv[])
{
	t_lst	*lst_1;
	int input;
	int i;
	int a;
	int numb;
	char **temp;

	input = 0;
	i = 0;
	lst_1 = NULL;
	while (input++ < argc)
	{
		temp = ft_split(argv[i], ' ', '+');
		a = 0;
		while(temp[a] != NULL)
		{
			numb = ft_atoi(temp[a]);
			ft_lstadd_back(&lst_1, ft_lstnew(numb));
			//printf("1->%d\n", list_1->content);
			//printf("número = %s\n", temp[a]); //guardar en las listas
			a++;
		}
		ft_free(temp);
		i++;
	}
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

/* static void check_num(char **temp)
{
	int i;
	int a;

	i = 0;
	while (temp[i] != NULL)
	{
		a = 0;
		if (temp[i][0] == '-')
			a++;
		while (temp[i][a] != '\0')
		{
			if (ft_isdigit(temp[i][a]) == 0 || temp[i][a] == '-')
			{
				printf("Error\nEverything must be numbers");
				exit(0);
			}
			a++;
		}
		i++;
	}
}

static void check_error(char *temp[])
{
	check_num(temp);
	//check_duplicate(temp);
} */

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
