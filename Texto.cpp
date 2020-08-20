#include "Texto.h"
#include <stdlib.h>
#include <iostream>
#include<string.h>
#include "Diccionario.h"
#include "pilas.h"

using namespace std;


/*Texto texto2 = CrearTexto();*/
// Crea un texto vacío
Texto CrearTexto() 
{
	Texto t = new _texto;
	t->textoViejo = NULL;
	t->pilaP = NULL;
	return t;
}
// Inserta una nueva línea vacía al final del texto.
TipoRetorno InsertarLinea(Texto &texto) 
{
	textoViejo aux = texto->textoViejo;
	 
	if (texto->textoViejo == NULL)  //si el texto es nulo se crea nuevo nodo e inserta 
	{
		textoViejo nuevo = new _textoViejo; //Se reserva espacio de memoria para un nodo nuevo
		nuevo->sigL = NULL;		  //Se apuntan los punteros del nodo nuevo a NULL para evitar problemas
		nuevo->priP = NULL;		  //Se apuntan los punteros del nodo nuevo a NULL para evitar problemas
		texto->textoViejo = nuevo;			  //El puntero apunta al nuevo nodo			
		return OK;
	}
	
	else  //si ya existen nodos recorre hasta el final e inserta un nuevo nodo tipo texto
	{
		aux = texto->textoViejo;
		while (aux->sigL!=NULL) //Mientras la siguiente línea no sea NULL 
		{
			aux = aux->sigL;	
		}
		textoViejo nuevo = new _textoViejo;
		nuevo->sigL = NULL;
		nuevo->priP = NULL;
		aux->sigL = nuevo;
	}
	return OK; 
}

// Inserta una nueva línea vacía en la posición indicada.
TipoRetorno InsertarLineaEnPosicion(Texto &texto, Posicion posicionLinea) {
	
	if (texto->textoViejo == NULL && posicionLinea != 1) // Si el texto está vacío y se ingresa cualuier posicion distinto de 1
	{
		return ERROR;
	}
	
	if (texto->textoViejo == NULL && posicionLinea == 1) //Si el texto está vacío y se ingresa la posición número 1
	{
		textoViejo nuevo = new _textoViejo;
		nuevo->sigL = NULL;
		nuevo->priP = NULL;
		texto->textoViejo = nuevo;
		return OK;
	}	
	int contador = 1;
	textoViejo aux = texto->textoViejo;
	while(aux) //Mientras el auxiliar no esté apuntando a NULL
	{
		contador++; //Se aumenta el contador
		aux = aux->sigL; //Se avanza el auxiliar
	}
	
	if (posicionLinea > contador || posicionLinea == 0)
	{
		return ERROR;
	}
	
	else 
	{
		textoViejo nuevo = new _textoViejo;
		nuevo->sigL = NULL;
		nuevo->priP = NULL;	
		if(posicionLinea == 1) //ingresa principio
		{
			nuevo->sigL = texto->textoViejo;
			texto->textoViejo = nuevo;
			return OK;
		}
		if (posicionLinea == contador) //ingresa final
		{
			aux = texto->textoViejo;
			while(aux->sigL)
			{
				aux = aux->sigL;
			}
			nuevo->sigL = aux->sigL;
			aux->sigL = nuevo;
		}
		else  //ingresa al medio
		{
			aux = texto->textoViejo;
			textoViejo aux2 = aux->sigL;
			int i = 2;
			while (aux2 && i< posicionLinea)
			{
				i++;
				aux = aux->sigL;
				aux2 = aux2->sigL;
			}
			nuevo->sigL = aux->sigL;
			aux->sigL = nuevo;
		}
	}
	return OK;
}

