/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:34:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/30 09:31:09 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* ***************************** LIBRERIAS ********************************** */

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <unistd.h> // Librería que gestiona la función close
# include <fcntl.h> // Librería que gestiona la función open

/* ***************************** FUNCIONES ********************************** */

/* Check_error -------------------------------------------------------------- */
void	error_message(char *msg);
int		check_file(char *argv[]);

/* Pipex_utils -------------------------------------------------------------- */
void	exec_cmd(char *argv, char **env);

/* File_in and file_out ----------------------------------------------------- */
int		select_file_in(char *argv[]);
void	file_in(char *argv);
void	select_file_out(char *argv[], int cmd, char **env);

/* ***************************** CONSTANTES ********************************* */

# define READ_FD 0
# define WRITE_FD 1

#endif
