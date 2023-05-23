/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:58:18 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/23 17:41:16 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char *argv[])
{
	int	file;

	file = open(".new_file", O_CREAT | O_APPEND | O_RDWR , 0644);
	while (1)
	{
		read()
	}
	close(file);
}