// Borra la línea en la posición indicada.
TipoRetorno BorrarLinea(Texto &texto, Posicion posicionLinea) {
	if (texto->textoViejo == NULL) //Si el texto está vacío se retorna ERROR
	{
		return ERROR;
	}
	
	if (posicionLinea < 1) //Si la posicion de la línea ingresada es menor a 1 se retorna ERROR
	{
		return ERROR;
	}
	
	
	else //En caso de que el texto no sea NULL y la posicion sea >= 1 se chequea si posicionLinea < cantLineasIngresadas 
	{
		int contador = 0;
		textoViejo aux = texto->textoViejo;
		while(aux) //Se recorren con un auxiliar todas las líneas ingresadas para obtener el número de estas
		{
			contador++; //Se aumenta el contador 
			aux=aux->sigL; //Se avanza el auxiliar
		}
		if (posicionLinea > contador) //Si la posición a borrar es > al número de líneas ingresadas se retorna ERROR
		{
			return ERROR;
		}
		else //En caso de que esté en el rango numérico de posibilidades y el texto no esté vacío se procede a buscar la línea a borrar
		{
			aux = texto->textoViejo;
			textoViejo aux2 = texto->textoViejo;
			int i = 1;
			Palabras aux3 = NULL;
			while (aux){ //Avanza con el auxiliar
				if (i == posicionLinea){  //si el contador es igual a la posicion de la lines, significa que encontró la posición de la línea a borrar
					aux3 = aux->priP; //Se apunta un auxiliar de tipo palabra a la primer palabra del nodo al cual apunta el auxiliar de tipo texto
					if (aux == texto->textoViejo) //Si el auxiliar apunta al texto, significa que se està borrando la primer línea
					{ 
						BorrarTodoPalabras(aux3); //Se llama a la función que borra todas las palabras de la línea
						texto->textoViejo = texto->textoViejo->sigL; //Se avanza el texto
						delete aux; //Se libera el espacio de memoria ocupado por aux para evitar problemas 
						aux = texto->textoViejo; //Se apunta a texto con el auxiliar
						return OK; //se retorna OK
						break; //Usamos break para salir del while, evitando recorrer innecesariamente
					}
					else { //En caso de que la línea a borrar no sea la primera
						
						BorrarTodoPalabras(aux3); //se llama a la función que borra todas las palabras de una línea
						aux2->sigL = aux->sigL;   //El auxiliar 2, posicionado un lugar antes que el auxiliar 1, apunta al siguiente de donde apunta aux, para no perder el resto del texto
						delete (aux);  //Se libera el espacio de memoria ocupado por aux para evitar problemas
						aux = aux2; //Se apunta con aux a lo que apunta aux2
						return OK; //Se retorna OK
						break; //Usamos break para salir del while, evitando recorrer innecesariamente
					}
				}
				else{ //En caso de que no haya coincidencia se sigue avanzando con los auxiliares
					aux2 = aux; //Aux2 apunta a aux, para estar posicionado detrás de este
					aux = aux->sigL; //Aux avanza, posicionándose un lugar después que aux2
					i++; //Se auemnta el contador
				}
			} 
		} 
	}
	return OK;
}




// Borra todas las líneas del texto.
TipoRetorno BorrarTodo(Texto &texto) {
	textoViejo q = texto->textoViejo;
	Palabras aux = NULL;
	if (texto->textoViejo != NULL)
	{
		while(texto->textoViejo!=NULL) //recorro las lineas y voy borrando
		{
			aux = texto->textoViejo->priP; //apunta primera palabra de cada linea
			BorrarTodoPalabras(aux); //Llama a función que borra todas las palabras en una linea
			texto->textoViejo = texto->textoViejo->sigL; //Se avanza el texto
			delete(q); //Se libera el espacio de memoria ocupado por q para evitar problemas
			q = texto->textoViejo; //Se apunta con q al texto
		}
		return OK; //Se retorna OK
	}
	return OK;
}

// Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto &texto, Cadena palabraABorrar) 
{
	textoViejo aux = texto->textoViejo;
	while (aux) //recorro las lineas
	{
		BorrarOcurrenciasPalabra(aux->priP, palabraABorrar); //Cada vez que pasa por una línea borra las ocurrencias de la palabra ingresada en esa línea
		aux = aux->sigL; //Avanzamos el auxiliar aux
	}
	return OK;
}

