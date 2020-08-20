#ifndef TEXTO_H
#define TEXTO_H

#include "Constantes.h"
#include "Palabras.h"
#include "Diccionario.h"


struct _textoViejo {
	struct _palabra *priP;
	struct _textoViejo *sigL;
};
typedef _textoViejo *textoViejo;

struct _texto{
	struct _pila *pilaP;
	struct _textoViejo *textoViejo;
};
 typedef _texto *Texto;

// Crea un texto vacío
Texto CrearTexto();

// Inserta una nueva línea vacía al final del texto.
TipoRetorno InsertarLinea(Texto &texto);

// Inserta una nueva línea vacía en la posición indicada.
TipoRetorno InsertarLineaEnPosicion(Texto &texto, Posicion posicionLinea);

// Borra la línea en la posición indicada.
TipoRetorno BorrarLinea(Texto &texto, Posicion posicionLinea);

// Borra todas las líneas del texto.
TipoRetorno BorrarTodo(Texto &texto);

// Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto &texto, Cadena palabraABorrar);

// Imprime el texto por pantalla.
TipoRetorno ImprimirTexto(Texto texto);

// Comprime las líneas.
TipoRetorno ComprimirTexto(Texto &texto);

// Inserta una palabra en una línea en la posicion dada.
TipoRetorno InsertarPalabraEnLinea(Texto &texto, Posicion posicionLinea,
	Posicion posicionPalabra, Cadena palabraAIngresar);

// Inserta una palabra en una línea en la posicion dada y dentro de la línea en 
//la posición posicionPalabra. Desplaza todas las palabras que se encuentran a 
//partir de la posición posicionPalabra un lugar hacia adelante. Si al ingresar 
//la palabra se superara la cantidad máxima de palabras por línea (MAX_CANT_PALABRAS_X_LINEA), 
//el desplazamiento afectaría a la línea siguiente y eventualmente a las posteriores, 
//llegando incluso a ser necesario en el caso extremo agregar una nueva línea al 
//final del documento con una sola palabra (si todas las líneas posteriores estuvieran llenas).
TipoRetorno InsertarPalabraYDesplazar(Texto &texto, Posicion posicionLinea,
	Posicion posicionPalabra, Cadena palabraAIngresar);

// Borra la palabra de una linea que se encuentra en la posición dada.
TipoRetorno BorrarPalabraEnLinea(Texto &texto, Posicion posicionLinea,
	Posicion posicionPalabra);

// Borra todas las ocurrencias de una palabra en la línea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto &texto, Posicion posicionLinea,
	Cadena palabraABorrar);

// Imprime la línea por pantalla.
TipoRetorno ImprimirLinea(Texto texto, Posicion posicionLinea);
void insertarInicioU(Texto &, Cadena);
//------------------Para Parte 2------------------------
// Muestra todas las líneas del texto, pero exhibiendo solamente las palabras
// que no se encuentran en el dicionario.
// Se debe imprimir el número de línea. Cuando el texto no tiene líneas se debe
// mostrar el mensaje "Texto vacio".
TipoRetorno ImprimirTextoIncorrecto(Texto texto, Diccionario D);

//------------------Para Parte 2------------------------
// Imprime las últimas palabras ingresadas.
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS, a lo sumo, palabras ingresadas
// al texto (no al diccionario), aún cuando estas palabras pudieran haber sido
// luego eliminadas.
// MAX_CANT_ULTIMAS_PALABRAS es una constante del sistema.
// El orden en el que se muestran las palabras debe ser el siguiente: primero la
// última palabra ingresada, luego la penúltima, y así sucesivamente.
// Si nunca se ingresaron palabras se debe mostrar "No se ingresaron palabras".
TipoRetorno ImprimirUltimasPalabras(Texto texto);

TipoRetorno ComprimirTextoViejo(textoViejo &);

TipoRetorno BorrarLineaVieja(textoViejo &, Posicion);
#endif
