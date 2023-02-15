/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:40:21 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/15 18:26:54 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check error map rectangular
static int	check_map_rectangular(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = strlen_line(map[0]);
	while (map[i] != NULL)
	{
		if (len != strlen_line(map[i]))
		{
			printf("Error: The map must be rectangular.\n\n");
			return (2);
		}
		i++;
	}
	return (0);
}

// Check error map wall
static int	check_map_wall(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = strlen_line(map[0]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
		{
			printf("Error: The map must be surrounded by walls.\n\n");
			return (2);
		}
		i++;
	}
	while (len-- > 0)
	{
		if (map[0][len] != '1' || map[i - 1][len] != '1')
		{
			printf("Error: The map must be surrounded by walls.\n\n");
			return (2);
		}
	}
	return (0);
}

// Check error caracter
static int	check_caract(char **map, char c)
{
	unsigned int	caract;

	caract = send_numb_caract(map, c);
	if (caract == 0)
	{
		printf("Error: Component '%c'is required.\n\n", c);
		return (2);
	}
	if (caract > 1 && c != 'C')
	{
		printf("Error: There is more than one component '%c'.\n\n", c); // TODO: CAMBIAR MENOS SI ES 'C'
		return (2);
	}
	return (0);
}

// Check error path
static int	check_path(char **map)
{
	unsigned int	i;
	unsigned int	a;

	check_end(map, ft_find_p(map, 'x'), ft_find_p(map, 'y'));
	i = 0;
	while (map[i] != NULL)
	{
		a = 0;
		while (map[i][a] != '\0')
		{
			if (map[i][a] == 'E')
			{
				printf("Error: The character would never reach the exit.\n\n");
				return (2);
			}
			if (map[i][a] == 'C')
			{
				printf("Error: The character would never reach the object.\n\n");
				return (2);
			}
			a++;
		}
		i++;
	}
	return (0);
}

int	check_error(t_program *program)
{
	char	**new_map;

	if (program -> map[0] == NULL)
	{
		printf("Error: Add map.\n\n");
		return (2);
	}
	// Check map
	if (check_map_rectangular(program -> map) == 2 || check_map_wall
		(program -> map) == 2)
		return (2);
	//Check caract
	if (check_caract(program -> map, 'P') == 2 || check_caract
		(program -> map, 'E') == 2 || check_caract(program -> map, 'C') == 2)
		return (2);
	// Check path
	new_map = duplicate_map(program -> map);
	if (check_path(new_map) == 2)
		return (2);
	ft_free(new_map);
	return (0);
}
	//- .xpm sale error
