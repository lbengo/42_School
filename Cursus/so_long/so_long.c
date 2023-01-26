/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:33:19 by lbengoec          #+#    #+#             */
/*   Updated: 2023/01/26 13:33:50 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int key_hook()
{
	printf("Hello fron keyhook\n");
	return (0);
} */

int ft_put_map(void *mlx_ptr, void *win_ptr, char **map, int len)
{
	int		i;
	int		a;
	void	*img;
	char	*img_espacio = "files/espacio.xpm";
	char	*img_muro = "files/muro.xpm";
	char	*img_pacman = "files/pacman.xpm";
	int		img_width;
	int		img_height;
	int		width;
	int		height;

	i = 0;
	a = 0;
	height = 0;
	while (len >= 0)
	{
		width = 0;
		while (map[i][a] != '\n')
		{
			if (map[i][a] == '1')
			{
				img = mlx_xpm_file_to_image(mlx_ptr, img_muro, &img_width, &img_height); // lee la imagen que hayas añadido
				mlx_put_image_to_window(mlx_ptr, win_ptr, img, width, height); // pone la imagen en la ventana en la posición que quieras
			}
			if (map[i][a] == '0' || map[i][a] == 'E'|| map[i][a] == 'C')
			{
				img = mlx_xpm_file_to_image(mlx_ptr, img_espacio, &img_width, &img_height); // lee la imagen que hayas añadido
				mlx_put_image_to_window(mlx_ptr, win_ptr, img, width, height); // pone la imagen en la ventana en la posición que quieras
			}
			if (map[i][a] == 'P')
			{
				img = mlx_xpm_file_to_image(mlx_ptr, img_pacman, &img_width, &img_height); // lee la imagen que hayas añadido
				mlx_put_image_to_window(mlx_ptr, win_ptr, img, width, height); // pone la imagen en la ventana en la posición que quieras
			}
			width = width + 80;
			a++;
		}
		height = height + 80;
		len --;
		a = 0;
		i++;
	}
	return (0);
}

// añadir si no tiene objeto (C) o posición inicial (P) debe salir error
// añadir si no es rectangular y si tiene salto de linea debe salir error
//ft_check_map(void);

int	strlen_line(char *line)
{
	unsigned int	i;

	i = 0;
	if (line == NULL)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			break;
		i++;
	}
	return (i);
}

int	ft_map_lines(char *argv)
{
	char	*line;
	int		i;
	int		fd;
	int		len;

	fd = open (argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	len = strlen_line(line);
	while (line != NULL || len == strlen_line(line))
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		if (len != strlen_line(line))
			break;
		i++;
	}
	free (line);
	close(fd);
	return (i);
}

char	**ft_matrix(int len, char *argv)
{
	char	**map;
	int		fd;
	int		i;


	fd = open (argv, O_RDONLY);
	map = malloc((len + 1) * sizeof(char *));
	if (!map)
		return(NULL);
	i = 0;
	while (i <= len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int main(int argc, char *argv[])
{
	void	*mlx_ptr; // resultado de la función principal que conecta con el servidor gráfico
	void	*win_ptr; // identificador de la nueva ventana
	char	**map;
	int		i;
	int		map_width;

	argc = 0;
	mlx_ptr = mlx_init(); // función principal que conecta con el servidor gráfico del Mac
	map_width = ft_map_lines(argv[1]);
	map = ft_matrix(map_width, argv[1]);
	win_ptr = mlx_new_window(mlx_ptr, (strlen_line(map[0]) * 80), ((map_width + 1) * 80), "Pac Man"); // abrir una ventana
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (0);
	}
	ft_put_map(mlx_ptr, win_ptr, map, map_width);
	i = 0;
	while(map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	//mlx_key_hook(win_ptr, key_hook, 0); //cuando presionas cualquier tecla se muestra en la terminal
	mlx_loop(mlx_ptr); // función esencial para que no se cierre la ventana y más cosas
	free(mlx_ptr);
	return (0);
}
