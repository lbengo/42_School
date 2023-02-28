/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:34:28 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/28 09:55:12 by lbengoec         ###   ########.fr       */
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
	int		width;
}			t_program;

/* ***************************** FUNCIONES ********************************** */

char	**ft_matrix(int len, char *argv);
int		ft_map_lines(char *argv);
int		strlen_line(char *line);
void	ft_put_map(t_program *program);
int		ft_input(int key, t_program *program);
void	ft_free(char **map);
int		check_error(char **map);
int		check_end(char **map, int x, int y);
int		ft_find_p(char **map, char c);
char	**duplicate_map(char **map);
int		send_numb_caract(char **map, char c);
int		find_c_path(char **new_map);
int		ft_close(t_program *program);
void	ft_exit(t_program *program, int x, int y, char letter);
int		find_c(char **map);
void	ft_ghost(t_program *program, int x, int y, char letter);
void	find_ghost(t_program *program);

/* ***************************** CONSTANTES ********************************* */

# define SPACE "textures/Space.xpm"
# define WALL "textures/Wall.xpm"
# define GHOST "textures/Ghost.xpm"
# define GHOSTV "textures/Ghostv.xpm"
# define FOOD "textures/Food.xpm"
# define EXIT "textures/Exit.xpm"
# define PACMANL "textures/PacmanL.xpm"
# define PACMANR "textures/PacmanR.xpm"
# define PACMAND "textures/PacmanD.xpm"
# define PACMANU "textures/PacmanU.xpm"

#endif
