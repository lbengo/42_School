/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:04:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:02:45 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_limit(char *str_nbr)
{
	char	*int_max;
	int		i;
	int		a;

	i = 0;
	a = 0;
	int_max = "2147483647";
	if (strlen(str_nbr) >= 10)
	{
		if (str_nbr[0] == '-' || str_nbr[0] == '+')
			i++;
		if (strlen(str_nbr) == 10 && i == 1)
			return ;
		while ((str_nbr[i] != '\0') && (str_nbr[i] == int_max[a++]))
			i++;
		if ((str_nbr[i] > int_max[--a]))
		{
			if (i == 10 && str_nbr[0] == '-' && str_nbr[10] <= '8')
				return ;
			ft_putstr_fd("Error\n", 2);
			exit(0);
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
			exit(0);
		}
	}
	while (str_nbr[i] != '\0')
	{
		if (ft_isdigit(str_nbr[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		i++;
	}
}

void	check_duplicate(t_lst *lst)
{
	t_lst	*curr;
	t_lst	*temp;
	int		len;

	len = 0;
	curr = lst;
	while (curr != NULL)
	{
		len++;
		temp = curr -> next;
		while (temp != NULL)
		{
			if (curr->data == temp->data)
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			temp = temp -> next;
		}
		curr = curr -> next;
	}
	if (len == 1)
		exit(0);
}