// Imprime el texto por pantalla.
TipoRetorno ImprimirTexto(Texto texto) { 
	int i=1;
	textoViejo aux;
	aux = texto->textoViejo;
	Palabras aux2;
	if (texto->textoViejo == NULL) //SI el texto está vacío
		cout<<"Texto vacio"<<endl;
	else{ //En caso contrario 
		while(aux) //recorro las lineas
		{
			cout<<i<<":"; //Hacemos un cout con el entero que muestra la posición de la línea
			if (aux->priP != NULL) //Si tiene palabras
			{
				aux2 = aux->priP; //Se apunta con un auxiliar a la primera palabra de cada línea
					ImprimirPalabras(aux2); //Se llama a la función que imprime en pantalla todas las palabras de una línea
			}
			
			i++; //Se aumenta el contador
			aux = aux->sigL; //Se avanza el auxiliar
			cout<<endl; //Hacemos un enter
		}
		
		return OK;
	}
}

// Comprime las líneas.
TipoRetorno ComprimirTexto(Texto &texto)
{
	if (ComprimirTextoViejo(texto->textoViejo) == OK)
	{
		return OK;
	}
	
	else
	{
		return ERROR;
	}
}

TipoRetorno ComprimirTextoViejo(textoViejo &texto)
{
	
	if (texto == NULL)
	{
		return OK;
	}
	int i = 1; //Entero que nos servirá para controlar qué posición tiene las líneas vacías encontradas
	textoViejo aux = texto;
	while(aux) //Mientras el auxiliar no esté apuntando a  NULL	recorremos el texto buscando líneas vacías para borrarlas
	{
		if (aux->priP == NULL) //Si una línea está vacía
		{
			aux = aux->sigL; //Avanzamos el auxiliar
			BorrarLineaVieja(texto, i); //Llamamos a la función que borra una línea, usando la posición i que comienza en 1
		}
		else //En caso de que no esté vacía
		{
			i++; //Se aumenta el contador 
			aux = aux->sigL; //Se avanza el auxiliar
		}
	}
	aux = texto; //Se apunta el auxiliar a texto 
	if(texto==NULL)
	{
		return OK;
	}
	if (aux->sigL == NULL) //Si la siguiente línea de aux es NULL (no se puede comprimir si hay una sola línea
	{
		return OK;
	}
	
	textoViejo aux2 = aux->sigL; // se apunta con un auxiliar a la siguiente línea del auxiliar que ya tenemos
	
	if (CantidadPalabras(aux->priP) == MAX_CANT_PALABRAS_X_LINEA) //Si la primer línea está llena (No se puede agregarle más palabras)
	{
		aux = aux->sigL;										//Se avanza el auxiliar
		ComprimirTextoViejo(aux);									//Se vuelve a ejecutar comprimir texto, tomando como texto todo a partir del auxiliar, sin tener en cuenta la primer línea completa
	}
	
	if (CantidadPalabras(aux->priP) < MAX_CANT_PALABRAS_X_LINEA) //Si la cantidad de palabras que tiene la línea sobre la que está parado aux es menor a la cantidad de palabras (en este caso necesita palabras para comprimirse)
	{
		int cant = (MAX_CANT_PALABRAS_X_LINEA - CantidadPalabras(aux->priP)); //Este entero contiene la cantidad de palabras que necesita la primer línea para completarse
		Cadena insertar; //Se crea una cadena que nos servirá para guardar en ella la palabra que insertemos en la primer línea
		insertar = new char [MAX_LARGO_PALABRA]; //Se le asigna un espacio de memoria dinámica para evitar problemas
		Palabras aux3 = aux2->priP; //Se apunta con un auxiliar de tipo palabra a la primer palabra de la línea de la cual "pediremos" palabras para ingresar en la primer línea
		
		if (aux2 == NULL) //Si solo hay una línea (no se puede comprimir más)
		{
			return OK;
		}
		
		if (CantidadPalabras (aux2->priP) == cant) //Si la línea de la cual vamos a pedir palabras tiene la cantidad suficiente de palabras, pedimos las palabras y eliminamos la línea
		{
			while (aux2->priP) //Mientras sigan habiendo palabras
			{
				strcpy(insertar, aux3->palabra); //Se copian en la cadena la palabra a insertar en la primer línea
				InsertarPalabra(aux->priP, CantidadPalabras(aux->priP)+1, insertar); //Se llama a la función que inserta palabras en una línea
				aux2->priP = aux3->sigP; //Se avanza para ir borrando palabras
				delete(aux3); //Se libera el espacio de memoria ocupado por aux3 
				aux3 = aux2->priP; //Se apunta con aux3 a la primer palabra de aux2 
			}
			int contador = 1; //Contador que nos servirá para saber que psición de línea borrar
			textoViejo aux4 = texto; //Se apunta con un nuevo auxiliar al texto
			while (aux4 != aux2) //Se recorrerá hasta que el auxiliar nuevo esté en la posición de la línea a eliminar
			{
				contador++; //Se aumenta el contador
				aux4 = aux4->sigL; //Se avanza el auxiliar
			}
			BorrarLineaVieja(texto, contador); //Se llama ala función que borra una línea
			aux = aux->sigL; //Se avanza el auxiliar
			aux2 = aux->sigL; //Se avanza el auxiliar
			ComprimirTextoViejo(aux); //Se vuelve a llamar a la función ComprimirTexto tomando como texto todo a partir de auxiliar
			return OK; //Se retorna OK para terminar la recursividad
		}
		
		if (CantidadPalabras(aux2->priP) > cant) //En caso de que la línea de la que pediremos palabras tenga más palabras que las que necesitemos
		{
			int i = 0; //Se declara un entero que nos servirá para saber cuántas veces tenemos que pasar palabras
			while (i < cant) 
			{
				strcpy(insertar, aux3->palabra); // Se copia en la cadena la palabra a ingresar
				InsertarPalabra(aux->priP, CantidadPalabras(aux->priP)+1, insertar); //Se llama a la función que inserta una palabra
				aux2->priP = aux3->sigP; //Se avanza para ir borrando palabras
				delete(aux3); //Se libera el espacio de memoria ocupado por aux3 
				aux3 = aux2->priP; //Se apunta con el auxiliar3 a la primera palabra de aux2
				i++; //Se aumenta el contador
			}
			
			ComprimirTextoViejo(aux2); //Se vuelve a llamar a la función tomando como texto todo a partir de aux2
			return OK; //Se retorna OK para terminar la recursividad
		}
		
		if (CantidadPalabras(aux2->priP) < cant)
		{
			while (aux2->priP)
			{
				strcpy(insertar, aux3->palabra);
				InsertarPalabra(aux->priP, CantidadPalabras(aux->priP)+1, insertar);
				aux2->priP = aux3->sigP;
				delete(aux3);
				aux3 = aux2->priP;
			}
			int contador = 1;
			textoViejo aux4 = texto;
			while (aux4 != aux2)
			{
				contador++;
				aux4 = aux4->sigL;
			}
			BorrarLineaVieja(texto, contador);
			aux2 = aux->sigL;
			ComprimirTextoViejo(aux);
			return OK;
			
			
			
		}
	}
	return OK;
}

