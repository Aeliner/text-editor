#include "Palabras.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Diccionario.h"
using namespace std;
// Crea un conjunto de palabras vacio
Palabras CrearPalabras() {
	Palabras p = NULL;
	return p;
}

// Inserta una palabra en la posicion dada.
TipoRetorno InsertarPalabra(Palabras &palabras, Posicion posicionPalabra,Cadena palabraAIngresar) {
	if (posicionPalabra > MAX_CANT_PALABRAS_X_LINEA || posicionPalabra < 1)
	{
		return ERROR;
	}
	
	if (strlen(palabraAIngresar) > MAX_LARGO_PALABRA) //controla si la cantidad de caracteres de la palabra es valido
	{
		return ERROR;
	}
	
	Palabras nuevo = new _palabra;
	nuevo->sigP = NULL;
	nuevo->palabra=new char;
	
	Palabras aux = palabras;
	Palabras aux2 = palabras;
	
	int cantP = CantidadPalabras(aux);
	
	if (posicionPalabra > cantP+1 || cantP == MAX_CANT_PALABRAS_X_LINEA) //si la posicion de la palabra es mayor a la cantidad de palabras es linea
	{
		return ERROR;
	}
		
		else 
		{
			if (palabras == NULL)
			{
		if (posicionPalabra != 1)
		
		{
			return ERROR;
		}
		
	}
			
	if (posicionPalabra == 1) //agrega en el primer lugar y mueve las palabras ya existentes al siguiente lugar
	{
		nuevo->sigP = palabras;
		palabras = nuevo;
		strcpy(nuevo->palabra, palabraAIngresar);
		return OK;
	}
	
	if (posicionPalabra == cantP+1) //agrega en el ultimo lugar
	{
		aux = palabras;
		while (aux->sigP) //se para en el ultimo lugar
		{
			aux = aux->sigP;
		}
		
		nuevo->sigP = aux->sigP;
		aux->sigP = nuevo;
		strcpy(nuevo->palabra, palabraAIngresar);
		return OK;
	}
	
	else //si se ingresa en el medio
	{
		int i = 2;
		aux = palabras;
		aux2 = aux->sigP; //se para un nodo despues
		while (aux2->sigP && i < posicionPalabra) //mientras el puntero a la siguiente palabra del auxiliar de más adelante no apunte a NULL
		{
			i++;
			aux2 = aux2->sigP;
			aux = aux->sigP;
		}
		
		nuevo->sigP = aux->sigP;
		aux->sigP = nuevo;
		
		strcpy(nuevo->palabra, palabraAIngresar);
		
		return OK;
	}	
			return ERROR;
		}
	
		return OK;
}

// Borra la palabra que se encuentra en la posición dada.
TipoRetorno BorrarPalabra(Palabras &palabras, Posicion posicionPalabra) {
	if (posicionPalabra < 1 || posicionPalabra > MAX_CANT_PALABRAS_X_LINEA)
	{
		return ERROR;
	}
	
	if (palabras == NULL)
	{
		return ERROR;
	}
	
	Palabras aux= palabras;
	Palabras aux2 = palabras;
	int cantP = CantidadPalabras(aux);
	
	
	if (posicionPalabra > cantP)
	{
		return ERROR;
	}
	
	else
	{
		if (posicionPalabra == 1) //si la palabra a borrar es la primera
		{
			palabras = palabras->sigP;
			delete(aux);
			aux = palabras;
			return OK;
		}
		
		if (posicionPalabra == cantP) //si la palabra a borrar es la ultima
		{
			aux = palabras;
			aux2 = aux->sigP;
			while(aux2->sigP)
			{
				aux = aux->sigP;
				aux2= aux2->sigP;
			}
			aux->sigP = NULL;
			delete(aux2);
			aux2 = aux;
			return OK;
		}
		
		else //si la palabra a borrar se encuentra en medio
		{
			int i = 1;
			aux = palabras;
			aux2 = palabras;
			while (aux2->sigP && i < posicionPalabra)
			{
				i++;
				aux2 = aux2->sigP;
			}
			
			while (aux->sigP != aux2)
			{
				aux = aux->sigP;
			}
			
			aux->sigP = aux2->sigP;
			delete(aux2);
			aux2 = aux;
			return OK;
		}
	}
	
	
	return OK;
}

// Borra todas las ocurrencias de una palabra.
TipoRetorno BorrarOcurrenciasPalabra(Palabras &palabras,Cadena palabraABorrar) {
		Palabras aux = palabras;
		Palabras aux2 = palabras;
		while(aux2)
		{
			if (stricmp (aux2->palabra, palabraABorrar) == 0) //compara si las cadenas son iguales
			{
				if (stricmp (palabras->palabra, palabraABorrar) == 0)
				{
					palabras = palabras->sigP;
					delete (aux);
					delete (aux2);
					aux = palabras;
					aux2 = palabras;
				}
				
				else
				{
					aux->sigP = aux2->sigP;
					delete (aux2);
					aux2 = aux;
				}
			}
			
			else //si no son iguales continua recorriendo
			{
			aux = aux2;
			aux2 = aux2->sigP;
			}
		}
	
		return OK;
	}

// Borrar todo.
void BorrarTodoPalabras(Palabras &palabras) 
{
	Palabras aux = palabras;
	while (palabras != NULL) //recorre y va borrando las palabras
	{
		palabras = palabras->sigP;
		delete(aux);
		aux = palabras;
	}
}

// Imprime la línea en pantalla.
void ImprimirPalabras(Palabras palabras) 
{
	Palabras aux2 = palabras;
	while (aux2)   //recorre y va imprimiendo las palabras
	{
		cout<<" "<<aux2->palabra;
		aux2 = aux2->sigP;
	}
}

// Devuelve la cantidad de palabras.
unsigned int CantidadPalabras(Palabras palabras) 
{	
	int contador = 0;
	Palabras aux = palabras;
	while (aux)
	{
		contador++;
		aux = aux->sigP;
	}
	
	return contador;
}

// Devuelve en palabra una copia de la palabra que se encuentra
// en la posición dada.
TipoRetorno PalabraEnPosicion(Palabras palabras, Posicion posicionPalabra,Cadena &palabra) 
	{
	if (posicionPalabra < 1 || posicionPalabra > MAX_CANT_PALABRAS_X_LINEA || posicionPalabra > CantidadPalabras(palabras))
	{
		return ERROR;
	}
	
	Palabras aux = palabras;
	int contador = 1;
	
	while(aux && contador < posicionPalabra)
	{
		contador++;
		aux = aux->sigP;
	}
	
	strcpy(palabra, aux->palabra);
	return OK;
}


//------------------Para Parte 2------------------------
// Muestra solamente las palabras que no se encuentran en el dicionario.
TipoRetorno ImprimirPalabrasIncorrectas(Palabras palabras, Diccionario D) {
	if (palabras == NULL)
	{
		return OK;
	}
	
	Palabras aux = palabras;
	Cadena palabraAux;
	palabraAux = new char[MAX_LARGO_PALABRA];
	while(aux)
	{
		strcpy(palabraAux, aux->palabra);
		if (PerteneceDiccionario(D, palabraAux) == false)
		{
			cout<<aux->palabra<<" ";
		}
		aux = aux->sigP;
	}
	return OK;
}
