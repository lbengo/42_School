<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/ft_printfe.png" alt="ft_printf 42 project badge"/>
</p>

# Printf

***El objetivo del proyecto ft_printf es recrear la función printf de la biblioteca C.***

A través de este proyecto se aprende a emplear argumentos varíadicos. Y lo que es más importante, podrás desafiarte a estructurar el código de manera más eficiente, para que pueda ser extendido a diferentes casos de uso.

## Consideraciones técnicas
- Funciones permitidas: ```malloc```, ```free```, ```write```, ```va_start```, ```va_arg```, ```va_copy```, ```va_end```
- No implementar la gestión del buffer del ```printf()``` original.
- Especificadores a implementar: ```cspdiuxX%```
- Usar el comando ```ar``` para crear la librería. El uso de ```libtool``` esta prohibido.

## Cómo testear
> Ejecuta los siguientes comandos. Puedes sustituir el ```test.c``` por tu propio archivo de prueba.

```shell
# Clone the project and access the folder
git clone https://github.com/ampuEus/42School/tree/main/cursus/lvl0/Libft && cd Libft/

# Run Make so you can build the library
make

# Run Make with bonus if you want chained lists manipulation functions
make bonus

# Compile your main with the library, example:
clang main.c libft.a

# Execute your program
./a.out

# Clean output objects with
make fclean

# Well done!

$ git clone https://github.com/qingqingqingli/ft_printf
https://github.com/lbengo/42_School/Cursus/ft_printf
$ cd ft_printf
$ make
$ gcc test.c libftprintf.a
$ ./a.out
```
