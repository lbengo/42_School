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
  <img src="Readme/imgs/Illustration_dining_philosophers_problem.png" alt="Illustration dining philosophers problem" width="40%"/>
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

- Para más información sobre el proyecto mira el <a href=Readme/imgs/Enunciado.pdf>enunciado</a>.


## Cómo testear
Ejecuta los siguientes comandos.
```shell
$ git clone https://github.com/lbengo/42_School.git && cd 42_School/Cursus/philosophers
$ make
$ ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

> Puedes sustituir los números por los que prefieras. Los filósofos no pueden ser mas de 200 y el "time_to_die" y "time_to_sleep" no pueden ser inferior a 60 ms.

Ejemplos:

- ./philo 5 800 200 200 : nadie debe morir.
- ./philo 4 410 200 200 : nadie debe morir.
- ./philo 4 310 200 100 : un filósofo debe morir.


## Cómo empezar

### 01. Control de errores
Errores a gestionar
- Todos los argumentos de entrada deben ser positivos.
- El número de argumentos debe ser 4 o 5.

### 02. Parseo
En primer lugar se crean varias estructuras: la estructura `rules` que posea los argumentos y las variables que se van a emplear en el proyecto como el array de tenedores; Y otra estructura de `philo`, la cual posee variables necesarias de cada filósofo y la dirección de memoria de la estructura `rules`. Tras la realización de varios parseos, esta es la que se ha encontrado más adecuada ya que no genera variables innecesarias.

Asimismo, en el parseo se crean los threads y mutex. Sin embargo, para trabajar con ellas es necesario primeramente conocer que son las <a href=Readme/theory/Race_Conditions.md>race conditions</a>.

### 03. Implementación de la rutina
Como todos los filósofos comenzarían a comer cogiendo el tenedor de su izquierda, no permitirian comer a nadie ya que necesitan el de su derecha que está ocupado por otro filósofo. Es por lo que se ha dividido en dos: los filósofos pares comen primero y los impares esperan.

El siguiente paso del hilo del filósofo es comer. Para ello, primero hacen un mutex en el que cogen el tenedor de la izquierda y, a continuación, otro mutex con el de su derecha. Una vez tienen ambos tenedores, comienzan a comer. Y una vez terminan, liberan estos mutex para que los filósofos de sus costados puedan comer.

Tras terminar de comer, los filósofos duermen. Y una vez acaban esperan pensando hasta que puedan volver a comer.




