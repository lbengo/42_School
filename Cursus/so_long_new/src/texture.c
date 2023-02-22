/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:58:08 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/22 09:11:47 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_image(t_program *program, char *fig, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(program -> mlx, fig, &img_width, &img_height); // lee la imagen que hayas añadido
	mlx_put_image_to_window(program -> mlx, program -> win, img, x, y); // pone la imagen en la ventana en la posición que quieras
}

static void	ft_find_texture(t_program *program, char fig, int x, int y)
{

	if (fig == '0')
		ft_put_image(program, SPACE, x, y);
	else if (fig == '1')
		ft_put_image(program, WALL, x, y);
	else if (fig == 'C')
		ft_put_image(program, FOOD, x, y);
	else if (fig == 'E')
		ft_put_image(program, GHOST, x, y);
	else if (fig == 'P')
		ft_put_image(program, PACMANR, x, y);
}

void	ft_put_map(t_program *program)
{
	int		x;
	int		y;
	int		i;
	int		a;

	i = 0;
	y = 0;
	while (program -> map[i] != NULL)
	{
		x = 0;
		a = 0;
		while (program -> map[i][a] != '\0')
		{
			ft_find_texture(program, program -> map[i][a], x, y);
			x = x + 80;
			a++;
		}
		y = y + 80;
		i++;
	}
}
