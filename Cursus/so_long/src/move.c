/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:49 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/06 14:21:36 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_find_p(char **map, int c)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y][x])
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				if (c == 'y')
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	ft_check_wall(t_program program, int x, int y, char letter)
{
	if (letter == 'l' && program.map[y][x - 1] == '1')
		return (1);
	else if (letter == 'r' && program.map[y][x + 1] == '1')
		return (1);
	else if (letter == 'd' && program.map[y + 1][x] == '1')
		return (1);
	else if (letter == 'u' && program.map[y - 1][x] == '1')
		return (1);
	return (0);
}

void	ft_move_p(t_program program, void *img, int *x, int *y, char letter)
{
	if (letter == 'l')
		mlx_put_image_to_window(program.mlx, program.win, img, ((--(*x)) * 80),
			(*y * 80));
	else if (letter == 'r')
		mlx_put_image_to_window(program.mlx, program.win, img, ((++(*x)) * 80),
			(*y * 80));
	else if (letter == 'd')
		mlx_put_image_to_window(program.mlx, program.win, img, (*x * 80),
			((++(*y)) * 80));
	else if (letter == 'u')
		mlx_put_image_to_window(program.mlx, program.win, img, (*x * 80),
			((--(*y)) * 80));
}

static int	ft_move(t_program program, char letter)
{
	int				img_height;
	int				img_width;
	void			*img;
	static int		y;
	static int		x;

	if (!x && !y)
	{
		y = ft_find_p(program.map, 'y');
		x = ft_find_p(program.map, 'x');
	}
	if (ft_check_wall(program, x, y, letter) == 1)
		return (0);
	img = mlx_xpm_file_to_image(program.mlx, SPACE, &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.win, img, (x * 80), (y * 80));
	img = mlx_xpm_file_to_image(program.mlx, PACMAN, &img_width, &img_height);
	ft_move_p(program, img, &x, &y, letter);
	return (0);
}

int	ft_input(int key, t_program *program)
{
	if (key == 53)
	{
		mlx_destroy_window(program -> mlx, program -> win);
		ft_free(program -> map);
		free(program -> mlx);
		exit(0);
	}
	else if (key == 123) // left
		ft_move(*program, 'l');
	else if (key == 124) // right
		ft_move(*program, 'r');
	else if (key == 125) // down
		ft_move(*program, 'd');
	else if (key == 126) // up
		ft_move(*program, 'u');

	printf("Number press %d\n", key);
	return (0);
}
