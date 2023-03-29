/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:46:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/29 08:47:23 by laurabengoe      ###   ########.fr       */
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

/* ***************************** FUNCIONES ********************************** */

/* List_functions ----------------------------------------------------------- */
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstnew(int content);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
void	deallocate(t_lst **lst);
t_lst *ft_lstpenultimate(t_lst *lst);

/* Create_lst --------------------------------------------------------------- */
t_lst *add_to_lst(int argc, char *argv[]);

/* Check_error -------------------------------------------------------------- */
void check_digit_and_limit(char *str_nbr);
void check_duplicate(t_lst *lst);

/* Game_rules --------------------------------------------------------------- */
void swap_a(t_lst **lst_a);
void swap_b(t_lst **lst_b);
void swap_a_b(t_lst **lst_a, t_lst **lst_b);
void push_a(t_lst **lst_a, t_lst **lst_b);
void push_b(t_lst **lst_a, t_lst **lst_b);
void rotate_a(t_lst **lst_a);
void rotate_b(t_lst **lst_b);
void rotate_a_b(t_lst **lst_a, t_lst **lst_b);
void reverse_rotate_a(t_lst **lst_a);
void reverse_rotate_b(t_lst **lst_b);
void reverse_rotate_a_b(t_lst **lst_a, t_lst **lst_b);

#endif
