/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:40:21 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/23 10:37:50 by laurabengoe      ###   ########.fr       */
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
		printf("Error: There is more than one component '%c'.\n\n", c);
		return (2);
	}
	return (0);
}

// Check error path
static int	check_path(char **map)
{
	char			**new_map;
	unsigned int	error;
	
	new_map = duplicate_map(map);
	check_end(new_map, ft_find_p(new_map, 'x'), ft_find_p(new_map, 'y'));
	error = find_c_path(new_map);
	ft_free(new_map);
	if (error == 1 || error == 2)
	{	
		if (error == 1)
			printf("Error: The character would never reach the exit.\n\n");
		else
			printf("Error: The character would never reach the object.\n\n");
		
		return (2);
	}
	return (0);
}


int	check_error(char **map)
{
	if (map[0] == NULL)
	{
		printf("Error: Add map.\n\n");
		return (2);
	}
	// Check map
	if (check_map_rectangular(map) == 2 || check_map_wall (map) == 2)
		return (2);
	//Check caract
	if (check_caract(map, 'P') == 2 || check_caract(map, 'E') == 2 
		|| check_caract(map, 'C') == 2)
		return (2);
	// Check path
	if (check_path(map) == 2)
		return(2);
	return (0);
}
