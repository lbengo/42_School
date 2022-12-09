<p align="center">
  <img src="https://github.com/lbengo/42_School/blob/main/42_badges/get_next_linee.png" alt="get_next_line 42 project badge"/>
</p>

# Get Next Line

***El objetivo del proyecto ft_printf es programar una función que devuelva una línea leída de un file descriptor.***

Esta función devuelve una sola línea de un descriptor de archivo dado. Al llamar a la función en bucle, get_next_line devuelve todo el contenido de un fichero, línea a línea hasta llegar al final. Y además, puede compilarse especificando el tamaño de búfer. A través de este proyecto aprendemos a leer de un descriptor de fichero e introduce el concepto de variables estáticas en la programación en C.

## Consideraciones técnicas
- Funciones permitidas: `malloc`, `free`, `read`
- La línea devuelta debe acabar con \n, excepto si ha llegado al final del archivo y este no termina con \n.
- Si no hay nada más que leer o ha ocurrido un error, la función devuelve NULL.

## Cómo testear
Ejecuta los siguientes comandos.
```shell
$ git clone git@github.com:lbengo/42_School.git && cd 42_School/Cursus/get_next_line/
$ gcc get_next_line.c get_next_line_utils.c main.c
$ ./a.out
```
> Puedes sustituir el `main.c` por tu propio archivo de prueba.

## Cómo empezar

### 01. Crea una función que lea un fichero

**Abrir y leer el fichero**

Para trabajar con un fichero primero hay que abrirlo con la función `open`, la cual devuelve un file descriptor o -1 en caso de error. Y finalmente, habría que cerrar el fichero con la función `close` para liberar los recursos que se tengan asignados.

```c
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
int close(int fd);
```

Los parámetros flags de la llamada al sistema `open` permite elegir el modo de acceso al fichero. Las constantes más comunes son:

<table>
  <thead>
    <tr>
      <th align="left">Constantes</th>
      <th align="left">Descripción</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="left">O_RONLY</td>
      <td align="left">Solo lectura.</td>
    </tr>
    <tr>
      <td align="left">O_WRONLY</td>
      <td align="left">Solo escritura.</td>
    </tr>
    <tr>
      <td align="left">O_RDWR</td>
      <td align="left">Lectura y escritura.</td>
    </tr>
    <tr>
      <td align="left">O_TRUNC</td>
      <td align="left">Modo truncado. Abre el fichero y trunca su contenido a 0 cuando se abre, con el efecto de sobreescribir el fichero.</td>
    </tr>
    <tr>
      <td align="left">O_APPEND</td>
      <td align="left">Modo apéndice. El desplazamiento del fichero se establece al final del mismo en cada escritura.</td>
    </tr>
    <tr>
      <td align="left">O_CREAT</td>
      <td align="left">Crea el fichero si aun no existe.</td>
    </tr>
  </tbody>
</table>

Por ejemplo, se podría abrir un fichero y leerlo de la siguiente forma:

```c
open("file", O_RDONLY);
```

**Leer el fichero**

Con el objetivo de leer este file descriptor se emplea la función `read`, de la biblioteca <unistd.h>

```c
ssize_t read(int fd, void *buf, size_t count);
```
Los parámetros son los siguientes:
- fd: el descriptor de fichero a leer.
- buf: un puntero hacia una zona de memoia donde almacenar temporalmente los carácteres leídos.
- count: un tamaño en bytes a leer, es decir, el número de carácteres a leer.

Esta función devuelve el número de carácteres leidos, 0 si ha llegado al final del fichero, o -1 en caso de error.

### 02. Modificar el código para que encuentre y retorne una linea

**Encontrar y retornar una línea**

Tras haber creado una función que lea el fichero completo, se modifica el código para que únicamente lea y retorne hasta el salto de linea (\n) o final del fichero.

> Mi recomendación mientras se prueba esta función es emplear un buffer_size menor a la línea leída.

**Guardar datos que no vayan a retornarse**

Por otro lado, en el caso de que el buffer_size sea mayor que la línea leida, la segunda vez que se ejecute la función no retornará lo que se ha leido anteriormente. Por ello, se ha de añadir estos datos que no corresponden con la linea a retornar en una VARIABLE ESTÁTICA.

Una variable local en el momento en que acaba la subrutina/función en la que se haya declarado se eliminan las referencias de la pila y se quitan de la memoria. Sin embargo, una variable estática persiste hasta el final del programa, independientemente de donde se haya declarado.


---
Made by lbengoec: lbengoec@student.42urduliz.com | LinkedIn: [lbengoec](https://www.linkedin.com/in/laura-bengoechea-navarro/)
