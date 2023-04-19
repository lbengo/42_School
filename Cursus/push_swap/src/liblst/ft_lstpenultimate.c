/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpenultimate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:01 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/19 13:22:10 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_lst	*ft_lstpenultimate(t_lst *lst)
{
	t_lst	*curr;
	t_lst	*prev;

	if (!lst)
		return (0);
	prev = lst;
	while (prev->next != NULL)
	{
		curr = prev;
		prev = prev->next;
	}
	return (curr);
}
