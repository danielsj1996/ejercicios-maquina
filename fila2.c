#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int indefinido = -9999;

// definicion del nodo de la lista enlazada

typedef int item;
typedef struct Nodo
{
    item numero;
    struct Nodo *siguiente;
} Nodo;

typedef struct Fila
{
    Nodo *frente; // puntero al primer elemento de la fila
    Nodo *final;  // puntero al ultimo elemento de la fila
    int total;
} Fila;

Fila *FilaVacia()
{

    Fila *fila = (Nodo *)malloc(sizeof(Nodo));
    fila->frente = NULL;
    fila->final = NULL;
    fila->total = 0;
    return fila;
}

// Test para determinar si una fila está vacía
bool esFilaVacia(Fila *fila)
{
    return fila->frente == NULL;
}

// Funcion que retorna el elemento que se encuentra en el frente de la fila
int Frente(Fila *fila)
{
    if (esFilaVacia(fila))
    {
        printf("La fila se encuentra vacia");
        return indefinido;
    }
    else
    {
        return fila->frente->numero;
    }
}

// Funcion para agregar nuevos datos a la fila
void Enfila(Fila *fila, int numero)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->numero = numero;
    nuevoNodo->siguiente = NULL;
    if (esFilaVacia(fila))
    {
        fila->frente = nuevoNodo;
        fila->final = nuevoNodo;
    }
    else
    {
        fila->final->siguiente = nuevoNodo;
        fila->final = nuevoNodo;
    }
    printf("Numero Agregado Correctamente\n");
    fila->total++;
}

void Defila(Fila *fila)
{

    if (esFilaVacia(fila))
    {
        printf("La fila se encuentra vacia");
        return;
    }
    Nodo *nodoAEliminar = fila->frente;
    fila->frente = fila->frente->siguiente;
    if (fila->frente == NULL)
    {
        fila->final = NULL; // si la fila queda vacia, actualiza el puntero final de la fila
    }
    free(nodoAEliminar);
    printf("Numero Eliminado Correctamente\n");
    fila->total--;
}

int total(Fila *fila)
{
    return fila->total;
}
int ContarX(Fila *fila, int x)
{
    if (esFilaVacia(fila))
    {
        return 0;
    }
    else
    {
        int numero = Frente(fila);
        Defila(fila);
        if (numero == x)
        {
            return 1 + ContarX(fila, x);
        }
        else
        {
            return ContarX(fila, x);
        }
    }
}

int main()
{

    Fila *fila = FilaVacia();

    // Probar si la fila está vacía
    printf("Esta la fila vacia?: %s\n", esFilaVacia(fila) ? "Si" : "No");

    // probar Enfilar Datos

    Enfila(fila, 5);
    Enfila(fila, 20);
    Enfila(fila, 25);
    Enfila(fila, 30);
    Enfila(fila, 56);
    Enfila(fila, 51);
    Enfila(fila, 5);
    Enfila(fila, 88);
    Enfila(fila, 90);

        // Probar si la fila está vacía
    printf("Esta vacía la fila?: %s\n", esFilaVacia(fila) ? "Si" : "No");
    // Obtener el elemento del frente de la fila
    printf("El primer elemento de la fila es: %d\n", Frente(fila));

    //Probando defilar un elemento de la fila y luego mostrando el frente de la misma
    Defila(fila);
    printf("El primer elemento de la fila es: %d\n", Frente(fila));

    //probar funcion para obtener el total de elementos de la fila
     printf("El total de elementos en la fila es: %d\n",total(fila));

    int x=122;
    printf("El numero %d aparece %d veces en la fila.\n",x,ContarX(&fila,x));
    return 0;
}
