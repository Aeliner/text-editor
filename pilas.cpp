#include "pilas.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
pNodoP crearNodoP(Cadena palabraAIngresar)
{
	pNodoP aux = new tipoPila;
	aux->palabraP = new char;
	if (aux)
	{
		strcpy(aux->palabraP, palabraAIngresar);
		aux->sig = NULL;
		//cout<<" ";
		return aux;
	}
	else
	{
		return NULL;
	}
}

bool pilaVacia(Pila pil)
{
	if (pil)
		return true;
	return false;
}

void apilar(Pila &pila, pNodoP aux)
{
	aux->sig = pila;
	pila = aux;
}

pNodoP desapilar(Pila &p)
{
	pNodoP aux, dev = new tipoPila;
	aux = p;
	if (!p)
		return NULL;
	dev->palabraP = p->palabraP;
	p = p->sig;
	delete(aux);
	return dev;
}
