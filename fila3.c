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
    Nodo *frente; // Nodo que apunta al primer elemento de la fila
    Nodo *final;  // Nodo que apunta al ultimo elemento de la fila
    int total;    // Contador para contabilizar el total de elementos en la lista
} Fila;

Fila *filaVacia()
{

    Fila *fila = (Nodo *)malloc(sizeof(Nodo));
    fila->frente = NULL;
    fila->final = NULL;
    fila->total = 0;
    return fila;
}

// test para verificar si la fila está vacía

bool esFilaVacia(Fila *fila)
{
    return fila->frente == NULL;
}

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
    printf("Numero agregado Correctamente.\n");
    fila->total++;
}

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
        fila->final == NULL; // Si la fila queda vacia, actualiza el puntero final de la fila
    }
    free(nodoAEliminar);
    fila->total--;
}
void mostrarFila(Fila *fila)
{
    if (esFilaVacia(fila))
    {
        printf("La fila se encuentra vacia.\n");
    }
    Nodo *actual = fila->frente;
    printf("Fila: \n");
    while (actual != NULL)
    {
        printf("%d ->", actual->numero);
        actual = actual->siguiente;
    }
    printf("\n");
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
        int frente = Frente(fila);
        Defila(fila);
        if (frente == x)
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

    Fila *fila = filaVacia();

    // Pruebas cuando la fila se encuentra vacía
    printf("Esta vacia la fila?: %s\n", esFilaVacia(fila) ? "Si" : "No");

    printf("El total de elementos en la fila es: %d\n", total(fila));

    printf("El primer elemento de la fila es: %d\n", Frente(fila));

    Enfila(fila, 15);
    Enfila(fila, 35);
    Enfila(fila, 11);
    Enfila(fila, 23);
    Enfila(fila, 44);
    Enfila(fila, 52);
    Enfila(fila, 12);
    Enfila(fila, 16);
    Enfila(fila, 122);
    Enfila(fila, 122);

    mostrarFila(fila);
    // Probar si la fila está vacía
    printf("Esta vacia la fila?: %s\n", esFilaVacia(fila) ? "Si" : "No");
    printf("El total de elementos en la fila es: %d\n", total(fila));
    // Obtener el elemento del frente de la fila
    printf("El primer elemento de la fila es: %d\n", Frente(fila));

    // Probando defilar un elemento de la fila y luego mostrando el frente de la misma
    Defila(fila);
    printf("El primer elemento de la fila luego de aplicar una vez el defila es: %d\n", Frente(fila));

    // probar funcion para obtener el total de elementos de la fila
    printf("El total de elementos en la fila es: %d\n", total(fila));

    int x = 122;
    printf("El numero %d aparece %d veces en la fila.\n", x, ContarX(fila, x));
}