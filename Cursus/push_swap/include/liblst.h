/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:34:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/19 13:31:19 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLST_H
# define LIBLST_H

/* ***************************** LIBRERIAS ********************************** */

#include <stdlib.h>

/* ******************************* LISTA ************************************ */

typedef struct s_lst
{
	int				data;
	int				cost_a;
	int				cost_b;
	int				count;
	struct s_lst	*next;
}	t_lst;

/* ***************************** FUNCIONES ********************************** */

void	ft_deallocate(t_lst **lst_1);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstnew(int data);
t_lst	*ft_lstpenultimate(t_lst *lst);
int		ft_lstsize(t_lst *lst);

#endif
