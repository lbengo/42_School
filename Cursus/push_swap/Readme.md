<p align="center">
  <img src="https://github.com/lbengo/42_School/blob/main/42_badges/push_swape.png" alt="Push_Swap 42 project badge"/>
</p>

# Push_Swap

***El objetivo del proyecto push_swap es programar un algoritmo de ordenamiento.***

Este programa deberá ordenar una lista dada de números aleatorios, a través de unas instrucciones, utilizando el menor número de acciones posibles. Para ello, tendremos que manipular varios tipos de algoritmos y elegir la solución más adecuada para una ordenación optimizada de los datos. Este proyecto es un gran ejemplo para aprender a trabajar con listas, por lo que recomiendo utilizarlas.


## Enunciado del ejercicio
- Dispones de dos listas, llamadas a y b. En la lista a tendrás los números y en b no habrá nada.
- El objetivo es ordenar la lista a en orden ascendente con la ayuda de la lista b.
- Para hacerlo se deben seguir las siguientes instrucciones:

<table align="center">
    <thead>
        <tr>
            <th align="left">Nombre</th>
            <th align="left">Instrucción</th>
            <th align="left">Descripción</th>
        </tr>
    </thead>
    <tbody>
	<tr>
            <td>sa</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/swap.c>swap_a</a></td>
            <td>Intercambia los dos primeros elementos encima del stack a.</td>
    </tr>
	<tr>
            <td>sb</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/swap.c>swap_b</a></td>
            <td>Intercambia los dos primeros elementos encima del stack b.</td>
    </tr>
	<tr>
            <td>ss</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/swap.c>swap_a_b</a></td>
            <td>swap_a y swap_b a la vez</td>
    </tr>
	<tr>
            <td>ra</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/rotate.c>rotate_a</a></td>
			<td>El primer elemento de la lista a pasa al último.</td>
    </tr>
	<tr>
            <td>rb</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/rotate.c>rotate_b</a></td>
			<td>El primer elemento de la lista b pasa al último.</td>
    </tr>
	<tr>
            <td>rr</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/rotate.c>rotate_a_b</a></td>
			<td>El primer elemento de la lista a y b pasan al último.</td>
    </tr>
	<tr>
            <td>rra</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/reverse_rotate.c>reverse_rotate_a</a></td>
			<td>El último elemento de la lista a pasa al primero.</td>
    </tr>
	<tr>
            <td>rrb</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/reverse_rotate.c>reverse_rotate_b</a></td>
			<td>El último elemento de la lista a pasa al primero.</td>
    </tr>
	<tr>
            <td>rrr</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/reverse_rotate.c>reverse_rotate_a_b</a></td>
			<td>El último elemento de la lista a y b pasan al primero.</td>
    </tr>
		<tr>
            <td>pa</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/push.c>push_a</a></td>
            <td>Toma el primer elemento de la lista b y lo situa al principio de la lista a.</td>
    </tr>
	<tr>
            <td>pb</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/push.c>push_b</a></td>
			<td>Toma el primer elemento de la lista a y lo situa al principio de la lista b.</td>
    </tr>
	</tbody>
<table>


## Cómo testear
Ejecuta los siguientes comandos.
```shell
$ git clone git@github.com:lbengo/42_School.git && cd 42_School/Cursus/push_swap/
$ make
$ ./push_swap 5 4 9 8 7
```
> Puedes sustituir los números por los que prefieras (en el rango de un int).


## Forma de evaluar

- Para 3 valores de entrada: No se permiten más de 3 movimientos.
- Para 5 valores de entrada: No se permiten más de 12 movimientos.
- Para 100 valores de entrada: Se puntuará de 1 hasta 5 dependiendo de los movimientos ejecutados.
	- 5 puntos. Movimientos realizados <= 700
	- 4 puntos. 700 < movimientos <= 900
	- 3 puntos. 900 < movimientos <= 1100
	- 2 puntos. 1100 < movimientos <= 1300
	- 1 puntos. 1300 < movimientos <= 1500

- Para 500 valores de entrada: Se puntuará de 1 hasta 5 dependiendo de los movimientos ejecutados.
	- 5 puntos. Movimientos realizados <= 5500
	- 4 puntos. 5501 < movimientos <= 7000
	- 3 puntos. 7000 < movimientos <= 8500
	- 2 puntos. 8500 < movimientos <= 10000
	- 1 puntos. 10000 < movimientos <= 11500

> Para comprobar los valores de entrada más facilmente puedes añadir wc -l. Ej: ./push_swap 5 3 7 | wc -l


## Cómo empezar

### 01. Control de errores
Errores a gestionar
- Números positivos y/o negativos. Ej: 2 -2 7 / 4 3 5 / -5 -1 -9
- Alguno de los números es más grande que un int
- Nunca duplicados (Cuidado con: 0 -0 / -05 -5 / 5 +5)
- Separados solo por un espacio
- Los valores pueden entrar tanto por argumentos como por arrays. Ej: 5 "3 8" / 5 3 8 / "5 3 8"

### 02. Añadir los valores a la lista a
Para ello, primero realicé algunas funciones básicas para las listas como por ejemplo: ft_lstnew, ft_lstsize o ft_lstadd_front, entre otras. Y, a continuación, las empleé con el objetivo de incorporar los valores a la lista a.

### 03. Creación de las instrucciones
Tras haber rellenado la lista, realicé las instrucciones del push_swap (sa, rb, pa, ...) y comprobé que su funionamiento fuera correcto. Previniendo con ello errores al realizar el algoritmo.

### 04. Implementación del algoritmo: Insertion Sort
Tras evaluar y estudiar diferentes algoritmos, el que se ha seguido en este proyecto es el Insertion Sort ya que me ha parecido más intuitivo y fácil de implementar.

El Insertion Sort es un algoritmo de ordenación que coloca un elemento sin ordenar (de la lista a) en su lugar adecuado (de la lista b) en cada iteración. Veamos a continuación más detalladamente los pasos de este algoritmo:

<p align="center">
  <img src="https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/Readme_img/List.png" alt="list"/>
</p>

En primer lugar, 




calcular el coste que tendría mover cada número en la siguiente lista
