/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:34:59 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/04/13 13:03:05 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*add_to_lst(int argc, char *argv[])
{
	t_lst	*lst;
	char	**temp;
	int		input;
	int		i;
	int		a;

	i = 0;
	input = 0;
	lst = NULL;
	while (input++ < argc)
	{
		temp = ft_split(argv[i], ' ');
		a = 0;
		while (temp[a] != NULL)
		{
			check_digit(temp[a]);
			check_limit(temp[a]);
			ft_lstadd_back(&lst, ft_lstnew(ft_atoi(temp[a])));
			a++;
		}
		ft_free(temp);
		i++;
	}
	return (lst);
}
