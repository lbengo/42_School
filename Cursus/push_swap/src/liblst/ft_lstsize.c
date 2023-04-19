/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:19:54 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/19 13:20:08 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

int	ft_lstsize(t_lst *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
