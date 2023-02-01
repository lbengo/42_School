/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/01 14:28:37 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int ft_find_p_x(char **map, int i)
{
	int a;

	a = 0;
	while (map[i][a] != '\n')
	{
		if(map[i][a] == 'P')
			return(a);
		a++;
	}
	return (0);
}

static int ft_find_p_y(char **map)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while(map[i][a])
	{
		printf("i= %d\n", i);
		printf("map = %c\n", map[i][a]);
		a = 0;
		while (map[i][a] != '\n' || map[i][a] != '\0')
		{
			if(map[i][a] == 'P')
				return(i);
			a++;
		}
		i++;
	}
	return(2);
}

static void ft_move(t_program program, char letter)
{
	int		img_height;
	int		img_width;
	void	*img;
	int	y;
	int	x;

	y = ft_find_p_y(program.map);
	x = ft_find_p_x(program.map, y);
	printf("x=%d y=%d", x, y);
	if(letter == 'l')
	{
		img = mlx_xpm_file_to_image(program.mlx, SPACE, &img_width, &img_height);
		mlx_put_image_to_window(program.mlx, program.win, img, (x * 80), (y * 80));
		img = mlx_xpm_file_to_image(program.mlx, PACMAN, &img_width, &img_height);
		mlx_put_image_to_window(program.mlx, program.win, img, ((x + 1) * 80), (y * 80));
	}
}

void ft_free(char **map)
{
	unsigned int i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
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
	//else if (key == 123) // left
	else if (key == 124) // right
		ft_move(*program, 'l');
	//else if (key == 125) // down
	//else if (key == 126) // up

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
