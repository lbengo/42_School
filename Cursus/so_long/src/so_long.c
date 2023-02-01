/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/01 12:03:11 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, t_program *program)
{
	if (key == 53)
	{
		mlx_destroy_window(program -> mlx, program -> win);
		free(program -> mlx);
		exit(0);
	}
	printf("Number press %d", key);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_program	program;

	argc = 0;
	// Función principal que conecta con el servidor gráfico del Mac y crear ventana
	program.mlx = mlx_init();
	// return void *0 if failed
	program.map_width = ft_map_lines(argv[1]); // alto de mapa
	program.map = ft_matrix(program.map_width, argv[1]); // matriz del mapa
	program.win = mlx_new_window(program.mlx, (strlen_line(program.map[0])
				* 80), ((program.map_width + 1) * 80), "Pac Man");
	// return void *0 if failed

	ft_put_map(&program);
	mlx_key_hook(program.win, *ft_input, &program);

	// Bucle constante que mantiene detectado los eventos
	mlx_loop(program.mlx);
}
