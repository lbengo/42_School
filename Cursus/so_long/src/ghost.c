/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:31:51 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/28 11:18:33 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_ghost(t_program *program, unsigned int i, unsigned int a)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(program->mlx, GHOSTV, &img_width, &img_height);
	if (!img)
	{
		ft_printf("Error: Corrupt .xpm\n\n");
		ft_close(program);
	}
	mlx_put_image_to_window(program->mlx, program->win, img, (a * 80),
		(i * 80));
}

void	find_ghost(t_program *program)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	while (program -> map[i] != NULL)
	{
		a = 0;
		while (program -> map[i][a] != '\0')
		{
			if (program -> map[i][a] == 'G')
				change_ghost(program, i, a);
			a++;
		}
		i++;
	}
}

void	ft_ghost(t_program *program, int x, int y, char letter)
{
	static unsigned int	change_ghost;

	change_ghost = 0;
	if (find_c(program->map) == 0 && change_ghost == 0)
	{
		change_ghost = 1;
		find_ghost(program);
	}
	if (letter == 'l' && program->map[y][x - 1] == 'G' &&
		find_c(program->map) == 1)
		ft_close(program);
	else if (letter == 'r' && program->map[y][x + 1] == 'G' &&
		find_c(program->map) == 1)
		ft_close(program);
	else if (letter == 'd' && program->map[y + 1][x] == 'G' &&
		find_c(program->map) == 1)
		ft_close(program);
	else if (letter == 'u' && program->map[y - 1][x] == 'G' &&
		find_c(program->map) == 1)
		ft_close(program);
}
