<p align="center">
  <img src="https://github.com/lbengo/42_School/blob/main/42_badges/so_longe.png" alt="so_long 42 project badge"/>
</p>

# So_Long

***El objetivo del proyecto so_long es programar un juego sencillo en 2D.***

En este juego, tendrás un personaje principal cuya misión será recolectar todos los objetos coleccionables y llegar a la salida utilizando la menor cantidad de movimientos posibles. Este proyecto nos permitirá familiarizarnos con la librería gráfica de 42, MiniLibX.

## Cómo testear
Ejecuta los siguientes comandos.
```shell
$ git clone git@github.com:lbengo/42_School.git && cd 42_School/Cursus/so_long/
$ make bonus
$ ./so_long_bonus maps/example2.ber
```
> Puedes sustituir el `maps/example2.ber` por tu propio mapa de prueba.

## Cómo empezar

### 01. Conoce la MiniLibX
Antes de empezar con el proyecto, es mejor aprender a manejarnos con la librería MiniLibX, por ello:

***¿Qué es la miniLibX?***

MiniLiX es una librería gráfica que permite realizar funciones básicas para interactuar con las pantallas sin tener conocimientos de X-Window y Cocoa. Esta librería posee numerosas funciones, sin embargo las que usaremos en este proyecto serán: abrir una ventana, crear y dibujar imágenes y gestionar eventos, ganchos y entradas.

***Funciones principales***

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

***Funciones complementarias***

Otras funciones importantes que se han empleado en el desarrollo del proyecto son los siguiente:

<table>
    <thead>
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

Para más información de la minilibx mirar: [Harm_Smits](https://harm-smits.github.io/42docs/libs/minilibx) y [Aurelien_Brabant](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)

### 02. Crea un Makefile.
Realiza un [makefile](https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/Makefile) para que las pruebas durante el ejercicio se realicen más rapidamente.
