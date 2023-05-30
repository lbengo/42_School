/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:43:05 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/29 10:39:21 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_message(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	check_file(char *argv[])
{
	if (access(argv[1], R_OK) != 0)
	{
		if (ft_strncmp(argv[1], "here_doc", 7) == 0)
			return (0);
		error_message("Error: File does not exist\n");
	}
	return (0);
}
