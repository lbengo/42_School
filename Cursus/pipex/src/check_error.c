/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:43:05 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/24 09:49:04 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_message(char *msg)
{
	ft_putstr_fd(msg, 2);
}

int	check_file(char *argv[])
{
	if (access(argv[1], R_OK) != 0)
	{
		error_message("Error: File does not exist\n");
		return(1);
	}
	return(0);
}
