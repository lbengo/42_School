/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:34:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/01 11:10:26 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ***************************** LIBRERIAS ********************************** */

# include "../minilibx/mlx.h" // Librería minilibx
# include "../get_next_line/get_next_line.h" // Librería gnl
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> // Librería que gestiona la función open


/* **************************** ESTRUCTURAS ********************************* */

typedef struct s_program {
	void	*mlx; // resultado de la función principal que conecta con el servidor gráfico
	void	*win; // identificador de la nueva ventana
	char	**map;
	int		map_width;
}			t_program;

/* ***************************** FUNCIONES ********************************** */

char	**ft_matrix(int len, char *argv);
int		ft_map_lines(char *argv);
int		strlen_line(char *line);
int		ft_put_map(void *mlx_ptr, void *win_ptr, char **map, int len);


/* ***************************** CONSTANTES ********************************* */

# define PACMAN "textures/Pacman.xpm"
# define SPACE "textures/Space.xpm"
# define WALL "textures/Wall.xpm"
# define GHOST "textures/Ghost.xpm"
# define FOOD "textures/Food.xpm"

#endif
