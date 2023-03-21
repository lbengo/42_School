/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:46:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/21 15:26:49 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ***************************** LIBRERIAS ********************************** */

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/* ******************************* LISTS ************************************ */

typedef struct s_list {
	int				numb;
	struct s_list	*next;
}t_list;

#endif
