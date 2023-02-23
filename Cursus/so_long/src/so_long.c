/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/23 10:33:55 by laurabengoe      ###   ########.fr       */
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
	map = NULL;
}

static int	ft_close(t_program *program)
{
	if (program -> map)
		ft_free(program -> map);
	if (program -> mlx)
		free(program -> mlx);
	if (program -> win)
		mlx_destroy_window(program -> mlx, program -> win);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_program	program;

	if (argc == 2)
	{
		program.map_width = ft_map_lines(argv[1]); // alto de mapa
		program.map = ft_matrix(program.map_width, argv[1]); // matriz del mapa
		if (check_error(program.map) == 2)
		{
			ft_free(program.map);
			return(0);
		}
		program.mlx = mlx_init();
		if (program.mlx == NULL)
			return(0);
		program.win = mlx_new_window(program.mlx, (strlen_line(program.map[0])
			* 80), ((program.map_width) * 80), "Pac Man");
		if (program.win == NULL)
		{
			free(program.map);
			free(program.mlx);
			return(0);
		}
		ft_put_map(&program);

		mlx_key_hook(program.win, *ft_input, &program);
		mlx_hook(program.win, 17, 1L << 17, ft_close, &program);
/* 
		// Saliste del videojuego
		if (ft_exit(&program) == 2)
		{
			ft_free(program.map);
			free(program.mlx);
			return(0);
		} */
		
		mlx_loop(program.mlx);
		ft_close(&program);
	}
	return (0);
}
