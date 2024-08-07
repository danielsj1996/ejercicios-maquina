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
    Nodo *frente; // puntero al primero elemento de la fila
    Nodo *final;
    int total; // puntero al ultimo elemento de la fila
} Fila;

// FilaVacia: Crea una fila vacia

Fila FilaVacia()
{

    Fila fila;
    fila.frente = NULL;
    fila.final = NULL;
    fila.total = 0;
    return fila;
}

// esFilaVacia:Determina si una fila está vacía
bool esFilaVacia(Fila *fila)
{
    return fila->frente == NULL;
}

// frente: Retorna el elemento que se encuentra en el frente de la fila
int Frente(Fila *fila)
{
    if (esFilaVacia(fila))
    {
        printf("la fila se encuentra vacia");
        return indefinido;
    }
    else
    {
        return fila->frente->numero;
    }
}

// EnFila: agrega un elemento al final de la fila
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
    fila->total++;
}

// Defila: Borra el elemento que está al frente de la fila
void Defila(Fila *fila)
{
    if (esFilaVacia(fila))
    {
        printf("La fila se encuentra vacia\n");
        return;
    }
    Nodo *nodoAEliminar = fila->frente;
    fila->frente = fila->frente->siguiente;
    if (fila->frente == NULL)
    {
        fila->final = NULL; // si la fila queda vacia, actualizar el puntero final
    }
    free(nodoAEliminar);
    fila->total--;
}

int total(Fila *fila)
{
    return fila->total;
}

// Funcion recursiva para contar la cantidad de veces que aparece un determinado item en la fila
int ContarX(Fila *fila, int numero)
{

    if (esFilaVacia(fila))
    {
        return 0;
    }
    else
    {
        if (Frente(fila) == numero)
        {
            Defila(fila);
            return 1 + ContarX(fila, numero);
        }
        else
        {
            Defila(fila);
            return ContarX(fila, numero);
        }
    }
}

int main()
{
    Fila fila = FilaVacia();

    printf("Esta la fila vacia?: %s\n", esFilaVacia(&fila) ? "Si" : "No");
    // probar Enfila

    Enfila(&fila, 5);
    Enfila(&fila, 10);
    Enfila(&fila, 20);
    Enfila(&fila, 60);
    Enfila(&fila, 5);

    // probar EsfilaVacia

    printf("Esta la fila vacia?: %s\n", esFilaVacia(&fila) ? "Si" : "No");

    // probar Frente
    printf("Elemento al frente de la fila: %d\n", Frente(&fila));

    // probar defila
    Defila(&fila);
    printf("Elemento al frente de la fila despues de Defila: %d\n", Frente(&fila));

    // probar Total

    printf("Total de elementos en la fila: %d\n", total(&fila));

    // probar ContarX
    int x = 5;
    printf("El numero %d aparece %d veces en la fila.\n", x, ContarX(&fila, x));

    return 0;
}
