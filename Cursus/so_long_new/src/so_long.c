/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/16 17:36:12 by lbengoec         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_program	program;

	if (argc == 2)
	{
		// Función principal que conecta con el servidor gráfico del Mac y crear ventana
		program.mlx = mlx_init();
		if (program.mlx == NULL)
			return(0);
		program.map_width = ft_map_lines(argv[1]); // alto de mapa
		program.map = ft_matrix(program.map_width, argv[1]); // matriz del mapa
		if (check_error(&program) == 2)
		{
			ft_free(program.map);
			free(program.mlx);
			return(0);
		}
		program.win = mlx_new_window(program.mlx, (strlen_line(program.map[0])
			* 80), ((program.map_width) * 80), "Pac Man");
		if (program.win == NULL)
		{
			free(program.map);
			free(program.mlx);
			return(0);
		}
		if (ft_put_map(&program) == 2)
		{
			printf("Error: Corrupt .xpm\n\n");
			free(program.map);
			free(program.mlx);
			return (0);
		}
		mlx_key_hook(program.win, *ft_input, &program);

		// Bucle constante que mantiene detectado los eventos
		mlx_loop(program.mlx);
		ft_free(program.map);
	}
	return (0);
}
