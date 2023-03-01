# So_Long - En proceso

## ¿Qué es y cómo empezar con la miniLibX?
MiniLiX es una librería gráfica que permite realizar funciones básicas para interactuar con las pantallas sin tener conocimientos de X-Window y Cocoa. Esta librería posee numerosas funciones, sin embargo las que usaremos en este proyecto serán: abrir una ventana, crear y dibujar imágenes y gestionar eventos, ganchos y entradas.

### 1. Funciones principales

Las funciones principales que se deben emplear en el proyecto son:

<table>
    <thead>
        <tr>
            <th align="left">Función</th>
            <th align="left">Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td valign="top"><b>mlx_init</b></td>
            <td valign="top">Inicia la conexión entre una aplicación y el sistema gráfico.</td>
        </tr>
		<tr>
            <td valign="top"><b>mlx_new_window</b></td>
            <td valign="top">Crea una nueva ventana en la pantalla del sistema gráfico.</td>
        </tr>
		<tr>
            <td valign="top"><b>mlx_loop</b></td>
            <td valign="top">Inicia el bucle principal de eventos del sistema gráfico. Este bucle se encarga de recibir y procesar eventos de entrada, como la entrada del teclado, clics del ratón y eventos de actualización de la pantalla.</td>
        </tr>
	</tbody>
<table>

Inicio de la minilibX

```C
#include "mlx.h" // librería minilibx

int main (void)
{
	void *mlx_ptr;
	void win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window();
	mlx_loop(mlx_ptr);
}
```
Nota: para compilar la minilibX se debe añadir la siguiente flag `-L [librería minilibx] -lmlx -framework OpenGL -framework Appkit`.

### 2. Funciones complementarias

Otras funciones importantes que se han empleado en el desarrollo del proyecto son los siguiente:

<table>
    <thead>
        <tr>
            <th colspan=2><h3 align="left">Funciones complementarias</h3></th>
        </tr>
        <tr>
            <th align="left">Función</th>
            <th align="left">Descripción</th>
        </tr>
    </thead>
    <tbody>
		<tr>
            <td valign="top"><b>mlx_xpm_file_to_image</b></td>
            <td valign="top">Carga una imagen XPM desde un archivo y la convierte en una estructura de datos de imagen que puede ser utilizada por otras funciones de MiniLibX.</td>
        </tr>
		<tr>
            <td valign="top"><b>mlx_put_image_to_window</b></td>
            <td valign="top">Muestra una imagen en una ventana</td>
        </tr>
		<tr>
            <td valign="top"><b>mlx_hook</b></td>
            <td valign="top">Permite que el programa responda a eventos específicos del usuario, como pulsaciones de teclas o clics de ratón, y realice acciones específicas en respuesta a ellos.</td>
        </tr>
	</tbody>
<table>

Para más información de la minilibx mirar: <a src="https://harm-smits.github.io/42docs/libs/minilibx">Harm_Smits</a> y <a src="https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx">Aurelien_Brabant</a>
