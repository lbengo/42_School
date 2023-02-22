/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:16:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/22 16:52:16 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_c(t_program program)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	while (program.map[i] != NULL)
	{
		a = 0;
		while (program.map[i][a] != '\0')
		{
			if (program.map[i][a] == 'C')
				return (1);
			a++;
		}
		i++;
	}
	return (0);
}

int	ft_exit(t_program program)
{
	if (find_c(&program) == 1)
		return (0);
	img = mlx_xpm_file_to_image(program.mlx, EXIT, &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.win, img, (x * 80), (y * 80));
	return (1);
}
