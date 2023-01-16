/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:33:19 by lbengoec          #+#    #+#             */
/*   Updated: 2023/01/16 10:23:14 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"

int main (void)
{
	void	*mlx_ptr; // resultado de la función principal que conecta con el servidor gráfico
	void	*win_ptr; // identificador de la nueva ventana
	void	*img;
	char	*prueba = "gato.xpm";
	int		img_width;
	int		img_height;

	mlx_ptr = mlx_init(); // función principal que conecta con el servidor gráfico del Mac
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Pac Man"); // abrir una ventana
	img = mlx_xpm_file_to_image(mlx_ptr, prueba, &img_width, &img_height); // lee la imagen que hayas añadido
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0); // pone la imagen en la ventana en la posición que quieras
	mlx_loop(mlx_ptr); // función esencial para que no se cierre la ventana y más cosas
}
