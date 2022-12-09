<p align="center">
  <img src="https://github.com/lbengo/42_School/blob/main/42_badges/ft_printfe.png" alt="ft_printf 42 project badge"/>
</p>

# Printf

***El objetivo del proyecto ft_printf es recrear la función printf de la biblioteca C.***

A través de este proyecto se aprende a emplear argumentos varíadicos. Y lo que es más importante, podrás desafiarte a estructurar el código de manera más eficiente, para que pueda ser extendido a diferentes casos de uso.

## Consideraciones técnicas
- Funciones permitidas: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
- No implementar la gestión del buffer del `printf()` original.
- Especificadores a implementar: `cspdiuxX%`
- Usar el comando `ar` para crear la librería. El uso de `libtool` esta prohibido.

## Cómo testear
Ejecuta los siguientes comandos.
```shell
$ git clone git@github.com:lbengo/42_School.git && cd 42_School/Cursus/ft_printf/
$ make
$ gcc test.c libftprintf.a
$ ./a.out
```
> Puedes sustituir el `test.c` por tu propio archivo de prueba.

## Cómo empezar

### 01. Crea un Makefile.
Realiza un [makefile](https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/Makefile) para que las pruebas durante el ejercicio se realicen más rapidamente.

### 02. Desarrolla la función principal ft_printf.
Comienza la función [ft_printf](https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_printf.c) comprendiendo como emplear las funciones variádicas.

**¿Qué es una función variádica?**

Una función varíadica son funciones que pueden recibir un <ins>número indefinido de argumentos</ins>. Estas poseen al menos una variable fija, utilizada para especificar los argumentos, y el resto de parámetros se definen mediante una elipsis ("...").

```c
int funcion_variadica(int <variable fija>, ...);
```
>  Los data types int pueden sustituirse por cualquier otro tipo.


**¿Cómo acceder a los argumentos de la función?**

Con el objetivo de acceder a estos argumentos se emplean una serie de macros:

- `va_list` Se emplea con el objetivo de declarar la variable donde se almacenarán los argumentos de la función variática.
- `va_start` Introduce dentro de la variable declarada anteriormente los parámetros que hayan pasado en la función.
- `va_arg` Accede al siguiente argumento de la función variádica.
- `va_end` Finaliza el acceso a los argumentos.

Ejemplo:
```c
#include <stdio.h>
#include <stdarg.h> // Librería que gestiona las variádicas

void variadic_test(char const *format, ...)
{
  va_list arg; // Declara la variable arg
  va_start (arg, format); // Introduce dentro de la variable arg los parámetros a partir de format

  // Ir recorriendo los argumentos
  printf("%c", va_arg(arg, int));
  printf("%s", va_arg(arg, char *));
  printf("%d", va_arg(arg, int));

  va_end(arg); //Finaliza
}

int main(void)
{
  variadic_test("<variable fija>", 'V', "ariadic", 1234);
  return (0);
}
```
Salida:
```shell
Variadic1234%
```

### 03. Añade los especificadores a la función.
Tras haber realizado la función principal, se implementan las siguientes conversiones a la misma.

<table>
<thead>
  <tr>
    <th>Especificador</th>
    <th>Función empleada</th>
    <th>Salida</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>%c</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putchar.c>ft_putchar</a></td>
    <td>Imprime un solo carácter</td>
  </tr>
  <tr>
    <td>%s</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putstr.c>ft_putstr</a></td>
    <td>Imprime un string</td>
  </tr>
  <tr>
    <td>%p</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putpointer.c>ft_putpointer</a></td>
    <td>La dirección del puntero (void *) dado como argumento se imprime en formato hexadecimal</td>
  </tr>
  <tr>
    <td>%d</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putnbr_10.c>ft_putnbr_10</a></td>
    <td>Imprime un número decimal (base 10)</td>
  </tr>
  <tr>
    <td>%i</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putnbr_10.c>ft_putnbr_10</a></td>
    <td>Imprime un entero en base 10</td>
  </tr>
  <tr>
    <td>%u</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putnbr_10_u.c>ft_putnbr_10_u</a></td>
    <td>Imprime un número decimal sin signo</td>
  </tr>
  <tr>
    <td>%x</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putnbr_16.c>ft_putnbr_16</a></td>
    <td>Imprime un número hexadecimal en minúsculas</td>
  </tr>
  <tr>
    <td>%X</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putnbr_16.c>ft_putnbr_16</a></td>
    <td>Imprime un número hexadecimal en mayúsculas</td>
  </tr>
  <tr>
    <td>%%</td>
    <td><a href=https://github.com/lbengo/42_School/blob/main/Cursus/ft_printf/ft_putchar.c>ft_putchar</td>
    <td>Para imprimir el símbolo del porcentaje</td>
  </tr>
</tbody>
</table>

---
Made by lbengoec: lbengoec@student.42urduliz.com | LinkedIn: [lbengoec](https://www.linkedin.com/in/laura-bengoechea-navarro/)

