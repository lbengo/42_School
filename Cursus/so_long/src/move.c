/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:49 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/01 17:19:02 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_pacman(t_program *program, int *x, int *y, char letter)
{
	int		img_height;
	int		img_width;
	void	*img;

	img = mlx_xpm_file_to_image(program->mlx, SPACE, &img_width, &img_height);
	mlx_put_image_to_window(program->mlx, program->win, img,
		(*x * 80), (*y * 80));
	print_pacman(program, x, y, letter);
	if (program->map[*y][*x] == 'C')
		program->map[*y][*x] = '0';
}

static void	ft_exit(t_program *program, int x, int y, char letter)
{
	if (letter == 'l' && program->map[y][x - 1] == 'E' &&
		find_c(program->map) == 0)
		ft_close(program);
	else if (letter == 'r' && program->map[y][x + 1] == 'E' &&
		find_c(program->map) == 0)
		ft_close(program);
	else if (letter == 'd' && program->map[y + 1][x] == 'E' &&
		find_c(program->map) == 0)
		ft_close(program);
	else if (letter == 'u' && program->map[y - 1][x] == 'E' &&
		find_c(program->map) == 0)
		ft_close(program);
}

static int	stop_moving(t_program *program, int x, int y, char letter)
{
	if (letter == 'l')
	{
		if ((program->map[y][x - 1] == '1') || (program->map[y][x - 1] == 'E'
		&& find_c(program->map) == 1))
			return (1);
	}
	else if (letter == 'r')
	{
		if ((program->map[y][x + 1] == '1') || (program->map[y][x + 1] == 'E'
		&& find_c(program->map) == 1))
			return (1);
	}
	else if (letter == 'd')
	{
		if ((program->map[y + 1][x] == '1') || (program->map[y + 1][x] == 'E'
		&& find_c(program->map) == 1))
			return (1);
	}
	else if (letter == 'u')
	{
		if ((program->map[y - 1][x] == '1') || (program->map[y - 1][x] == 'E'
		&& find_c(program->map) == 1))
			return (1);
	}
	return (0);
}

static int	ft_move(t_program *program, char letter)
{
	static int		y;
	static int		x;

	if (!x && !y)
	{
		y = ft_find_p(program->map, 'y');
		x = ft_find_p(program->map, 'x');
	}
	if (stop_moving(program, x, y, letter) == 1)
		return (1);
	ft_exit(program, x, y, letter);
	move_pacman(program, &x, &y, letter);
	return (0);
}

int	ft_input(int key, t_program *program)
{
	static unsigned int	i;
	unsigned int		check_move;

	if (!i)
		i = 0;
	check_move = 0;
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 53)
	{
		if (key == 53)
			check_move = ft_close(program);
		else if (key == 123)
			check_move = ft_move(program, 'l');
		else if (key == 124)
			check_move = ft_move(program, 'r');
		else if (key == 125)
			check_move = ft_move(program, 'd');
		else if (key == 126)
			check_move = ft_move(program, 'u');
		if (check_move == 0)
			ft_printf("Movement number %d || Number press %d\n", i++, key);
	}
	return (0);
}
