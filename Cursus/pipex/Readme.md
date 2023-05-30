<p align="center">
  <img src="../../42_badges/pipexe.png" alt="Push_Swap 42 project badge"/>
</p>

# Pipex

***El objetivo del proyecto pipex es recrear el funcionamiento de la redirección de shell y las pipes.***

Este programa debe tomar un archivo de entrada, ejecutar un comando en él, canalizar el resultado a otro comando y finalmente escribir el resultado en un archivo de salida. El propósito es que el programa funcione de manera indéntica al siguiente comando de shell:

```shell
$ < input_file command1 | command2 > output_file
```

## Cómo testear
Ejecuta los siguientes comandos.

```shell
$ git clone https://github.com/lbengo/42_School.git && cd 42_School/Cursus/pipex/
$ make bonus
```

### Ejecución normal de pipex

Pipex es capaz de ejecutar dos o más comandos de manera consecutiva. Para utilizarlo, debes realizar el siguiente comando:

```shell
$ ./pipex_bonus input_file command1 command2 ... commandx output_file
```

La salida generada será escrita en el archivo de salida que se especifique. En el caso de que dicho archivo ya exista, este será sobreescrito, reproduciendo así el comportamiento del siguiente comando de shell:

```shell
$ < input_file command1 | command2 | ... | command2 > output_file
```

Por ejemplo:

```shell
$ ./pipex_bonus inputfile.txt "grep x" | "wc -l" | ... | "cat -e" > outfile.txt
```

### Ejecución heredoc de pipex

También puedes ejecutar pipex con heredoc así:

```shell
$ ./pipex_bonus here_doc LIMITER command1 command2 output_file
```

A continuación, te pedirá introducir un texto que se utilizará como input para los comandos. En este caso, el archivo de salida no será sobreescrito, sino que se añadirá, lo cual reproduce el comportamiento del comando shell:

```shell
$  command1 << LIMITER | command2 >> output_file
```

## Cómo empezar

### 01. Conocer las funciones
- [execve()](./Readme/functions/execve())
- [fork()](./Readme/functions/fork())
- [pipe()](./Readme/functions/pipe())
- [dup() y dup2()](./Readme/functions/dup2())

### 02. Control de errores
- Solo puede haber 4 argumentos (4 o más en caso de bonus).
- El primer archivo debe existir y tener los permisos necesarios para leerse.

### 03. Ejecuta varios comandos
Después de comprender el funcionamiento de las funciones mencionadas anteriormente, se procedió a crear una función que permite ejecutar un comando. Para lograr esto, fue necesario comprender previamente el funcionamiento de la variable PATH del entorno. Esta variable almacena una lista de directorios donde el sistema operativo busca los ejecutables de comandos o programas.

Una vez que se ejecuta un comando, se implementó un bucle para establecer que la salida estándar (STDOUT) del comando anterior se convierta en la entrada estándar (STDIN) del siguiente. De esta manera, se logra ejecutar varios comandos en secuencia, canalizando así el resultado del primer comando hacia el siguiente.

### 04. Añade un file_in
***File_in normal***
Para ejecutar el primer comando en el archivo de entrada, se necesita redirigir la lectura del archivo hacia la entrada estándar (STDIN) del comando. Esto se logra mediante la utilización de la redirección de entrada. Al redirigir la entrada, el primer comando podrá leer el contenido del archivo como su entrada de datos.

***File_in here_doc***
Una alternativa adicional (bonus) es el uso de "here_doc", que no requiere de un archivo de entrada "file_in". En este caso, el usuario puede proporcionar directamente el texto de entrada en la terminal para ejecutar los comandos. Para lograr esto, se crea un archivo temporal en el que se guarda el texto de entrada y, una vez finalizado su uso, se elimina.

### 05. Añade un file_out
Por último, para enviar la salida estándar (STDOUT) al archivo de salida (file_out), fue necesario redirigir la salida del último comando hacia el archivo.

Es importante tener en cuenta la diferencia entre los operadores ">" y ">>":

- ">" (redirección de salida sobrescrita): Si utilizas el operador >, la salida del comando se redirige hacia el archivo especificado, sobrescribiendo cualquier contenido previo que pudiera tener. Si el archivo no existe, se crea.

- ">>" (redirección de salida agregada): Por otro lado, si utilizas el operador >>, la salida del comando se agrega al final del archivo especificado, preservando cualquier contenido existente. Si el archivo no existe, se crea.
