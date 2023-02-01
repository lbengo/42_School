/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:58:08 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/01 10:40:34 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_image(void *mlx, void *win, char *fig, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, fig, &img_width, &img_height); // lee la imagen que hayas añadido
	mlx_put_image_to_window(mlx, win, img, x, y); // pone la imagen en la ventana en la posición que quieras
}

static void ft_find_texture(void *mlx, void *win, char fig, int x, int y)
{
	if (fig == '0')
		ft_put_image(mlx, win, SPACE, x, y);
	else if (fig == '1')
		ft_put_image(mlx, win, WALL, x, y);
	else if (fig == 'C')
		ft_put_image(mlx, win, FOOD, x, y);
	else if (fig == 'E')
		ft_put_image(mlx, win, GHOST, x, y);
	else if (fig == 'P')
		ft_put_image(mlx, win, PACMAN, x, y);
}

int ft_put_map(void *mlx, void *win, char **map, int len)
{
	int		x;
	int		y;
	int		i;
	int		a;

	i = 0;
	y = 0;
	while (len-- >= 0)
	{
		x = 0;
		a = 0;
		while (map[i][a] != '\n')
		{
			ft_find_texture(mlx, win, map[i][a], x, y);
			x = x + 80;
			a++;
		}
		y = y + 80;
		i++;
	}
	return (0);
}
