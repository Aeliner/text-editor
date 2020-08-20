#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Texto.h"
#include "Diccionario.h"

using namespace std;

void imprimirResultado(int);

int main(int argc, char *argv[])
{
	Texto texto = CrearTexto();
//	texto->textoViejo = NULL;
//	texto->pilaP = NULL;
	//Texto texto2 = CrearTexto();
	Diccionario D = CrearDiccionario();
	int numOper = 0;
	bool salir = false;
	TipoRetorno retorno = NO_IMPLEMENTADA;
	Posicion posicionLinea = 0;
	Posicion posicionPalabra = 0;
	char opcion = 'n';
	Cadena palabraAux = NULL;
	
	do {
		
		
		cout<<"Estructuras de Datos y Algoritmos - Obligatorio 1\n";
		cout<<"PROCESADOR DE TEXTOS\n\n";
		  
		cout<<"Lista de operaciones disponibles:\n";
		cout<<"1)  InsertarLinea\n";
		cout<<"2)  InsertarLineaEnPosicion\n";
		cout<<"3)  BorrarLinea\n";
		cout<<"4)  BorrarTodo\n";
		cout<<"5)  BorrarOcurrenciasPalabraEnTexto\n";
		cout<<"6)  ImprimirTexto\n";
		cout<<"7)  ComprimirTexto\n";
		cout<<"8)  InsertarPalabra\n";
		cout<<"9)  InsertarPalabrayDesplazar\n";
		cout<<"10) BorrarPalabra\n";
		cout<<"11) BorrarOcurrenciasPalabraEnLinea\n";
		cout<<"12) ImprimirLinea\n";
		cout<<"13) IngresarPalabraDiccionario\n";
		cout<<"14) BorrarPalabraDiccionario\n";
		cout<<"15) ImprimirDiccionario\n";
		cout<<"16) ImprimirTextoIncorrecto\n";
		cout<<"17) ImprimirUltimasPalabras\n";
		cout<<"0) Salir\n\n";
		
		cout<<"Ingrese el numero de la operacion a realizar: ";
		fflush(stdin);
		cin>> numOper;
		
		switch (numOper){
		case 1:
			retorno = InsertarLinea(texto);
			imprimirResultado(retorno);
			break;
		case 2:
			cout<<"Ingrese la posicion de la nueva linea (debe ser >= 1 y <= cant lineas + 1): ";
			fflush(stdin);
			cin>>posicionLinea;
			fflush(stdin);
			retorno = InsertarLineaEnPosicion(texto,posicionLinea);
			imprimirResultado(retorno);
			break;
		case 3:
			cout<<"Ingrese la posicion de la linea a borrar (debe ser >= 1 y <= cant lineas): ";
			fflush(stdin);
			cin>>posicionLinea;
			retorno = BorrarLinea(texto,posicionLinea);
			imprimirResultado(retorno);
			break;                
		case 4:
			cout<<"Esta seguro de que desea borrar todas las lineas del texto (s/n)?: ";                  
			fflush(stdin);
			cin>>opcion;
			if (opcion == 's' || opcion == 'S'){
				retorno = BorrarTodo(texto);
				imprimirResultado(retorno);
			}
			break;
		case 5:                
			cout<<"Ingrese la palabra que desea borrar: ";
			palabraAux = new char [MAX_LARGO_PALABRA];
			fflush(stdin);
			cin>>palabraAux;
			retorno = BorrarOcurrenciasPalabraEnTexto(texto, palabraAux);
			imprimirResultado(retorno);
			delete palabraAux;
			break;
		case 6:
			retorno =  ImprimirTexto(texto);
			imprimirResultado(retorno);
			break;
		case 7:
			retorno = ComprimirTexto(texto);
			imprimirResultado(retorno);
			break;
		case 8:
			cout<<"Ingrese la palabra que desea agregar: ";
			palabraAux = new char;
			fflush(stdin);
			cin>>palabraAux;
			cout<<"Ingrese la posicion de la linea donde la va a agregar (debe ser >= 1 y <= cant lineas): ";
			fflush(stdin);
			cin>>posicionLinea;
			cout<<"Ingrese la posicion que debe tener la palabra dentro de las palabras de la linea (debe ser >= 1 y <= cant palabaras en la linea + 1): ";
			fflush(stdin);
			cin>>posicionPalabra;
			retorno = InsertarPalabraEnLinea(texto,posicionLinea,posicionPalabra,palabraAux);
//			ImprimirTexto(texto);
//			ImprimirUltimasPalabras(texto);
			imprimirResultado(retorno);
			delete palabraAux;
			break;
		case 9: //InsertarPalabraYDesplazar
			cout<<"Ingrese la palabra que desea agregar: ";
			palabraAux = new char [MAX_LARGO_PALABRA];
			fflush(stdin);
			cin>>palabraAux;
			cout<<"Ingrese la posicion de la linea donde la va a agregar (debe ser >= 1 y <= cant lineas): ";
			fflush(stdin);
			cin>>posicionLinea;
			cout<<"Ingrese la posicion que debe tener la palabra dentro de las palabras de la linea (debe ser >= 1 y <= cant palabaras en la linea + 1): ";
			fflush(stdin);
			cin>>posicionPalabra;
			retorno = InsertarPalabraYDesplazar(texto,posicionLinea,posicionPalabra,palabraAux);
			imprimirResultado(retorno);
			delete palabraAux;
			break;
		case 10:
			cout<<"Ingrese la posicion de la linea donde se encuentra la palabra a borrar (debe ser >= 1 y <= cant lineas): ";
			fflush(stdin);
			cin>>posicionLinea;
			cout<<"Ingrese la posicion de la palabra a borrar (debe ser >= 1 y <= cant palabaras en la linea): ";
			fflush(stdin);
			cin>>posicionPalabra;
			retorno = BorrarPalabraEnLinea(texto,posicionLinea,posicionPalabra);
			imprimirResultado(retorno);
			break;
		case 11:
			cout<<"Ingrese la palabra que desea borrar: ";
			palabraAux = new char [MAX_LARGO_PALABRA];
			fflush(stdin);
			cin>>palabraAux;
			cout<<"Ingrese la posicion de la linea donde se debe borrar la palabra (debe ser >= 1 y <= cant lineas): ";
			fflush(stdin);
			cin>>posicionLinea;
			retorno =  BorrarOcurrenciasPalabraEnLinea(texto,posicionLinea,palabraAux);
			imprimirResultado(retorno);
			delete palabraAux;
			break;
		case 12:
			cout<<"Ingrese la posicion de la linea que desea imprimir (debe ser >= 1 y <= cant lineas): ";
			fflush(stdin);
			cin>>posicionLinea;
			retorno =  ImprimirLinea(texto, posicionLinea);
			imprimirResultado(retorno);
			break;
		case 13:
			cout<<"Ingrese la palabra que desea agregar al diccionario: ";
			palabraAux = new char [MAX_LARGO_PALABRA];
			fflush(stdin);
			cin>>palabraAux;
			retorno = IngresarPalabraDiccionario(D,palabraAux);
			imprimirResultado(retorno);
			delete palabraAux;
			break;                
		case 14:
			cout<<"Ingrese la palabra que desea borrar del diccionario: ";
			palabraAux = new char [MAX_LARGO_PALABRA];
			fflush(stdin);
			cin>>palabraAux;
			retorno = BorrarPalabraDiccionario(D, palabraAux);
			imprimirResultado(retorno);
			delete palabraAux;
			break;
		case 15:
			if (contarPalabrasDiccionario(D) == 0)
			{
				cout<<"Diccionario vacio"<<endl;
				break;
			}
			
			else
			{
			retorno =  ImprimirDiccionario(D);
			imprimirResultado(retorno);
			}
			break;
		case 16:
			retorno =  ImprimirTextoIncorrecto(texto, D);
			imprimirResultado(retorno);
			break;
		case 17:                  
			retorno =  ImprimirUltimasPalabras(texto);
			imprimirResultado(retorno);
			break;
		case 0:
			cout<<"Esta seguro de que desea salir (s/n)?: ";                  
			fflush(stdin);
			cin>>opcion;
			if (opcion == 's' || opcion == 'S'){
				cout<<"Saliendo...\n"; 
				salir = true;
			}
			break;
		default:
			cout<<"No ingreso una opcion valida, vuelva a intentarlo...\n";
		}
		cout<<"\n";
		system("pause");
		
		system("cls");
		
	} while (!salir);
	
	return EXIT_SUCCESS;
}


void imprimirResultado(int retorno){
	
	switch(retorno){
	case 0:
		cout<<"Resultado: OK"<<endl;
		break; 
	case 1:
		cout<<"Resultado: ERROR"<<endl;
		break;
	case 2:
		cout<<"Resultado: NO_IMPLEMENTADA"<<endl;
		break;
	} 
}
