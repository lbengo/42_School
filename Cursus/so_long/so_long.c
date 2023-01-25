/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:33:19 by lbengoec          #+#    #+#             */
/*   Updated: 2023/01/25 11:16:55 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> // Librería que gestiona la función open
# include "get_next_line/get_next_line.h" // Librería minilibx

/* int key_hook()
{
	printf("Hello fron keyhook\n");
	return (0);
} */

/* int ft_put_map(void *mlx_ptr, void *win_ptr)
{
	int		fd;
	int		i;
	void	*img;
	char	read_line;
	char	*img_espacio = "files/espacio.xpm";
	char	*img_muro = "files/muro.xpm";
	char	*img_pacman = "files/pacman.xpm";
	int		img_width;
	int		img_height;
	int		width;
	int		height;

	fd = open ("map.ber", O_RDONLY);
	i = 1;
	width = 0;
	height = 0;
	while (i > 0)
	{
		i = read(fd, &read_line, 1);
		if (i <= 0) // ha llegado al final de la lectura o se ha producido un error en la lectura
			break;
		if (read_line == '\n')
		{
			height = height + 80;
			width = 0;
		}
		if (read_line == '1')
		{
			img = mlx_xpm_file_to_image(mlx_ptr, img_muro, &img_width, &img_height); // lee la imagen que hayas añadido
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, width, height); // pone la imagen en la ventana en la posición que quieras
			width = width + 80;
		}
		if (read_line == '0')
		{
			img = mlx_xpm_file_to_image(mlx_ptr, img_espacio, &img_width, &img_height); // lee la imagen que hayas añadido
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, width, height); // pone la imagen en la ventana en la posición que quieras
			width = width + 80;
		}
		if (read_line == 'P')
		{
			img = mlx_xpm_file_to_image(mlx_ptr, img_pacman, &img_width, &img_height); // lee la imagen que hayas añadido
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, width, height); // pone la imagen en la ventana en la posición que quieras
			width = width + 80;
		}
	}
	close(fd);
	return (0);
} */

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

int	ft_map_lines(void)
{
	char	*line;
	int		i;
	int		fd;
	int		len;

	fd = open ("maps/2exits.ber", O_RDONLY);
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

char	**ft_matrix(void)
{
	char	**map;
	char	*line;
	int		fd;
	int		len;
	int		i;


	fd = open ("maps/2exits.ber", O_RDONLY);
	len = ft_map_lines();
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


int main()
{
	char	**map;
	int check = -1;
	map = ft_matrix();

	while (map[++check])
	{
		printf("line [%d] -> %s\n", check, map[check]);
		free(map[check]);
	}
	free(map);

	//printf("%s", ft_split(s, c));
	return(0);

}
/*
int main(void)
{
	void	*mlx_ptr; // resultado de la función principal que conecta con el servidor gráfico
	void	*win_ptr; // identificador de la nueva ventana
	char	**map;

	mlx_ptr = mlx_init(); // función principal que conecta con el servidor gráfico del Mac
	//mirar errores de mapa
	map = ft_matrix();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Pac Man"); // abrir una ventana
	//if (!win_ptr)
	//	return(NULL);
	ft_put_map(mlx_ptr, win_ptr);
	//mlx_key_hook(win_ptr, key_hook, 0); //cuando presionas cualquier tecla se muestra en la terminal
	mlx_loop(mlx_ptr); // función esencial para que no se cierre la ventana y más cosas
} */
