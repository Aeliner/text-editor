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

// Crea un texto vac�o
Texto CrearTexto();

// Inserta una nueva l�nea vac�a al final del texto.
TipoRetorno InsertarLinea(Texto &texto);

// Inserta una nueva l�nea vac�a en la posici�n indicada.
TipoRetorno InsertarLineaEnPosicion(Texto &texto, Posicion posicionLinea);

// Borra la l�nea en la posici�n indicada.
TipoRetorno BorrarLinea(Texto &texto, Posicion posicionLinea);

// Borra todas las l�neas del texto.
TipoRetorno BorrarTodo(Texto &texto);

// Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto &texto, Cadena palabraABorrar);

// Imprime el texto por pantalla.
TipoRetorno ImprimirTexto(Texto texto);

// Comprime las l�neas.
TipoRetorno ComprimirTexto(Texto &texto);

// Inserta una palabra en una l�nea en la posicion dada.
TipoRetorno InsertarPalabraEnLinea(Texto &texto, Posicion posicionLinea,
	Posicion posicionPalabra, Cadena palabraAIngresar);

// Inserta una palabra en una l�nea en la posicion dada y dentro de la l�nea en 
//la posici�n posicionPalabra. Desplaza todas las palabras que se encuentran a 
//partir de la posici�n posicionPalabra un lugar hacia adelante. Si al ingresar 
//la palabra se superara la cantidad m�xima de palabras por l�nea (MAX_CANT_PALABRAS_X_LINEA), 
//el desplazamiento afectar�a a la l�nea siguiente y eventualmente a las posteriores, 
//llegando incluso a ser necesario en el caso extremo agregar una nueva l�nea al 
//final del documento con una sola palabra (si todas las l�neas posteriores estuvieran llenas).
TipoRetorno InsertarPalabraYDesplazar(Texto &texto, Posicion posicionLinea,
	Posicion posicionPalabra, Cadena palabraAIngresar);

// Borra la palabra de una linea que se encuentra en la posici�n dada.
TipoRetorno BorrarPalabraEnLinea(Texto &texto, Posicion posicionLinea,
	Posicion posicionPalabra);

// Borra todas las ocurrencias de una palabra en la l�nea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto &texto, Posicion posicionLinea,
	Cadena palabraABorrar);

// Imprime la l�nea por pantalla.
TipoRetorno ImprimirLinea(Texto texto, Posicion posicionLinea);
void insertarInicioU(Texto &, Cadena);
//------------------Para Parte 2------------------------
// Muestra todas las l�neas del texto, pero exhibiendo solamente las palabras
// que no se encuentran en el dicionario.
// Se debe imprimir el n�mero de l�nea. Cuando el texto no tiene l�neas se debe
// mostrar el mensaje "Texto vacio".
TipoRetorno ImprimirTextoIncorrecto(Texto texto, Diccionario D);

//------------------Para Parte 2------------------------
// Imprime las �ltimas palabras ingresadas.
// Imprime las �ltimas MAX_CANT_ULTIMAS_PALABRAS, a lo sumo, palabras ingresadas
// al texto (no al diccionario), a�n cuando estas palabras pudieran haber sido
// luego eliminadas.
// MAX_CANT_ULTIMAS_PALABRAS es una constante del sistema.
// El orden en el que se muestran las palabras debe ser el siguiente: primero la
// �ltima palabra ingresada, luego la pen�ltima, y as� sucesivamente.
// Si nunca se ingresaron palabras se debe mostrar "No se ingresaron palabras".
TipoRetorno ImprimirUltimasPalabras(Texto texto);

TipoRetorno ComprimirTextoViejo(textoViejo &);

TipoRetorno BorrarLineaVieja(textoViejo &, Posicion);
#endif
