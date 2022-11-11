<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/ft_printfe.png" alt="ft_printf 42 project badge"/>
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
$ git clone https://github.com/lbengo/42_School/tree/main/Cursus/ft_printf
$ cd ft_printf/
$ make
$ gcc test.c libft.a
$ ./a.out
```
> Puedes sustituir el `test.c` por tu propio archivo de prueba.

## Cómo empezar

### 01. Makefile
Realiza un makefile para que las pruebas durante el ejercicio se realicen más rapidamente.

### 02. Función ft_printf
Comienza la función principal del ft_printf comprendiendo como emplear las funciones variádicas.

**02.a. ¿Qué es una función variádica?**

Una función varíadica son funciones que pueden recibir un <ins>número indefinido de argumentos</ins>. Estas poseen al menos una variable fija, utilizada para especificar los argumentos, y el resto de parámetros se definen mediante una elipsis ("...").

```c
int funcion_variadica(int <variable fija>, ...);
```
>  Los data types int pueden sustituirse por cualquier otro tipo.


**02.b. ¿Cómo acceder a los argumentos de la función?**

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
