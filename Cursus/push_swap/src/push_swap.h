/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:46:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/16 01:10:02 by lbengoec         ###   ########.fr       */
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
	int				data;
	int				cost_a;
	int				cost_b;
	int				count;
	struct s_lst	*next;
}	t_lst;

/* ***************************** FUNCIONES ********************************** */

/* Create_lst --------------------------------------------------------------- */
t_lst	*add_to_lst(int argc, char *argv[]);
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstnew(int data);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
void	deallocate(t_lst **lst);
t_lst	*ft_lstpenultimate(t_lst *lst);
int		ft_lstsize(t_lst *lst);

/* Check_error -------------------------------------------------------------- */
void	check_digit(char *str_nbr);
void	check_limit(char *str_nbr);
void	check_duplicate(t_lst *lst);

/* Game_rules --------------------------------------------------------------- */
void	swap_a(t_lst **lst_a);
void	swap_b(t_lst **lst_b);
void	swap_a_b(t_lst **lst_a, t_lst **lst_b);
void	push_a(t_lst **lst_a, t_lst **lst_b);
void	push_b(t_lst **lst_a, t_lst **lst_b);
void	rotate_a(t_lst **lst_a);
void	rotate_b(t_lst **lst_b);
void	rotate_a_b(t_lst **lst_a, t_lst **lst_b);
void	reverse_rotate_a(t_lst **lst_a);
void	reverse_rotate_b(t_lst **lst_b);
void	reverse_rotate_a_b(t_lst **lst_a, t_lst **lst_b);

/* Algorithm ---------------------------------------------------------------- */
void	algorithm(t_lst **lst_a, t_lst **lst_b);

/* Algorithm utils ---------------------------------------------------------- */
int		change_positive(int n);
int		check_order(t_lst **lst, char c);
int		check_max_min(t_lst *lst, int nbr, char c);
void	send_to_a(t_lst **lst_a, t_lst **lst_b);
void	order_a(t_lst **lst_a);
void	order_b(t_lst **lst_b);

/* Algorithm big ------------------------------------------------------------ */
void	push_to_a(t_lst **lst_a, t_lst **lst_b);
void	select_and_move(t_lst **lst_a, t_lst **lst_b);
void	find_moves(t_lst **lst_a, t_lst **lst_b);

/* Algorithm cost ----------------------------------------------------------- */
int		cost_in_a(t_lst *lst, int nbr);
int		cost_to_b(t_lst *lst, int nbr);
int		cost_to_a(t_lst *lst, int nbr);
void	total_cost(t_lst *lst);

/* Algorithm move ----------------------------------------------------------- */
void	move_together(t_lst **lst_a, t_lst **lst_b, t_lst *curr);
void	move_a(t_lst **lst_a, int move_top);
void	move_b(t_lst **lst_b, int move_b);

#endif
