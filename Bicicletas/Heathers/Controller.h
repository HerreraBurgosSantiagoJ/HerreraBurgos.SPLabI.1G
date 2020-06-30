
/*1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
del mismo.
2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de las bicicletas.
3) Asignar tiempos: Se deberá hacer uso de la función map. la cual recibirá el linkedlist y una
función que asignará a la bicicleta un valor de tiempo entre 50 y 120 minutos calculado de
manera aleatoria se mostrará por pantalla el mismo.
4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan
bicicletas del tipo seleccionado.
5) Mostrar posiciones: Se deberá mostrar por pantalla un listado de las bicicletas ordenadas
por tipo y dentro de las del mismo tipo que aparezcan ordenadas por tiempo ascendente.
6) Guardar posiciones: Se deberá guardar el listado del punto anterior en un archivo de texto.
7) Salir.*/
int ctlr_load(LinkedList* this);
int ctlr_showList(LinkedList* this);
int ctlr_setRndTimes(LinkedList* this, int (*pFunc)(void*));
int ctlr_fillterType(LinkedList* this);
int ctlr_sortTypeShowPositions(LinkedList* this);
int ctlr_save(LinkedList* this);
