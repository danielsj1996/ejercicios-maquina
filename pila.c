#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
int indefinido = -9999;
typedef struct Nodo
{
    item numero;
    int top;
    struct Nodo *siguiente;
} Nodo;

typedef struct Pila
{
    Nodo *cabecera;
    int altura;
} Pila;

Pila *PilaVacia()
{
    Pila *pila = (Pila *)malloc(sizeof(Pila));
    pila->cabecera = NULL;
    pila->altura = 0;
    return pila;
}

bool esPilaVacia(Pila *pila)
{
    return pila->cabecera == NULL;
}

void push(Pila *pila, int numero)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->numero = numero;
    nuevoNodo->siguiente = pila->cabecera;
    pila->cabecera = nuevoNodo;
    pila->altura++;
    printf("Numero Agregado Correctamente\n");
}

void pop(Pila *pila)
{

    if (esPilaVacia(pila))
    {
        printf("La Pila se encuentra vacia\n");
    }
    Nodo *nodoAEliminar = pila->cabecera;
    pila->cabecera = pila->cabecera->siguiente;
    free(nodoAEliminar);
    pila->altura--;
}

int top(Pila *pila)
{
    if (esPilaVacia(pila))
    {
        return indefinido;
    }
    else
    {
        return pila->cabecera->numero;
    }
}
void mostrarPila(Pila *pila)
{
    if (esPilaVacia(pila))
    {
        printf("La pila se encuentra vacia\n");
    }

    Nodo *actual = pila->cabecera;
    printf("Pila:\n");
    while (actual != NULL)
   {

        printf("%d ->", actual->numero);
        actual = actual->siguiente;
    }
    printf("\n");
}
int altura(Pila *pila)
{
    return pila->altura;
}

void mostrarValorAbsoluto(Pila *pila)
{
    Nodo *actual = pila->cabecera;
    printf("Valor absoluto: ");
    while (actual != NULL)
    {
        printf("%d ->", abs(actual->numero));
        actual = actual->siguiente;
    }
    printf("\n");
}

int main()
{

    Pila *pila = PilaVacia();
    printf("El tope de la pila es: %d\n", top(pila));

    push(pila, 2);
    push(pila, 3);
    push(pila, 5);
    push(pila, 6);
    push(pila, 7);
    push(pila, 1);
    push(pila, 9);

    mostrarPila(pila);

    pop(pila);

    printf("El tope de la pila es: %d\n", top(pila));

    printf("El Altura de la pila es: %d\n", altura(pila));

    push(pila, 55);

    printf("El Altura de la pila es: %d\n", altura(pila));

    mostrarPila(pila);

    push(pila, -5);
    push(pila, -77);
    mostrarValorAbsoluto(pila);
    printf("El Altura de la pila es: %d\n", altura(pila));


}
