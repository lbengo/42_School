/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:16:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/01 17:19:16 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*pacman_direction(char letter)
{
	char	*path;

	if (letter == 'l')
		path = PACMANL;
	else if (letter == 'r')
		path = PACMANR;
	else if (letter == 'd')
		path = PACMAND;
	else
		path = PACMANU;
	return (path);
}

int	find_c(char **map)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	while (map[i] != NULL)
	{
		a = 0;
		while (map[i][a] != '\0')
		{
			if (map[i][a] == 'C')
				return (1);
			a++;
		}
		i++;
	}
	return (0);
}

int	print_pacman(t_program *program, int *x, int *y, char letter)
{
	void	*img;
	int		img_height;
	int		img_width;

	img = mlx_xpm_file_to_image(program->mlx, pacman_direction(letter),
			&img_width, &img_height);
	if (!img)
	{
		ft_printf("Error: Corrupt .xpm\n\n");
		ft_close(program);
	}
	if (letter == 'l')
		mlx_put_image_to_window(program->mlx, program->win, img,
			((--(*x)) * 80), (*y * 80));
	else if (letter == 'r')
		mlx_put_image_to_window(program->mlx, program->win, img,
			((++(*x)) * 80), (*y * 80));
	else if (letter == 'd')
		mlx_put_image_to_window(program->mlx, program->win, img,
			(*x * 80), (++(*y)) * 80);
	else if (letter == 'u')
		mlx_put_image_to_window(program->mlx, program->win, img,
			(*x * 80), (--(*y)) * 80);
	return (0);
}
