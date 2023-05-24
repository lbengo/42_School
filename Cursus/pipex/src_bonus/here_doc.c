/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:58:18 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/24 13:14:23 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// file = open(".new_file", O_CREAT | O_APPEND | O_RDWR , 0644);

void	here_doc(char *argv[])
{
	int		file;
	char *line;

	argv = NULL;
	line = NULL;
	file = open(".new_file", O_CREAT | O_TRUNC | O_RDWR , 0644);
	printf("line = %s\n", line);
	//get_next_line(0);
	/* while (1)
	{
		line = get_next_line(0);

	} */
	close(file);
}

