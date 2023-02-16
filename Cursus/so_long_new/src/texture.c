/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:58:08 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/16 17:32:28 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_put_image(t_program *program, char *fig, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(program -> mlx, fig, &img_width, &img_height); // lee la imagen que hayas añadido
	if (!img)
		return (2);
	mlx_put_image_to_window(program -> mlx, program -> win, img, x, y); // pone la imagen en la ventana en la posición que quieras
	return (0);
}

static int ft_find_texture(t_program *program, char fig, int x, int y)
{
	unsigned int find_error;

	find_error = 0;
	if (fig == '0')
		find_error = ft_put_image(program, SPACE, x, y);
	else if (fig == '1')
		find_error = ft_put_image(program, WALL, x, y);
	else if (fig == 'C')
		find_error = ft_put_image(program, FOOD, x, y);
	else if (fig == 'E')
		find_error = ft_put_image(program, GHOST, x, y);
	else if (fig == 'P')
		find_error = ft_put_image(program, PACMANR, x, y);
	if (find_error == 2)
		return (2);
	return (0);
}

int	ft_put_map(t_program *program)
{
	int		x;
	int		y;
	int		i;
	int		a;
	int		find_error;

	i = 0;
	y = 0;
	while (program -> map[i] != NULL)
	{
		x = 0;
		a = 0;
		while (program -> map[i][a] != '\0')
		{
			find_error = ft_find_texture(program, program -> map[i][a], x, y);
			if (find_error == 2)
				return (2);
			x = x + 80;
			a++;
		}
		y = y + 80;
		i++;
	}
	return (0);
}
