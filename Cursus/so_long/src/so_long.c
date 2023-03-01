/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/01 17:18:30 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free (map);
}

int	ft_close(t_program *program)
{
	ft_free(program->map);
	mlx_destroy_window(program->mlx, program->win);
	free(program->mlx);
	exit(0);
}

static void	init_map(t_program *program)
{
	program->mlx = mlx_init();
	program->win = mlx_new_window(program->mlx, (strlen_line(program->map[0])
				* 80), ((program->width) * 80), "Pac Man");
	ft_put_map(program);
	mlx_key_hook(program->win, *ft_input, program);
	mlx_hook(program->win, 17, 1L << 17, ft_close, program);
	mlx_loop(program->mlx);
	ft_close(program);
}

int	main(int argc, char *argv[])
{
	t_program	program;

	if (argc == 2)
	{
		program.width = ft_map_lines(argv[1]);
		program.map = ft_matrix(program.width, argv[1]);
		if (check_error(program.map) == 1)
		{
			ft_free(program.map);
			return (0);
		}
		init_map(&program);
	}
	return (0);
}