// Inserta una palabra en una línea en la posicion dada.
TipoRetorno InsertarPalabraEnLinea(Texto &texto, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar) {
	if (texto->textoViejo == NULL || posicionLinea < 1)
	{
		return ERROR;
	}
	
	int contador = 0;
	textoViejo aux = texto->textoViejo;
	
	while(aux)
	{
		contador++;
		aux = aux->sigL;
	}
	
	if (posicionLinea > contador)
	{
		return ERROR;
	}
	int i=1;
	aux = texto->textoViejo;
	if (posicionLinea != 1)
	{
		while(aux && i < posicionLinea)
		{
			i++;
			aux = aux->sigL;
		}
	}
	if (InsertarPalabra(aux->priP, posicionPalabra, palabraAIngresar) == OK)
	{
		apilar(texto->pilaP, crearNodoP(palabraAIngresar));
		return OK;
	}
	
	else
	{
		return ERROR;
	}
	
}

// Inserta una palabra en una línea en la posicion dada y dentro de la línea en 
//la posición posicionPalabra. Desplaza todas las palabras que se encuentran a 
//partir de la posición posicionPalabra un lugar hacia adelante. Si al ingresar 
//la palabra se superara la cantidad máxima de palabras por línea (MAX_CANT_PALABRAS_X_LINEA), 
//el desplazamiento afectaría a la línea siguiente y eventualmente a las posteriores, 
//llegando incluso a ser necesario en el caso extremo agregar una nueva línea al 
//final del documento con una sola palabra (si todas las líneas posteriores estuvieran llenas).
TipoRetorno InsertarPalabraYDesplazar(Texto &texto, Posicion posicionLinea,Posicion posicionPalabra, Cadena palabraAIngresar)
{
	if (strlen(palabraAIngresar) > MAX_LARGO_PALABRA) //controla si la cantidad de caracteres de la palabra es valido
	{
		return ERROR;
	}
	
	if (posicionLinea < 1 || texto == NULL)
	{
		return ERROR;
	}
	
	textoViejo aux = texto->textoViejo;
	int contador = 0;
	int posicionL = posicionLinea;
	int i = 1;
	Cadena ingresar;
	while (aux)
	{
		contador++;
		aux = aux->sigL;
	}
	
	if (posicionLinea > contador)
	{
		return ERROR;
	}
	
	aux = texto->textoViejo;
	
	while (aux && i < posicionLinea)
	{
		i++;
		aux = aux->sigL;
	}
	
	if (CantidadPalabras(aux->priP) < MAX_CANT_PALABRAS_X_LINEA)
	{
		InsertarPalabra(aux->priP, posicionPalabra, palabraAIngresar);
		apilar(texto->pilaP, crearNodoP(palabraAIngresar));
		return OK;
	}
	
	else
	{
		Palabras aux2 = aux->priP;
		i = 0;
		
		while (aux2 && i < MAX_CANT_PALABRAS_X_LINEA)
		{
			i++;
			aux2 = aux2->sigP;
		}
		ingresar = new char [MAX_LARGO_PALABRA];	
		if (PalabraEnPosicion (aux->priP, i, ingresar) == OK)
		{
			if (aux->sigL == NULL)
			{
				BorrarPalabra(aux->priP, i);
				InsertarLinea(texto);
				aux = aux->sigL;
				InsertarPalabra(aux->priP, 1, ingresar);
			}
			
			else
			{
			BorrarPalabra(aux->priP, i);
			aux = aux->sigL;
			InsertarPalabraYDesplazar(texto, posicionLinea+1, 1, ingresar);
			}
		}
		
		else
		{
			return ERROR;
		}
		
		aux = texto->textoViejo;
		i = 1;
		
		while (aux && i<posicionLinea)
		{
			i++;
			aux = aux->sigL;
		}
		
		InsertarPalabra(aux->priP, posicionPalabra, palabraAIngresar);
		apilar(texto->pilaP, crearNodoP(palabraAIngresar));
		return OK;
	}
}

