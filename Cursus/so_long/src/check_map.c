/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:40:21 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/10 10:03:08 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_end(char **area, int width, int x, int y)
{
	area[y][x] = 'X';
	if (area[y][x + 1] != '1')
	{
		x++;
		find_end(area, width, x, y);
		x--;
	}
	if ((x - 1) >= 0 && area[y][x - 1] != '1')
	{
		x--;
		find_end(area, width, x, y);
		x++;
	}
	if ((y + 1) < width && area[y + 1][x] != '1')
	{
		y++;
		find_end(area, width, x, y);
		y--;
	}
	if ((y - 1) >= 0 && area[y - 1][x] != '1')
	{
		y--;
		find_end(area, width, x, y);
		y++;
	}
}
