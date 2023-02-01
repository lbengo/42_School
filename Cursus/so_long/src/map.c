/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:15:04 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/01 09:50:20 by lbengoec         ###   ########.fr       */
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

static void	ft_put_image(void *mlx, void *win, char *fig, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, fig, &img_width, &img_height); // lee la imagen que hayas añadido
	mlx_put_image_to_window(mlx, win, img, x, y); // pone la imagen en la ventana en la posición que quieras
}

int ft_put_map(void *mlx, void *win, char **map, int len)
{
	int		x;
	int		y;
	int		i;
	int		a;

	i = 0;
	y = 0;
	while (len-- >= 0)
	{
		x = 0;
		a = 0;
		while (map[i][a] != '\n')
		{
			if (map[i][a] == '1')
				ft_put_image(mlx, win, WALL, x, y);
			if (map[i][a] == 'P')
				ft_put_image(mlx, win, PACMAN, x, y);
			if (map[i][a] == '0')
				ft_put_image(mlx, win, SPACE, x, y);
			x = x + 80;
			a++;
		}
		y = y + 80;
		i++;
	}
	return (0);
}
