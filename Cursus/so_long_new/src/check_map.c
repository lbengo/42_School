/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:40:21 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/14 13:41:10 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	check_map(char **map)
{
	unsigned int i;
	int len;

	i = 0;
	len = strlen_line(map[0]);
	while (map[i] != NULL)
	{
		if (len != strlen_line(map[i]))
		{
			printf("Error: The map must be rectangular.\n");
			return(2);
		}
		if (map[i][0] != '1' || map[i][len - 1] != '1')
		{
			printf("Error: The map must be enclosed/surrounded by walls.\n");
			return(2);
		}
		i++;
	}
	return(0);
}

static int	check_end(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return(0);
	if (map[y][x] == 'E')
		map[y][x] = 'e';
	else if (map[y][x] == 'C')
		map[y][x] = 'c';
	else if (map[y][x] == 'P')
		map[y][x] = 'p';
	else
		map[y][x] = 'X';
	check_end(map, ++x, y);
	check_end(map, x - 2, y);
	check_end(map, x, ++y);
	check_end(map, x, y - 2);
	return(0);
}

static int	ft_find_p(char **map, char c)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
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

static int	check_path(char **map)
{
	check_end(map, ft_find_p(map, 'x'), ft_find_p(map, 'y'));
	return(2);
}

int	check_error(t_program *program)
{
	//check_end(temp, ft_find_p(temp, 'x'), ft_find_p(temp, 'y'));
	if (program -> map[0] == NULL)
		printf("Error\n");
	if (check_map(program -> map) == 2)
		printf("Error\n");
	if (check_path(program -> map) == 2)
		printf("Error\n");

	//- No existe algun objeto
	//- Más de un objeto
	//- NULL
	//- .xpm sale error
	return(2);
}