// Borra la palabra de una linea que se encuentra en la posición dada.
TipoRetorno BorrarPalabraEnLinea(Texto &texto, Posicion posicionLinea, Posicion posicionPalabra) {
	if (texto == NULL || posicionLinea < 1)
	{
		return ERROR;
	}
	
	int contador = 0;
	textoViejo aux = texto->textoViejo;
	
	while(aux)
	{
		contador++;
		aux = aux->sigL;
	}
	
	if (posicionLinea > contador)
	{
		return ERROR;
	}
	int i=1;
	aux = texto->textoViejo;
	if (posicionLinea != 1)
	{
		while(aux && i < posicionLinea) //me paro en la linea
		{
			i++;
			aux = aux->sigL;
		}
	}
	
	if (BorrarPalabra(aux->priP, posicionPalabra) == OK)
	{
		return OK;
	}
	
	else
	{
		return ERROR;
	}
}

// Borra todas las ocurrencias de una palabra en la línea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto &texto, Posicion posicionLinea, Cadena palabraABorrar) {
	if (texto == NULL || posicionLinea < 1)
	{
		return ERROR;
	}
	
	int contador = 0;
	textoViejo aux = texto->textoViejo;
	
	while(aux)  //cantidad de lineas
	{
		contador++;
		aux = aux->sigL;
	}
	
	if (posicionLinea > contador)
	{
		return ERROR;
	}
	int i=1;
	aux = texto->textoViejo;
	if (posicionLinea != 1)
	{
		while(aux && i < posicionLinea) //me paro en la linea
		{
			i++;
			aux = aux->sigL;
		}
	}
	
	if (BorrarOcurrenciasPalabra(aux->priP,  palabraABorrar) == OK)
	{
		return OK;
	}
	
	else
	{
		return ERROR;
	}
}


