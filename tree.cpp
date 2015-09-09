#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define NULL 0
/*#define clrscr() system("clear")
#define getch() system("read a")*/

//using namespace std;

struct treenodo
{
    struct treenodo * izqptr;
    char dato[40];
    struct treenodo * derptr;
};

void crear(treenodo * nodo)
{
    char resp[1];
    clrscr();
    cout<<"Entre el dato: ";
    gets(nodo->dato);
    cout<<"Hay nodos a la Izquierda entre S/N ";
    gets(resp);
    if(strcmp(resp,"S")==0)
    {
	nodo->izqptr=NULL;
	nodo->izqptr= new (treenodo);
	crear(nodo->izqptr);
    }
    else
	nodo->izqptr=NULL;
    cout<<"Hay nodos a la Derecha entre S/N ";
    gets(resp);
    if (strcmp(resp,"S")==0)
    {
	nodo->derptr=new (treenodo);
	crear(nodo->derptr);
    }
    else
	nodo->derptr=NULL;
}

void preorden (treenodo * nodo)
{
    if(nodo != NULL)
    {
	printf("%s ",nodo->dato);
	preorden(nodo->izqptr);
	preorden(nodo->derptr);
    }
}


int main()
{
    treenodo * nodo;
    nodo= new treenodo;
    crear(nodo);
    preorden(nodo);
    getch();
}
