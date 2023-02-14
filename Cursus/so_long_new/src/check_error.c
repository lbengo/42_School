/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:40:21 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/14 14:44:45 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check error map
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
			printf("Error: The map must be surrounded by walls.\n");
			return(2);
		}
		i++;
	}
	return(0);
}

// Check error path
static int	check_path(char **map)
{
	unsigned int i;
	unsigned int a;

	check_end(map, ft_find_p(map, 'x'), ft_find_p(map, 'y'));
	i = 0;
	a = 0;
	while (map[i][a] != '\0')
	{
		while(map[i][a] != '\0')
		{
			printf("%c", map[i][a]);
			if (map[i][a] == 'E')
			{
				printf("Error: The character would never reach the exit.\n");
				return (2);
			}
			if (map[i][a] == 'C')
			{
				printf("Error: The character would never reach the object.\n");
				return (2);
			}
			a++;
		}
		printf("eeee %c", map[i][a]);
		i++;
	}
	return(0);
}

int	check_error(t_program *program)
{
	//check_end(temp, ft_find_p(temp, 'x'), ft_find_p(temp, 'y'));
	char **new_map;

	if (program -> map[0] == NULL)
		printf("Error\n");
	if (check_map(program -> map) == 2)
		printf("Error\n");
	//mirar si hay dobleso no hay alguno
	//printf("Error: A starting position 'P' is required.\n");
	new_map = duplicate_map(program -> map);
	if (check_path(new_map) == 2)
		printf("Error\n");


	printf("map[0] = %s\n", new_map[0]);
	printf("map[1] = %s\n", new_map[1]);
	printf("map[2] = %s\n", new_map[2]);
	printf("map[3] = %s\n", new_map[3]);
	printf("map[4] = %s\n\n", new_map[4]);

	ft_free(new_map);
	//- No existe algun objeto
	//- Más de un objeto
	//- NULL
	//- .xpm sale error
	return(2);
}


