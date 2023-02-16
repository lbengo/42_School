/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:49 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/16 14:22:09 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	ft_move_h(t_program program, int *x, int *y, char letter)
{
	int		img_height;
	int		img_width;
	void	*img;

	if (letter == 'l')
	{
		img = mlx_xpm_file_to_image(program.mlx, PACMANL, &img_width,
				&img_height);
		mlx_put_image_to_window(program.mlx, program.win, img, ((--(*x)) * 80),
			(*y * 80));
	}
	else if (letter == 'r')
	{
		img = mlx_xpm_file_to_image(program.mlx, PACMANR, &img_width,
				&img_height);
		mlx_put_image_to_window(program.mlx, program.win, img, ((++(*x)) * 80),
			(*y * 80));
	}
}

static void	ft_move_v(t_program program, int *x, int *y, char letter)
{
	int		img_height;
	int		img_width;
	void	*img;

	if (letter == 'd')
	{
		img = mlx_xpm_file_to_image(program.mlx, PACMAND, &img_width,
				&img_height);
		mlx_put_image_to_window(program.mlx, program.win, img, (*x * 80),
			((++(*y)) * 80));
	}
	else if (letter == 'u')
	{
		img = mlx_xpm_file_to_image(program.mlx, PACMANU, &img_width,
				&img_height);
		mlx_put_image_to_window(program.mlx, program.win, img, (*x * 80),
			((--(*y)) * 80));
	}
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
	if (letter == 'r' || letter == 'l')
		ft_move_h(program, &x, &y, letter);
	else
		ft_move_v(program, &x, &y, letter);
	return (0);
}

int	ft_input(int key, t_program *program)
{
	static unsigned int	i;

	if (!i)
		i = 0;
	if (key == 53 || key == 0 || key == 2 || key == 1 || key == 13)
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
		printf("Movement number %d || Number press %d\n", i++, key);
	}
	return (0);
}
