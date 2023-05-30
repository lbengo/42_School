/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:34:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/30 09:33:08 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

/* ***************************** CONSTANTES ********************************* */

# define READ_FD 0
# define WRITE_FD 1

#endif
