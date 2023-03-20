/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:35:13 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 10:45:04 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
Crea un nuevo nodo utilizando malloc(3). La variable miembro ’content’ se
inicializa con el contenido del parámetro ’content’. La variable ’next’, con
NULL.
----------------------------------------------------------------------------- */

/* PARÁMETROS:
- content: el contenido con el que crear el nodo.
----------------------------------------------------------------------------- */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
