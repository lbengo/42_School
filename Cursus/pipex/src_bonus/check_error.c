/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:43:05 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/12 13:28:00 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int error_message(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int	check_file(char *argv[])
{
	if (access(argv[1], R_OK) != 0)
		return (error_message("Error: No existe el archivo\n"));
	return(0);
}
