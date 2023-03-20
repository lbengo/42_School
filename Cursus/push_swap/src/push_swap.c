/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/20 19:19:09 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void check_num(char **temp)
{
	char sign;
	int i;
	int a;

	i = 0;

	sign = 0;
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

/* static void check_duplicate(int argc, char *argv[])
{
	int numb;
	int i;

	numb = 0;
	i = 0;
	while (numb++ < argc)
	{
		while (argv[i])
	}
} */

static void check_error(char *temp[])
{
	check_num(temp);
	//check_duplicate(temp);
}

static void change_to_str(int argc, char *argv[])
{
	int numb;
	int i;
	int a;
	char **temp;

	numb = 0;
	i = 0;
	temp = NULL;
	while (numb++ < argc)
	{
		temp = ft_split(argv[i], ' ');
		check_error(temp);
		a = 0;
		while(temp[a] != NULL)
		{
			printf("número = %s\n", temp[a]);
			a++;
		}
		ft_free(temp);
		i++;
	}
}

int main (int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("argc = %d\n", argc);
		printf("argv = %s\n\n", argv[0]);
		change_to_str(--argc, ++argv);
	}
	else
		printf("Error\nAdd a number");

	return(0);
}
