/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/02 12:16:05 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int ft_find_p(char **map, int c)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while(map[y][x])
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if(map[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				if (c == 'y')
					return(y);
			}
			x++;
		}
		y++;
	}
	return(0);
}

void	*ft_change_map(t_program program, int x, int y)
{
	int				img_height;
	int				img_width;
	void			*img;

	img = mlx_xpm_file_to_image(program.mlx, SPACE, &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.win, img, (x * 80), (y * 80));
	img = mlx_xpm_file_to_image(program.mlx, PACMAN, &img_width, &img_height);
	return (img);
}

static void ft_move(t_program program, char letter)
{
	static int		y;
	static int		x;
	void			*img;

	if (!x && !y)
	{
		y = ft_find_p(program.map, 'y');
		x = ft_find_p(program.map, 'x');
	}
	else if (letter == 'l')
	{
		img = ft_change_map(program, x, y);
		mlx_put_image_to_window(program.mlx, program.win, img, ((x - 1) * 80), (y * 80));
		x--;
	}
	if (letter == 'r')
	{
		img = ft_change_map(program, x, y);
		mlx_put_image_to_window(program.mlx, program.win, img, ((x + 1) * 80), (y * 80));
		x++;
	}
	else if (letter == 'd')
	{
		img = ft_change_map(program, x, y);
		mlx_put_image_to_window(program.mlx, program.win, img, (x * 80), ((y + 1) * 80));
		y++;
	}
	else if (letter == 'u')
	{
		img = ft_change_map(program, x, y);
		mlx_put_image_to_window(program.mlx, program.win, img, (x * 80), ((y - 1) * 80));
		y--;
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
	else if (key == 123) // left
		ft_move(*program, 'l');
	else if (key == 124) // right
		ft_move(*program, 'r');
	else if (key == 125) // down
		ft_move(*program, 'd');
	else if (key == 126) // up
		ft_move(*program, 'u');

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
