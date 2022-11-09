/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:36:47 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 10:49:13 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
Toma como parámetro un nodo ’lst’ y libera la memoria del contenido utilizando
la función ’del’ dada como parámetro, además de liberar el nodo. La memoria
de ’next’ no debe liberarse.
----------------------------------------------------------------------------- */

/* PARÁMETROS:
- lst: el nodo a liberar.
- del: un puntero a la función utilizada para liberar el contenido del nodo.
----------------------------------------------------------------------------- */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst -> content);
	free(lst);
}
