<p align="center">
  <img src="https://github.com/lbengo/42_School/blob/main/42_badges/libfte.png" alt="ft_printf 42 project badge"/>
</p>


# Libft

***El objetivo del proyecto Libft es programar una librería en C y varias funciones genéricas que se utilizarán posteriormente en futuros proyectos de 42.***

A través de este proyecto se aprende como funcionan algunas funciones estándar de libc, codificarlas desde cero y a emplearlas.


## Consideraciones técnicas
- Funciones permitidas: `malloc`, `free`, `write`
- Usar el comando `ar` para crear la librería. El uso de `libtool` esta prohibido.

## Cómo testear
Ejecuta los siguientes comandos.
```shell
$ git clone https://github.com/lbengo/42_School/tree/main/Cursus/Libft
$ cd Libft/
$ make
$ gcc test.c libft.a
$ ./a.out
```
> Puedes sustituir el `test.c` por tu propio archivo de prueba.
Para testear los bonus hay que cambiar `make` por `make bonus`

## Funciones incluidas

<table>
    <thead>
        <tr>
            <th colspan=3><h3>Funciones obligatorias</h3></a></th>
        </tr>
        <tr>
            <th colspan=2><h4>Funciones para verificar y manipular caracteres</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_isalnum.c>ft_isalnum</a></td>
            <td>Comprueba si el carácter pasado es alfanumérico.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_isalpha.c>ft_isalpha</a></td>
            <td>Comprueba si el carácter pasado es alfabético.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_isascii.c>ft_isascii</a></td>
            <td>Comprueba si el carácter pasado es ASCII.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_isdigit.c>ft_isdigit</a></td>
            <td>Comprueba si el carácter pasado es un número decimal.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_isprint.c>ft_isprint</a></td>
            <td>Comprueba si el carácter pasado se puede imprimir en consola.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_tolower.c>ft_tolower</a></td>
            <td>Convierte las letras mayúsculas a minúsculas.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_toupper.c>ft_toupper</a></td>
            <td>Convierte las letras minúsculas a mayúsculas.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=2><h4>Funciones para manipular strings</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_split.c>ft_split</a></td>
            <td>Reserva un array de strings resultante de separar la string <i>s</i> en substrings utilizando el caracter <i>c</i> como delimitador. El array debe terminar con un puntero NULL.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strchr.c>ft_strchr</a></td>
            <td>Busca la primera aparición del carácter <i>c</i> (un carácter sin signo) en la cadena.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_striteri.c>ft_striteri</a></td>
            <td>Aplica una función a cada carácter de la cadena.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strjoin.c>ft_strjoin</a></td>
            <td>Devuelve una nueva cadena, que es el resultado de la concatenación de <i>s1</i> y <i>s2</i>.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strlcat.c>ft_strlcat</a></td>
            <td>Agrega la cadena <i>src</i> al final de <i>dst</i>. Agregará como máximo <i>dstsize - strlen (dst) - 1</i> caracteres.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strlcpy.c>ft_strlcpy</a></td>
            <td>Copia hasta el carácter <i>dstsize - 1</i> de la cadena <i>src</i> a <i>dst</i>.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strlen.c>ft_strlen</a></td>
            <td>Calcula la longitud de la cadena pero sin incluir el carácter nulo de terminación.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strmapi.c>ft_strmapi</a></td>
            <td>Aplica una función a cada carácter de la cadena <i>s</i> para crear una nueva cadena.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strncmp.c>ft_strncmp</a></td>
            <td>Compara como máximo los primeros <i>n</i> bytes de <i>str1</i> y <i>str2</i>.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strnstr.c>ft_strnstr</a></td>
            <td>Localiza la primera aparición de la cadena <i>little</i> terminada en nulo en la cadena <i>big</i>, donde no se buscan más de <i>len</i> caracteres.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strrchr.c>ft_strrchr</a></td>
            <td>Busca la última aparición del carácter <i>c</i> (un carácter sin signo) en la cadena.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strtrim.c>ft_strtrim</a></td>
            <td>Devuelve una copia de <i>s1</i> con los caracteres especificados en <i>set</i> eliminados del principio y el final de la cadena.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_substr.c>ft_substr</a></td>
            <td>Devuelve una subcadena de la cadena <i>s</i>. La subcadena comienza en el índice <i>start</i> y tiene el tamaño máximo <i>len</i>.</td>
        </tr>
    </tbody>
	<thead>
        <tr>
            <th colspan=2><h4>Funciones para manipular memoria</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_calloc.c>ft_calloc</a></td>
            <td>Asigna la memoria solicitada inicializada a cero bytes.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_bzero.c>ft_bzero</a></td>
            <td>Borra los datos en los <i>n</i> bytes del bloque de memoria. (Escribe ceros, esto es, apunta a NULL)</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_memchr.c>ft_memchr</a></td>
            <td>Busca la primera aparición del carácter <i>c</i> (siendo un carácter sin signo) en los primeros <i>n</i> bytes de la cadena.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_memcmp.c>ft_memcmp</a></td>
            <td>Compara los primeros <i>n</i> bytes de <i>str1</i> y <i>str2</i>.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_memcpy.c>ft_memcpy</a></td>
            <td>Copia <i>n</i> caracteres de <i>src</i> a <i>dest</i>.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_memmove.c>ft_memmove</a></td>
            <td>Copia <i>n</i> caracteres de <i>src</i> a <i>dest</i>. (Manera no destructiva)</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_memset.c>ft_memset</a></td>
            <td>Copia el carácter <i>c</i> (un carácter sin signo) a los primeros <i>n</i> caracteres de la cadena.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_strdup.c>ft_strdup</a></td>
            <td>Devuelve un puntero a una cadena de bytes terminada en nulo, que es un duplicado de la cadena.</td>
        </tr>
    </tbody>
	<thead>
        <tr>
            <th colspan=2><h4>Funciones para números</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_atoi.c>ft_atoi</a></td>
            <td>Convierte la cadena a un número entero (tipo int).</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_itoa.c>ft_itoa</a></td>
            <td>Convierte el int a una cadena (tipo char *).</td>
        </tr>
    </tbody>
		<thead>
        <tr>
            <th colspan=2><h4>Funciones para escribir en un descriptor de archivo</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_putchar_fd.c>ft_putchar_fd</a></td>
            <td>Envía el carácter <i>c</i> al descriptor de archivo dado.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_putendl_fd.c>ft_putendl_fd</a></td>
            <td>Envía la cadena <i>s</i> al descriptor de archivo dado, seguida de un salto de línea.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_putnbr_fd.c>ft_putnbr_fd</a></td>
            <td>Envía el entero <i>n</i> al descriptor de archivo dado.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_putstr_fd.c>ft_putstr_fd</a></td>
            <td>Envía la cadena <i>s</i> al descriptor de archivo dado.</td>
        </tr>
    </tbody>
