/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:34:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/25 15:21:43 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* ***************************** LIBRERIAS ********************************** */

# include "pipex.h"

/* ***************************** FUNCIONES ********************************** */

/* Pipex_utils --------------------------------------------------------------- */
int		select_file_in(char *argv[]);
void	file_in(char *argv[]);
void	here_doc(char *argv[]);

#endif
