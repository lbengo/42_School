# Race Conditions

Una race condition ocurre cuando dos o más hilos o procesos acceden simultáneamente a un recurso compartido, como una variable, memoria o archivo, y al menos uno de ellos realiza una operación de escritura o modificación.

Las race conditions pueden ocurrir en programas paralelos o concurrentes, donde múltiples hilos o procesos se ejecutan en paralelo y comparten recursos. Estas condiciones pueden ser difíciles de detectar y solucionar, ya que su resultado puede ser inconsistente y depender de la concurrencia específica y el calendario de eventos.

Ejemplo:

```c
# include <stdio.h>
# include <unistd.h>
# include <pthread.h> // Librería que gestiona las funciones pthread

void *routine(void *nbr)
{
	int i = 0;
	int *x = (int *)nbr;
	while (i < 10000){
		(*x)++;
		i++;
	}
	return NULL;
}

int main(void)
{
	pthread_t	p1, p2;
	int 		x = 0;

	if (pthread_create(&p1, NULL, routine, &x)) // nuevo hilo
		return 1;
	if (pthread_create(&p2, NULL, routine, &x))
		return 2;
	if (pthread_join(p1, NULL)) // espera la ejecución del hilo
		return 3;
	if (pthread_join(p2, NULL))
		return 4;
	printf("Number of x = %d", x);
	return 0;
}
```
Resultado esperado:
```shell
Number of x = 20000
```

Resultados optenidos:
```shell
1º
Number of x = 19226

2º
Number of x = 10749

3º
Number of x = 13002
```

La prevención y solución de race conditions suelen implicar el uso de mecanismos de sincronización, como mutex, semáforos, variables de condición o barreras, para coordinar el acceso a los recursos compartidos y garantizar la coherencia y la consistencia en la ejecución del programa o sistema concurrente.

Es importante tener en cuenta y abordar las race conditions al desarrollar software concurrente o paralelo para evitar resultados incorrectos y comportamientos no deterministas.

Ejemplo de solución con mutex:

```c
# include <stdio.h>
# include <unistd.h>
# include <pthread.h> // Librería que gestiona las funciones pthread

pthread_mutex_t mutex;

void *routine(void *nbr)
{
	int i = 0;
	int *x = (int *)nbr;
	while (i < 10000){
		pthread_mutex_lock(&mutex); // espera a que el hilo no se esté ejecutando para prevenir el race condition
		(*x)++;
		i++;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(void)
{
	pthread_t	p1, p2;
	int 		x = 0;

	pthread_mutex_init(&mutex, NULL); // inicio del mutex
	if (pthread_create(&p1, NULL, routine, &x))
		return 1;
	if (pthread_create(&p2, NULL, routine, &x))
		return 2;
	if (pthread_join(p1, NULL))
		return 3;
	if (pthread_join(p2, NULL))
		return 4;
	pthread_mutex_destroy(&mutex); // finalización del mutex
	printf("Number of x = %d", x);
	return 0;
}
```
Resultado optenido:
```shell
Number of x = 20000
```