// Imprime la línea por pantalla.
TipoRetorno ImprimirLinea(Texto texto, Posicion posicionLinea) {
	textoViejo aux = texto->textoViejo;
	Palabras aux3 = NULL;
	int contador = 0;
	textoViejo nuevo = new _textoViejo;
	nuevo->sigL = NULL;
	nuevo->priP = NULL;
	if (posicionLinea<1)
	{
		return ERROR;
	}
	if (texto == NULL)
	{
		return ERROR;
	}
	
	while(aux)  //cantidad de lineas
	{
		contador++;
		aux = aux->sigL;
	}
	
	if (posicionLinea > contador)
	{
		return ERROR;
	}
	else
	{
		aux = texto->textoViejo;
		Texto aux2 = texto;
		int i = 1;
		while(aux && i<posicionLinea) //me paro en la linea
		{
			i++;
			aux = aux->sigL;
		}
		
		cout<<posicionLinea<<":";
		if (aux->priP != NULL) //recorro las palabras de esa linea
		{
			aux3 = aux->priP;
			ImprimirPalabras(aux3);
			cout<<endl;
			return OK;
		}
		return OK;
	} 
}
//------------------Agregado Obligatorio Parte 2------------------------
// Muestra todas las líneas del texto, pero exhibiendo solamente las palabras
// que no se encuentran en el dicionario.
// Se debe imprimir el número de línea. Cuando el texto no tiene líneas se debe
// mostrar el mensaje "Texto vacio".
TipoRetorno ImprimirTextoIncorrecto(Texto texto, Diccionario D) {
	int linea = 1;
	
	if (texto == NULL || D == NULL)
	{
		ImprimirTexto(texto);
		return OK;
	}
	
	textoViejo aux = texto->textoViejo;
	
	while (aux)
	{
		cout<<linea<<": ";
		ImprimirPalabrasIncorrectas(aux->priP, D);
		cout<<endl;
		aux = aux->sigL;
		linea++;
	}
	return OK;
}

