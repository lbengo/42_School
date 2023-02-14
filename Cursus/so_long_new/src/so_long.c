/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/14 20:02:48 by lbengoec         ###   ########.fr       */
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

	// Función principal que conecta con el servidor gráfico del Mac y crear ventana

	// return void *0 if failed
	if (argc == 2)
	{
		program.map_width = ft_map_lines(argv[1]); // alto de mapa
		program.map = ft_matrix(program.map_width, argv[1]); // matriz del mapa
		if (check_error(&program) == 2)
		//	return (0);
		ft_free(program.map);
	}
	return (0);
}

/*
falta
	-
 */
