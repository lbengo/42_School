/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:47:35 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/28 11:17:53 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_end(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'F' ||
		map[y][x] == 'G')
		return (0);
	if (map[y][x] == 'E')
	{
		map[y][x] = 'e';
		return (0);
	}
	map[y][x] = 'X';
	check_end(map, x + 1, y);
	check_end(map, x - 1, y);
	check_end(map, x, y + 1);
	check_end(map, x, y - 1);
	return (0);
}

int	ft_find_p(char **map, char c)
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

char	**duplicate_map(char **map)
{
	char	**new_map;
	int		i;
	int		a;

	i = 0;
	while (map[i] != NULL)
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	if (!new_map)
		return (0);
	a = 0;
	while (a < i)
	{
		new_map[a] = ft_strdup(map[a]);
		a++;
	}
	new_map[a] = NULL;
	return (new_map);
}

int	send_numb_caract(char **map, char c)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		a = 0;
		while (map[i][a] != '\0')
		{
			if (map[i][a] == c)
				count++;
			a++;
		}
		i++;
	}
	return (count);
}

int	find_c_path(char **new_map)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	while (new_map[i] != NULL)
	{
		a = 0;
		while (new_map[i][a] != '\0')
		{
			if (new_map[i][a] == 'E')
				return (1);
			if (new_map[i][a] == 'C')
				return (2);
			a++;
		}
		i++;
	}
	return (0);
}
