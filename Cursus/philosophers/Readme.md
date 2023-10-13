<p align="center">
  <img src="../../42_badges/philosopherse.png" alt="Philosophers 42 project badge"/>
</p>

# Philosophers

***El objetivo del proyecto philosophers es resolver el problema de la cena de filósofos (dining philosophers problem), usando sólo hilos y mutex.***

Este programa deberá solventar el famoso problema de la cena de filósofos (dining philosophers problem), un problema clásico de las ciencias de la computación propuesto por Edsger Dijkstra en 1965 para representar el problema de la sincronización de procesos en un sistema operativo. Para ello, se debe aprender sobre programación concurrente, sus problemas y como solventarlos.


## Enunciado del ejercicio

### Problema de la cena de filósofos (dining philosophers problem)

Cinco filósofos están sentados alrededor de una mesa y pasan su vida cenando y pensando. Cada filósofo tiene un plato de fideos y un tenedor a la izquierda de su plato. Para comer los fideos son necesarios dos tenedores y cada filósofo sólo puede tomar el tenedor que está a su izquierda y el de su derecha. Si cualquier filósofo toma un tenedor y el otro está ocupado, se quedará esperando, con el tenedor en la mano, hasta que pueda tomar el otro tenedor, para luego empezar a comer. El resto de filósofos que no está ni comiendo ni con un tenedor en la mano está pensando.

El problema consiste en crear un algoritmo que permita comer a los filósofos.


<p align="center">
  <img src="Readme_utils/Illustration_dining_philosophers_problem.png" alt="Illustration dining philosophers problem"/>
</p>

### Instruciones generales

- El programa deberá aceptar los siguientes argumentos:
	- number_of_philosophers: es el número de filósofos, pero también el número de tenedores.
	- time_to_die (en milisegundos): si un filósofo no empieza a comer en time_to_die milisegundos desde el comienzo de su ultima comida o desde el principio de la simulación, este morirá.
	- time_to_eat (en milisegundos): es el tiempo que tiene un filósofo para comer. Durante ese tiempo, tendrá los tenedores ocupados.
	- time_to_sleep (en milisegundos): es el tiempo que tiene un filósofo para dormir.
	- number_of_times_each_philosopher_must_eat (argumento opcional): si todos los filósofos comen al menos number_of_times_each_philosopher_must_eat veces, la simulación se detendrá. Si no se especifica, la simulación se detendrá con la muerte de un filósofo.

- Cualquier cambio de estado de un filósofo debe tener el siguiente formato:
	- timestamp_in_ms X has taken a fork
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died
	Reemplaza timestamp_in_ms con la marca de tiempo actual en milisegundos y X con el numero del filósofo.

- No se puede tener más de 10ms entre la muerte de un filósofo y el momento en el que se imprime su muerte

- Para más información sobre el proyecto mira el <a href=Readme_utils/Enunciado.pdf>enunciado</a>.









---------

**Race Conditions**

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


