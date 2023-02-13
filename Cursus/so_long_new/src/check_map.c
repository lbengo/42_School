/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:40:21 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/13 17:03:55 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_c(char **area, int width)
{
	int i;
	int a;
	int e;
	int c;
	int p;
	int E;
	int C;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	E = 0;
	C = 0;
	//printf("º map[0] = %s", area[0]);
	//printf("º map[1] = %s", area[1]);
	//printf("º map[2] = %s\n", area[2]);
	while (width >= 0)
	{
		a = 0;
		while (area[i][a] != '\0')
		{
			if (area[i][a] == 'E')
				E++;
			if (area[i][a] == 'C')
				C++;
			if (area[i][a] == 'c' || area[i][a] == 'C')
				c++;
			if (area[i][a] == 'e' || area[i][a] == 'E')
				e++;
			if (area[i][a] == 'p' || area[i][a] == 'P')
				p++;
			a++;
		}
		i++;
		width--;
	}
	if (p == 0)
	{
		printf("No existe jugador en el mapa.\n\nConsejo: Añade la posición inicial del jugador 'P' en el mapa.\n");
		return (1);
	}
	if (E > 0)
	{
		printf("El jugador nunca podría llegar a la salida.\n\nConsejo: Cambia el mapa.\n");
		return(1);
	}
	if (e == 0)
	{
		printf("No existe salida en el mapa.\n\nConsejo: Añade una salida 'E' al mapa.\n");
		return (1);
	}
	if (c == 0)
	{
		printf("No existe coleccionable en el mapa.\n\nConsejo: Añade un coleccionable 'C' al mapa.\n");
		return (1);
	}
	if (p > 1)
	{
		printf("Existe más de un inicio 'P' en el mapa.\n\nConsejo: Deja un y elimina las demás.\n");
		return (1);
	}
	if (e > 1)
	{
		printf("Existe más de una salida 'E' en el mapa.\n\nConsejo: Deja una y elimina las demás.\n");
		return (1);
	}

	if (C > 0)
	{
		printf("El jugador nunca podría llegar a un objeto.\n\nConsejo: Cambia el mapa.\n");
		return(1);
	}
	return (0);
}

static int	check_end(char **area, int x, int y)
{
	if (area[y][x] == '1' || area[y][x] == 'X' || area[y][x] == 'e' || area[y][x] == 'c' || area[y][x] == 'p')
		return(0);
	if (area[y][x] == 'E')
		area[y][x] = 'e';
	else if (area[y][x] == 'C')
		area[y][x] = 'c';
	else if (area[y][x] == 'P')
		area[y][x] = 'p';
	else
		area[y][x] = 'X';
	check_end(area, ++x, y);
	check_end(area, x - 2, y);
	check_end(area, x, ++y);
	check_end(area, x, y - 2);
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

int	check_error(t_program *program)
{
	check_end(program -> map, ft_find_p(program -> map, 'x'), ft_find_p(program -> map, 'y'));

	printf("Error\n");

	printf("map[0] = %s\n", program -> map[0]);
	printf("map[1] = %s\n", program -> map[1]);
	printf("map[2] = %s\n", program -> map[2]);
	//printf("map[3] = %s\n", program -> map[3]);
	//printf("map[4] = %s\n", program -> map[4]);
	//- Perímetro con '1'
	//- Mapa roto
	//- longitud del mapa
	//- No existe algun objeto
	//- Más de un objeto
	//- NULL
	return(2);
}