//------------------Agregado Obligatorio Parte 2------------------------
// Imprime las últimas palabras ingresadas. 
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS, a lo sumo, palabras ingresadas
// al texto (no al diccionario), aún cuando estas palabras pudieran haber sido
// luego eliminadas.
// MAX_CANT_ULTIMAS_PALABRAS es una constante del sistema.
// El orden en el que se muestran las palabras debe ser el siguiente: primero la
// última palabra ingresada, luego la penúltima, y así sucesivamente.
// Si nunca se ingresaron palabras se debe mostrar "No se ingresaron palabras".
TipoRetorno ImprimirUltimasPalabras(Texto texto) {
	if (texto->pilaP == NULL)
	{
		cout<<"No se ingresaron palabras"<<endl;
		return OK;
	}
	Pila aux = texto->pilaP;
	int i = 0;
	int contador = 0;
	while(aux)
	{
		contador++;
		aux = aux->sig;
	}
	if (contador >= MAX_CANT_ULTIMAS_PALABRAS)
	{
		aux = texto->pilaP;
	while(i < MAX_CANT_ULTIMAS_PALABRAS)
	{
		cout<<aux->palabraP<<endl;
		aux = aux->sig;
		i++;
	}
	cout<<endl;
	return OK;
	}
	
	else
	{
		aux = texto->pilaP;
		while (i < contador)
		{
			cout<<aux->palabraP<<"-";
			aux = aux->sig;
			i++;
		}
		cout<<endl;
		return OK;
	}
}



TipoRetorno BorrarLineaVieja(textoViejo &texto, Posicion posicionLinea) {
	if (texto == NULL) //Si el texto está vacío se retorna ERROR
	{
		return ERROR;
	}
	
	if (posicionLinea < 1) //Si la posicion de la línea ingresada es menor a 1 se retorna ERROR
	{
		return ERROR;
	}
	
	
	else //En caso de que el texto no sea NULL y la posicion sea >= 1 se chequea si posicionLinea < cantLineasIngresadas 
	{
		int contador = 0;
		textoViejo aux = texto;
		while(aux) //Se recorren con un auxiliar todas las líneas ingresadas para obtener el número de estas
		{
			contador++; //Se aumenta el contador 
			aux=aux->sigL; //Se avanza el auxiliar
		}
		if (posicionLinea > contador) //Si la posición a borrar es > al número de líneas ingresadas se retorna ERROR
		{
			return ERROR;
		}
		else //En caso de que esté en el rango numérico de posibilidades y el texto no esté vacío se procede a buscar la línea a borrar
		{
			aux = texto;
			textoViejo aux2 = texto;
			int i = 1;
			Palabras aux3 = NULL;
			while (aux){ //Avanza con el auxiliar
				if (i == posicionLinea){  //si el contador es igual a la posicion de la lines, significa que encontró la posición de la línea a borrar
					aux3 = aux->priP; //Se apunta un auxiliar de tipo palabra a la primer palabra del nodo al cual apunta el auxiliar de tipo texto
					if (aux == texto) //Si el auxiliar apunta al texto, significa que se està borrando la primer línea
					{ 
						BorrarTodoPalabras(aux3); //Se llama a la función que borra todas las palabras de la línea
						texto = texto->sigL; //Se avanza el texto
						delete aux; //Se libera el espacio de memoria ocupado por aux para evitar problemas 
						aux = texto; //Se apunta a texto con el auxiliar
						return OK; //se retorna OK
						break; //Usamos break para salir del while, evitando recorrer innecesariamente
					}
					else { //En caso de que la línea a borrar no sea la primera
						
						BorrarTodoPalabras(aux3); //se llama a la función que borra todas las palabras de una línea
						aux2->sigL = aux->sigL;   //El auxiliar 2, posicionado un lugar antes que el auxiliar 1, apunta al siguiente de donde apunta aux, para no perder el resto del texto
						delete (aux);  //Se libera el espacio de memoria ocupado por aux para evitar problemas
						aux = aux2; //Se apunta con aux a lo que apunta aux2
						return OK; //Se retorna OK
						break; //Usamos break para salir del while, evitando recorrer innecesariamente
					}
				}
				else{ //En caso de que no haya coincidencia se sigue avanzando con los auxiliares
					aux2 = aux; //Aux2 apunta a aux, para estar posicionado detrás de este
					aux = aux->sigL; //Aux avanza, posicionándose un lugar después que aux2
					i++; //Se auemnta el contador
				}
			} 
		} 
	}
	return OK;
}
