/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:40:21 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/14 20:08:03 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check error map
static int	check_map(char **map)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = strlen_line(map[0]);
	while (map[i] != NULL)
	{
		if (len != strlen_line(map[i]))
		{
			printf("Error: The map must be rectangular.\n\n");
			return (2);
		}
		if (map[i][0] != '1' || map[i][len - 1] != '1')
		{
			printf("Error: The map must be surrounded by walls.\n\n");
			return (2);
		}
		i++;
	}
	return (0);
}

static int	send_numb_caract(char **map, char c)
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
	if (caract > 1)
	{
		printf("Error: There is more than one component'%c'.\n\n", c);
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

	if (program -> map[0] == NULL) // NO FUNCIONA
		return (2);
	if (check_map(program -> map) == 2)
		return (2);
	if (check_caract(program -> map, 'P') == 2 || check_caract
		(program -> map, 'E') == 2 || check_caract(program -> map, 'C') == 2)
		return (2);
	new_map = duplicate_map(program -> map);
	if (check_path(new_map) == 2)
		return (2);
	ft_free(new_map);
	return (0);
}
	//- NULL
	//- .xpm sale error
