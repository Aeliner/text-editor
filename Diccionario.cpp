#include "Diccionario.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

Diccionario CrearDiccionario() {
	Diccionario t = NULL;
	return t; 
}

// Agrega una palabra al diccionario.
// Ingresa una palabra al diccionario si ésta no se encuentra en el mismo.
TipoRetorno IngresarPalabraDiccionario(Diccionario &D,Cadena palabraAIngresar) 
{
	if (PerteneceDiccionario(D, palabraAIngresar) == true)
	{
		return ERROR;
	}
	
	else
	{
	if (D == NULL)
	{
		pNodoD nuevo = new _diccionario;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		nuevo->palabraD=new char[MAX_LARGO_PALABRA];
		strcpy(nuevo->palabraD, palabraAIngresar);
		D = nuevo;
		return OK;
	}
	
	if (stricmp(D->palabraD, palabraAIngresar) > 0)
	{
		IngresarPalabraDiccionario(D->izq, palabraAIngresar);
	}
	
	if (stricmp(D->palabraD, palabraAIngresar) < 0)
	{
		IngresarPalabraDiccionario(D->der, palabraAIngresar);
	}
	
	return OK;
}
}
// Borra una palabra del diccionario si se encuentra en el mismo.
TipoRetorno BorrarPalabraDiccionario(Diccionario &D, Cadena palabraABorrar) {
	if(D==NULL) 
		return ERROR;
	
	if (PerteneceDiccionario (D, palabraABorrar) == false)
	{
		return ERROR;
	}
	else
	{
	if(strcmp(palabraABorrar, D->palabraD)<0)
		BorrarPalabraDiccionario(D->izq, palabraABorrar);
	else
		if(strcmp(palabraABorrar, D->palabraD)>0)
		BorrarPalabraDiccionario(D->der, palabraABorrar);
		else
		{
			Diccionario p = D;
			D= unir(D->izq, D->der);
			delete p;
		}
		return OK;
}
}
Diccionario unir(Diccionario izq, Diccionario der)
{
	if(izq==NULL) 
		return der;
	if(der==NULL) 
		return izq;
	Diccionario centro = unir(izq->der,  der->izq);
	izq->der = centro;
	der->izq= izq;
	return der;
}

// Devuelve true si y sólo si la palabra pertenece al diccionario
bool PerteneceDiccionario(Diccionario D, Cadena palabra) {
	
	int i = 0;
	
	if (D == NULL)
	{
		return i;
	}
	
	if (stricmp(palabra,D->palabraD) < 0)
	{
		i = PerteneceDiccionario(D->izq, palabra);
	}
	
	if (stricmp(palabra, D->palabraD) > 0)
	{
		i = PerteneceDiccionario(D->der, palabra);
	}
	
	if (stricmp(palabra, D->palabraD) == 0)
	{
		return true;
	}
	
	else
	{
		return i;
	}
	
	return i;
}


// Muestra las palabras del diccionario odenadas alfabéticamente, de menor a
// mayor.
// Cuando el diccionario no tiene palabras debe mostrarse el mensaje
// "Diccionario vacio".
TipoRetorno ImprimirDiccionario(Diccionario D) {
	
	if (D == NULL)
	{
		return OK;
	}
	
	ImprimirDiccionario(D->izq);
	cout<<D->palabraD<<endl;
	ImprimirDiccionario(D->der);
	return OK; 
}

int contarPalabrasDiccionario(Diccionario D)
{
	if (D == NULL)
		return 0;
	else
	{
		return 1+contarPalabrasDiccionario(D->der) + contarPalabrasDiccionario(D->izq);
	}
}
