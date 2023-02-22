/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:49 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/22 07:46:53 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char *ft_p_direct(char letter)
{
	char *path;

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

static int	ft_move_p(t_program program, int *x, int *y, char letter)
{
	void	*img;
	int		img_height;
	int		img_width;

	img = mlx_xpm_file_to_image(program.mlx, ft_p_direct(letter), &img_width,
				&img_height);
	if (!img)
		return (2);
	if (letter == 'l')
		mlx_put_image_to_window(program.mlx, program.win, img, ((--(*x)) * 80),
			(*y * 80));
	else if (letter == 'r')
		mlx_put_image_to_window(program.mlx, program.win, img, ((++(*x)) * 80),
			(*y * 80));
	else if (letter == 'd')
		mlx_put_image_to_window(program.mlx, program.win, img, (*x * 80),
			(++(*y)) * 80);
	else if (letter == 'u')
		mlx_put_image_to_window(program.mlx, program.win, img, (*x * 80),
			(--(*y)) * 80);
	return (0);
}

static int	ft_check_wall(t_program program, int x, int y, char letter)
{
	if (letter == 'l' && program.map[y][x - 1] == '1')
		return (1);
	else if (letter == 'r' &&  ,program.map[y][x + 1] == '1')
		return (1);
	else if (letter == 'd' && program.map[y + 1][x] == '1')
		return (1);
	else if (letter == 'u' && program.map[y - 1][x] == '1')
		return (1);
	return (0);
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
	if (program.map[y][x] == 'C')
		program.map[y][x] = '0';
	img = mlx_xpm_file_to_image(program.mlx, SPACE, &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.win, img, (x * 80), (y * 80));
	if (ft_move_p(program, &x, &y, letter) == 2)
		return (2);
	return (0);
}

int	ft_input(int key, t_program *program)
{
	static unsigned int	i;
	unsigned int find_error;

	if (!i)
		i = 0;
	find_error = 0;
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 53)
	{
		if (key == 53)
		{
			mlx_destroy_window(program -> mlx, program -> win);
			ft_free(program -> map);
			free(program -> mlx);
			exit(0);
		}
		else if (key == 123) // left
			find_error = ft_move(*program, 'l');
		else if (key == 124) // right
			find_error = ft_move(*program, 'r');
		else if (key == 125) // down
			find_error = ft_move(*program, 'd');
		else if (key == 126) // up
			find_error = ft_move(*program, 'u');
		printf("Movement number %d || Number press %d\n", i++, key);
	}
	printf("q es i=%d", find_error);
	return (find_error);
}
