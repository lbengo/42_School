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
int open(const char *camino, int flags);
int open(const char *camino, int flags, mode_t modo);
int close(int fd);
```

Los parámetros flags de la llamada al sistema `open` permite elegir el modo de acceso al fichero. Las constantes más comunes son:

|  Constantes  | Descripción                                                                                                        |
|:------------:|:------------------------------------------------------------------------------------------------------------------:|
|   O_RONLY    | Solo lectura                                                                                                       |
|   O_WRONLY   | Solo escritura                                                                                                     |
|    O_RDWR    | Lectura y escritura                                                                                                |
|   O_TRUNC    | Modo truncado. Abre el fichero y trunca su contenido a 0 cuando se abre, con el efecto de sobreescribir el fichero |
|   O_APPEND   | Modo apéndice. El desplazamiento del fichero se establece al final del mismo en cada escritura.                    |
|   O_CREAT    | Crea el fichero si aun no existe.                                                                                  |

**Abrir y leer el fichero**
Con el objetivo de leer este file descriptor se emplea la función `read`, de la biblioteca <unistd.h>




| Valor entero |      Nombre      | Constante simbólica  | Secuencia de archivos |
|:------------:|:----------------:|:--------------------:|:---------------------:|
|      0       | Entrada estándar |    STDIN_FILENO      |         stdin         |
|      1       | Salida estándar  |    STDOUT_FILENO     |         stdout        |
|      2       | Error estándar   |    STDERR_FILENO     |         stderr        |
