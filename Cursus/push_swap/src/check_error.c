/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:04:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/23 12:16:25 by lbengoec         ###   ########.fr       */
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
