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

<table>
    <thead>
        <tr>
            <th align="left">Instrucción</th>
            <th align="left">Nombre</th>
            <th align="left">Descripción</th>
			<th align="left">Lista a</th>
			<th align="left">Lista b</th>
			<th></th>
        </tr>
    </thead>
    <tbody>
	<tr>
            <td>sa</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/swap.c>swap_a</a></td>
            <td>Intercambia los dos primeros elementos encima del stack a.</td>
			<td>1 2 3 4 -> 2 1 3 4</td>
			<td></td>
    </tr>
	<tr>
            <td>sb</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/swap.c>swap_b</a></td>
            <td>Intercambia los dos primeros elementos encima del stack B.</td>
			<td></td>
			<td>1 2 3 4 -> 2 1 3 4</td>
    </tr>
	<tr>
            <td>ss</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/swap.c>swap_a_b</a></td>
            <td>swap_a y swap_b a la vez</td>
			<td>1 2 3 4 -> 2 1 3 4</td>
			<td>1 2 3 4 -> 2 1 3 4</td>
    </tr>
	<tr>
            <td>pa</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/push.c>push_a</a></td>
            <td>Toma el primer elemento de la lista b y lo situa al principio de la lista a.</td>
			<td>1 2 3 -> 4 1 2 3</td>
			<td>4 5 -> 5</td>
    </tr>
	<tr>
            <td>pb</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/push.c>push_b</a></td>
			<td>Toma el primer elemento de la listaa y lo situa al principio de la lista b.</td>
            <td>1 2 3 -> 2 3</td>
			<td>4 5 -> 1 4 5</td>
    </tr>
	<tr>
            <td>ra</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/rotate.c>rotate_a</a></td>
			<td>El primer elemento de la lista a pasa al último.</td>
            <td>1 2 3 4 -> 2 3 4 1</td>
			<td></td>
    </tr>
	<tr>
            <td>rb</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/rotate.c>rotate_b</a></td>
			<td>El primer elemento de la lista b pasa al último.</td>
            <td>1 2 3 4 -> 2 3 4 1</td>
			<td></td>
    </tr>
	<tr>
            <td>rr</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/rotate.c>rotate_a_b</a></td>
			<td>El primer elemento de la lista a y b pasan al último.</td>
            <td>1 2 3 4 -> 2 3 4 1</td>
			<td>1 2 3 4 -> 2 3 4 1</td>
    </tr>
	<tr>
            <td>rra</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/reverse_rotate.c>reverse_rotate_a</a></td>
			<td>El último elemento de la lista a pasa al primero.</td>
            <td>1 2 3 4 -> 4 1 2 3</td>
			<td></td>
    </tr>
	<tr>
            <td>rrb</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/reverse_rotate.c>reverse_rotate_b</a></td>
			<td>El último elemento de la lista a pasa al primero.</td>
            <td></td>
			<td>1 2 3 4 -> 4 1 2 3</td>
    </tr>
	<tr>
            <td>rrr</td>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/push_swap/src/game_rules/reverse_rotate.c>reverse_rotate_a_b</a></td>
			<td>El último elemento de la lista a y b pasan al primero.</td>
            <td>1 2 3 4 -> 4 1 2 3</td>
			<td>1 2 3 4 -> 4 1 2 3</td>
    </tr>
	</tbody>
<table>



***Errores a gestionar***
- Números positivos y/o negativos. Ej: 2 -2 7 / 4 3 5 / -5 -1 -9
- Alguno de los números es más grande que un int
- Nunca duplicados (Cuidado con: 0 -0 / -05 -5 / 5 +5)
- Separados solo por un espacio
- Pueden entrar tanto por argumentos como por arrays. Ej: 5 "3 8" / 5 3 8 / "5 3 8"

Ej: ./push_swap 2 1 3

Nota:
	argc = número de carácteres. Ej: argc en el anterior ejemplo es 4.
	argv = los carácteres. Ej: argv en el anterior ejemplo es 2.


1º hacer una temporal donde guardar los split de cada argc[i]
2º luego meto cada uno del split en una lista
3º free de doble puntero
