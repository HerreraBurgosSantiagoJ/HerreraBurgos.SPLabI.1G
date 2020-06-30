
/*1) Cargar archivo: Se pedir� el nombre del archivo y se cargar� en un linkedlist los elementos
del mismo.
2) Imprimir lista: Se imprimir� por pantalla la tabla con los datos de las bicicletas.
3) Asignar tiempos: Se deber� hacer uso de la funci�n map. la cual recibir� el linkedlist y una
funci�n que asignar� a la bicicleta un valor de tiempo entre 50 y 120 minutos calculado de
manera aleatoria se mostrar� por pantalla el mismo.
4) Filtrar por tipo: Se deber� generar un archivo igual al original, pero donde solo aparezcan
bicicletas del tipo seleccionado.
5) Mostrar posiciones: Se deber� mostrar por pantalla un listado de las bicicletas ordenadas
por tipo y dentro de las del mismo tipo que aparezcan ordenadas por tiempo ascendente.
6) Guardar posiciones: Se deber� guardar el listado del punto anterior en un archivo de texto.
7) Salir.*/
int ctlr_load(LinkedList* this);
int ctlr_showList(LinkedList* this);
int ctlr_setRndTimes(LinkedList* this, int (*pFunc)(void*));
int ctlr_fillterType(LinkedList* this);
int ctlr_sortTypeShowPositions(LinkedList* this);
int ctlr_save(LinkedList* this);
