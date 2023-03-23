/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:46:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/23 11:04:29 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ***************************** LIBRERIAS ********************************** */

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

/* ******************************* LISTS ************************************ */

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
}	t_lst;


t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstnew(int content);
void	ft_lstadd_back(t_lst **lst, t_lst *new);

#endif
