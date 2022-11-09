/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:12:37 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 10:51:27 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
Devuelve el último nodo de la lista.
----------------------------------------------------------------------------- */

/* PARÁMETROS:
- lst: un puntero a un nodo.
- f: la dirección de un puntero a una función usada en la iteración de cada
elemento de la lista.
- del: un puntero a función utilizado para eliminar el contenido de un nodo,
si es necesario.
----------------------------------------------------------------------------- */

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
