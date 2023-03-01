/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:16:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/28 10:59:30 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*pacman_direction(char letter)
{
	char	*path;

	if (letter == 'l')
		path = PACMANL;
	else if (letter == 'r')
		path = PACMANR;
	else if (letter == 'd')
		path = PACMAND;
	else
		path = PACMANU;
	return (path);
}

int	find_c(char **map)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	while (map[i] != NULL)
	{
		a = 0;
		while (map[i][a] != '\0')
		{
			if (map[i][a] == 'C')
				return (1);
			a++;
		}
		i++;
	}
	return (0);
}

void	ft_exit(t_program *program, int x, int y, char letter)
{
	if (letter == 'l' && program->map[y][x - 1] == 'E' &&
		find_c(program->map) == 0)
		ft_close(program);
	else if (letter == 'r' && program->map[y][x + 1] == 'E' &&
		find_c(program->map) == 0)
		ft_close(program);
	else if (letter == 'd' && program->map[y + 1][x] == 'E' &&
		find_c(program->map) == 0)
		ft_close(program);
	else if (letter == 'u' && program->map[y - 1][x] == 'E' &&
		find_c(program->map) == 0)
		ft_close(program);
}
