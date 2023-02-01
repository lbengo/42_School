/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:15:04 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/01 09:17:26 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int ft_put_map(void *mlx_ptr, void *win_ptr, char **map, int len)
{
	char	*img_espacio = "textures/espacio.xpm";
	char	*img_muro = "textures/muro.xpm";
	char	*img_pacman = "textures/pacman.xpm";
	void	*img;
	int		img_width;
	int		img_height;
	int		width;
	int		height;
	int		i;
	int		a;

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
