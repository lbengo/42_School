## Función fork()

```shell
pid_t fork(void);
```

### Descripción
La llamada al sistema Fork crea un nuevo proceso llamado proceso hijo, que es una copia exacta del proceso padre que lo creó.

- Tienen PIDs diferentes.
- Corren en espacios de memoria separados.

Nota: cuando se mata al hijo pero no al padre, este permanecerá zombi. Es decir, este habrá terminado pero quedará de alguna manera representado en el sistema, almacenando algunos recursos. Sin embargo, al contrario no se produce esta situación.

### Valor devuelto
- En caso de exito:
	- Retorno al padre: PID del hijo.
	- Retorno al hijo: 0.
- Si hay errores:
	- Retorno al padre: -1
	- (el hijo no es creado)

### Ejemplo 01:

```c
int	main(void)
{
	fork();
	printf("Hello\n");
	return (0);
}
```
```bash
Hello
Hello
```

### Ejemplo 02:

```c
void forexample(void)
{
	int pid = fork();
	int x = 1;

	// instrucciones que tanto el padre como el hijo harán

	if (pid >= 0)
	{
		// instrucciones que solo el proceso padre hará
		printf("Parent has x = %d\n", --x);
	}
	if (pid == 0)
	{
		// instrucciones que solo el proceso hijo hará
		printf("Child has x = %d\n", ++x);
	}
}

int	main(void)
{
	forexample();
	return (0);
}
```
```bash
Parent has x = 0
Child has x = 2
```
