/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/13 11:51:01 by lbengoec         ###   ########.fr       */
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

static int	ft_find_p(char **map, char c)
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

int	main(int argc, char *argv[])
{
	t_program	program;

	argc = 0;
	// Función principal que conecta con el servidor gráfico del Mac y crear ventana

	// return void *0 if failed
	program.map_width = ft_map_lines(argv[1]); // alto de mapa
	program.map = ft_matrix(program.map_width, argv[1]); // matriz del mapa
	find_end(program.map, ft_find_p(program.map, 'x'), ft_find_p(program.map, 'y'));
	if (search_c(program.map, program.map_width) == 1)
		printf("eeerrooooor\n");

	printf("map[0] = %s", program.map[0]);
	printf("map[1] = %s", program.map[1]);
	printf("map[2] = %s", program.map[2]);
	printf("map[3] = %s", program.map[3]);
	printf("map[4] = %s", program.map[4]);
	printf("map[5] = %s", program.map[5]);

	ft_free(program.map);
	// return void *0 if failed

	// Bucle constante que mantiene detectado los eventos
}
