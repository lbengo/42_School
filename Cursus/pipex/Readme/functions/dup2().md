## Función dup() y dup2()

### Nombre
```
dup, dup2 - duplica un descriptor de fichero
```

### Sinopsis

```c
#include <unistd.h>

int dup(int oldfd);
int dup2(int oldfd, int newfd);
```

### Descripción

**dup** y **dup2** crea una copia del descriptor de fichero oldfd en newfd.

Después  de  una  llamada  a dup o dup2 con éxito, los descriptores antiguo y nuevo pueden usarse indiferentemente. Comparten candados (locks), indicadores de posición de fichero  y banderas  (flags); por ejemplo, si la posición del fichero se modifica usando lseek en uno de los descriptores, la posición en el otro también cambia.

Sin embargo los descriptores no comparten la bandera close-on-exec, (cerrar-al-ejecutar).

**dup** usa el descriptor libre con menor numeración posible como nuevo descriptor.

**dup2** hace que newfd sea la copia de oldfd, cerrando primero newfd si es necesario.


### Valor devuelto

**dup** y **dup2** devuelven el valor del nuevo descriptor, ó -1 si ocurre algún error, en cuyo caso errno toma un valor apropiado.
