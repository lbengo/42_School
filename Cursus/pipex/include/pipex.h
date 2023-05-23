/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:34:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/23 17:39:27 by lbengoec         ###   ########.fr       */
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
int	error_message(char *msg);
int	check_file(char *argv[]);

/* Pipex_utils --------------------------------------------------------------- */
char	*ft_find_path(char **env);
char	**ft_separate_path(char **env);
void	exec_cmd(char *argv, char **env);

#endif
