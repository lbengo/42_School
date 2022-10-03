/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:12:37 by lbengoec          #+#    #+#             */
/*   Updated: 2022/09/23 10:55:08 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	new = NULL;
	while (lst)
	{
		aux = ft_lstnew(f(lst -> content));
		if (!aux)
		{
			ft_lstclear (&aux, del);
			return (NULL);
		}
		ft_lstadd_back(&new, aux);
		lst = lst -> next;
	}
	return (new);
}
