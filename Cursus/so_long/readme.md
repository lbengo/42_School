¿Qué es y cómo empezar con el miniLibX?
MiniLiX es una librería gráfica que permite realizar funciones básicas para interactuar con las pantallas sin tener conocimientos de X-Window y Cocoa. Esta librería posee numerosas funciones, sin embargo las que usaremos en este proyecto serán: abrir una ventana, crear y dibujar imágenes y gestionar eventos, ganchos y entradas.

Funciones:
- mlx_new_window : manage windows
- mlx_pixel_put  : draw inside window
- mlx_new_image  : manipulate images
- mlx_loop       : handle keyboard or mouse events


Función principal que conecta con el servidor gráfico del Mac:
mlx_init();

Función para abrir una ventana:
void *mlx_new_window (void* mlx_ptr, int size_x, int size_y, char *title);

- mlx_ptr: la conexión con el servidor gráfico.
- size_x y size_y: altura y anchura de la pantalla a mostrar.
- title: título de la ventana.

```C
#include "mlx.h" // librería minilibx

int main (void)
{
	void *mlx_ptr; // resultado de la función principal que conecta con el servidor gráfico
	void win_ptr; // identificador de la nueva ventana

	mlx_ptr = mlx_init(); // función principal que conecta con el servidor gráfico del Mac
	win_ptr = mlx_new_window(); // abrir una ventana
	mlx_loop(mlx_ptr); // función esencial para que no se cierre la ventana y además tiene la función de crear y dibuar imágenes y gestionar eventos
}
```
Para compilar hay que añadir el siguiente comando:
`gcc [función].c -L [librería minilibx] -lmlx -framework OpenGL -framework Appkit`



