/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:04:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 15:19:14 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_INT "2147483647"

void	check_limit(char *str_nbr)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (strlen(str_nbr) >= strlen(MAX_INT))
	{
		if (str_nbr[0] == '-' || str_nbr[0] == '+')
			i++;
		if (strlen(str_nbr) == strlen(MAX_INT) && i == 1)
			return ;
		while ((str_nbr[i] != '\0') && (str_nbr[i] == MAX_INT[a++]))
			i++;
		if ((str_nbr[i] > MAX_INT[--a]))
		{
			if (i == 10 && str_nbr[0] == '-' && str_nbr[10] <= '8')
				return ;
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
}

void	check_digit(char *str_nbr)
{
	int	i;

	i = 0;
	if (str_nbr[0] == '-' || str_nbr[0] == '+')
	{
		i++;
		if (!str_nbr[i])
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	while (str_nbr[i] != '\0')
	{
		if (!ft_isdigit(str_nbr[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

void	check_duplicate(t_lst *lst)
{
	t_lst	*temp;

	while (lst != NULL)
	{
		temp = lst -> next;
		while (temp != NULL)
		{
			if (lst->data == temp->data)
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			temp = temp -> next;
		}
		lst = lst -> next;
	}
}
