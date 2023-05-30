## Función execve()

```c
int execve(const char *filename, char *const argv[], char *const envp[]);
```

### Descripción
La función execve() se utiliza para **ejecutar un programa externo desde dentro de un programa**.

- Filename (la ruta al archivo ejecutable): Se debe proporcionar la ruta al archivo ejecutable que se desea ejecutar. Esta ruta debe ser un puntero a una cadena de caracteres que contiene la ruta completa al archivo ejecutable.

	Para saber la ruta del archivo ejecutable, por ejemplo de 'ls' en el sistema, podemos ejecutar el siguiente comando en la terminal: `which ls`

	Este comando mostrará la ubicación exacta del archivo ejecutable. En este caso 'ls' se encuentra en la ruta '/bin/ls' del sistema.

- Argv (argumentos del programa): El segundo argumento es un array de punteros a cadenas de caracteres que representan los argumentos que se deben pasar al programa que se está ejecutando. El primer elemento del array debe contener el filename asociado al archivo ejecutable que se desea ejecutar. Tanto argv como envp tienen que terminar con un puntero NULL.

- Envp (variables de entorno): El tercer argumento es un array de punteros a cadenas de caracteres que representan las variables de entorno que se deben pasar al programa que se está ejecutando.

### Valor devuelto
En caso de éxito execve() no regresa mientas que en caso de error el valor devuelto es -1, y a la variable errno se le asigna un valor apropiado.

### Ejemplo:

```c
int	main(void)
{
	int val;

	char *args[] = { "/bin/ls", "-l", NULL };
	val = execve(args[0], args, NULL);
	if (val == -1)
		perror("Error");
	return (0);
}
```
