# Pipex - In Process

## To do
- mirar como funciona execve()
- mirar como funciona pipe()
- mirar como funciona el PATH del enviroment y una parsearlo (la funcion access() con el flag X_OK te puede ayudar para encontrar el binario)


## Función execve()

```shell
$ int execve(const char *filename, char *const argv[], char *const envp[]);
```

### Descripción
La función execve() es una llamada al sistema en el lenguaje de programación C que se utiliza para **ejecutar un programa externo desde dentro de un programa**.

- Filename (la ruta al archivo ejecutable): Se debe proporcionar la ruta al archivo ejecutable que se desea ejecutar. Esta ruta debe ser un puntero a una cadena de caracteres que contiene la ruta completa al archivo ejecutable.

	Para saber la ruta del archivo ejecutable, por ejemplo de 'ls' en el sistema, podemos ejecutar el siguiente comando en la terminal: `which ls`

	Este comando mostrará la ubicación exacta del archivo ejecutable. En este caso 'ls' se encuentra en la ruta '/bin/ls' del sistema.

- Argv (argumentos del programa): El segundo argumento es un array de punteros a cadenas de caracteres que representan los argumentos que se deben pasar al programa que se está ejecutando. El primer elemento del array debe ser el nombre del programa que se está ejecutando.

- Envp (variables de entorno): El tercer argumento es un array de punteros a cadenas de caracteres que representan las variables de entorno que se deben pasar al programa que se está ejecutando.

### Valor devuelto
En caso de éxito execve() no regresa mientas que en caso de error el valor devuelto es -1, y a la variable errno se le asigna un valor apropiado.

### Ejemplo:

```shell
$ int	main()
$ {
$ 	char *args[] = { "/bin/ls", "-l", NULL };
$ 	execve(args[0], args, NULL);
$ 	return 0;
$ }
```

### envp[]

