<p align="center">
  <img src="https://github.com/lbengo/42_School/blob/main/42_badges/so_longe.png" alt="so_long 42 project badge"/>
</p>

# So_Long

***El objetivo del proyecto so_long es programar un juego sencillo en 2D.***

En este juego, tendrás un personaje principal cuya misión será recolectar todos los objetos coleccionables antes de llegar a la salida utilizando la menor cantidad de movimientos posibles. Este proyecto nos permitirá familiarizarnos con la librería gráfica de 42, MiniLibX

<p align="center">
  <img src="https://github.com/lbengo/42_School/blob/main/Cursus/so_long/Readme/Game.png" alt="so_long game"/>
</p>

## Consideraciones técnicas
- El jugador debe poder moverse en 4 direcciones, subir, bajar, izquierda o derecha.
- El jugador no puede entrar dentro de las paredes.
- El número de cada movimiento debe mostrarse en la terminal.
- Utilizar una perspectiva 2D.
- El mapa estará constituido por 6 carácteres: P (pacman), 1 (wall), 0 (empty), C (coolecible), E (exit) y G (ghost).
- Ver más en la [ficha del proyecto](https://github.com/lbengo/42_School/blob/main/Cursus/so_long/Readme/So_Long_Subject.pdf).

## Cómo testear
Ejecuta los siguientes comandos.
```shell
$ git clone git@github.com:lbengo/42_School.git && cd 42_School/Cursus/so_long/
$ make bonus
$ ./so_long_bonus maps/example2.ber
```
> Puedes sustituir el `maps/example2.ber` por tu propio mapa de prueba.

Mientras el So_Long se este ejecutando, el siguiente conjunto de controles estarán disponibles:

<table>
  <tr><td><strong>Controles</strong></td><td><strong>Acción</strong></td></tr>
  <tr><td><kbd>&nbsp;▲&nbsp;</kbd><kbd>&nbsp;◄&nbsp;</kbd><kbd>&nbsp;▼&nbsp;</kbd><kbd>&nbsp;►&nbsp;</kbd></td><td>Mover personaje principal</td></tr>
  <tr><td><kbd>&nbsp;esc&nbsp;</kbd> or close window</td><td>Salir del juego</td></tr>
</table>

## Cómo empezar

### Parte 01. Conoce la MiniLibX
Antes de empezar con el proyecto, es mejor aprender a manejarnos con la librería MiniLibX.

***¿Qué es la miniLibX?***

MiniLiX es una librería gráfica que permite realizar funciones básicas para interactuar con las pantallas sin tener conocimientos de X-Window y Cocoa. Esta librería posee numerosas funciones, sin embargo las que usaremos en este proyecto serán: abrir una ventana, crear y dibujar imágenes y gestionar eventos, ganchos y entradas.

<table>
    <thead>
        <tr>
            <th colspan=2><h4 align="left">Funciones principales</h4></th>
        </tr>
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
> Nota: para compilar la minilibX se debe añadir la siguiente flag `-L [librería minilibx] -lmlx -framework OpenGL -framework Appkit`.

<table>
    <thead>
        <tr>
            <th colspan=2><h4 align="left">Funciones complementarias</h4></th>
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

Para más información de la minilibx mirar: [Harm_Smits](https://harm-smits.github.io/42docs/libs/minilibx) y [Aurelien_Brabant](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)

### Parte 02. Gestión de errores.

Antes de iniciar el juego, es fundamental gestionar posibles errores que puedan surgir. Estos incluyen:

- Asegurarse de que el mapa contenga al menos una salida, un objeto y una posición inicial. Si hay caracteres duplicados en la salida o en la posición, se producirá un error.
- Verificar que el mapa sea rectangular y esté rodeado por muros.
- Comprobar si existe un camino válido en el mapa.
- Comprobar que el archivo .xpm no esté corrupto.

Si se detecta algún error, se mostrará un mensaje correspondiente al usuario para que pueda corregirlo de manera efectiva.

### Parte 03. Leer y mostrar el mapa

Con el objetivo de facilitar posteriormente el proceso de movimiento del personaje, recomiendo leer y almacenar el mapa en una matríz, pudiendo emplear como ayuda la función get_next_line.

Después de que el mapa haya sido guardado, se utilizará la librería MiniLibX para mostrarlo en una nueva ventana.


### Parte 04. Mover al personaje

Por último, se buscará al personaje principal en el mapa y se moverá utilizando la función "hook" de MiniLibX y la matriz creada previamente. El personaje deberá cumplir con las siguientes condiciones:

- Si se encuentra con un muro, no podrá atravesarlo.
- No podrá salir sin haber recogido todos los objetos coleccionables previamente.
- Después de cada movimiento, se mostrará en la terminal el número de movimientos realizados.
- Si el personaje entra en contacto con un fantasma, morirá (parte bonus).

---
Made by lbengoec: lbengoec@student.42urduliz.com | LinkedIn: [lbengoec](https://www.linkedin.com/in/laura-bengoechea-navarro/)