</table>
<table>
    <thead>
        <tr>
            <th colspan=3><h3>Funciones bonus</h3></a></th>
        </tr>
        <tr>
            <th colspan=2><h4>Funciones para la manipulación de listas</h4></th>
        </tr>
        <tr>
            <th>Nombre</th>
            <th>Descripción</th>
        </tr>
    </thead>
    <tbody>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstladd_back_bonus.c>ft_lstladd_back</a></td>
            <td>Agrega el elemento al final de la lista.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstadd_front_bonus.c>ft_lstadd_front</a></td>
            <td>Agrega el elemento al inicio de la lista.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstclear_bonus.c>ft_lstclear</a></td>
            <td>Elimina y libera el elemento dado y todos los sucesores de ese elemento, usando una función dada y <i>free()</i></td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstdelone_bonus.c>ft_lstdelone</a></td>
            <td>Toma como parámetro un elemento y libera la memoria del contenido del elemento usando una función dada como parámetro y libera el elemento.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstiter_bonus.c>ft_lstiter</a></td>
            <td>Itera la lista y aplica una función al contenido de cada elemento.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstlast_bonus.c>ft_lstlast</a></td>
            <td>Devuelve el último elemento de la lista.</td>
        </tr>
		<tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstmap_bonus.c>ft_lstmap</a></td>
            <td>Itera la lista y aplica una función al contenido de cada elemento. Crea una nueva lista resultante de las sucesivas aplicaciones de la función. Se utiliza una función <i>del</i> para eliminar el contenido de un elemento si es necesario.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstnew_bonus.c>ft_lstnew</a></td>
            <td>Devuelve un nuevo elemento.</td>
        </tr>
        <tr>
            <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/Libft/ft_lstsize_bonus.c>ft_lstsize</a></td>
            <td>Cuenta el número de elementos en una lista.</td>
        </tr>
	</tbody>
</table>

---
Made by lbengoec: lbengoec@student.42urduliz.com | LinkedIn: [lbengoec](https://www.linkedin.com/in/laura-bengoechea-navarro/)
