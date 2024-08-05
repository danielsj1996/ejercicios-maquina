#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
    char nombre[50];
    struct Nodo *siguiente;
} Nodo;

Nodo *crearNodo(const char *nombre)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void agregarCandidato(Nodo **pila, const char *nombre)
{
    Nodo *nuevoNodo = crearNodo(nombre);
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
    printf("Candidato %s agregado correctamente.\n", nombre);
}

int eliminarCandidato(Nodo **pila)
{
    if (*pila == NULL)
    {
        printf("no hay candidatos para eliminar.\n");
        return 0;
    }
    Nodo *temp = *pila;
    *pila = (*pila)->siguiente;
    printf("Candidato % eliminado.\n", temp->nombre);
    free(temp);
    return 1;
}

int perteneceCandidato(Nodo *pila, const char *nombre)
{
    Nodo *actual = pila;
    while (actual != NULL)
    {
        if (strcmp(actual->nombre, nombre) == 0)
        {
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

void votar(Nodo **pila, const char *nombre)
{
    if (perteneceCandidato(*pila, nombre))
    {
        // Si pertenece a la pila, se cuenta el voto
        printf("Voto registrado para %s.\n", nombre);
    }
    else
    {
        // Si no pertenece a la pila, se muestra el mensaje
        printf("Candidato %s no pertenece a la pila.\n", nombre);
    }
}

void contarVotos(Nodo *pila)
{
    Nodo *actual = pila;
    while (actual != NULL)
    {
        printf("Candidato %s.\n", actual->nombre);
        actual = actual->siguiente;
    }
}

Nodo *obtenerUltimoCandidato(Nodo *pila)
{
    Nodo *actual = pila;
    while (actual != NULL && actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    return actual;
}

Nodo *obtenerPrimerCandidato(Nodo *pila)
{
    return pila;
}

int main()
{

    Nodo *pilaVotos = NULL;

    agregarCandidato(&pilaVotos, "juan");
    agregarCandidato(&pilaVotos, "maria");
    agregarCandidato(&pilaVotos, "carlos");

    votar(&pilaVotos, "juan");
    votar(&pilaVotos, "juan");
    votar(&pilaVotos, "martin");
    votar(&pilaVotos, "carlos");
    votar(&pilaVotos, "maria");
    votar(&pilaVotos, "maria");
    votar(&pilaVotos, "juan");
    votar(&pilaVotos, "carlos");
    votar(&pilaVotos, "carlos");
    votar(&pilaVotos, "juan");

    contarVotos(pilaVotos);

    Nodo *PrimerCandidato = obtenerPrimerCandidato(pilaVotos);
    Nodo *UltimoCandidato = obtenerUltimoCandidato(pilaVotos);

    if (PrimerCandidato != NULL)
    {
        printf("Primer Candidato ingresado: %s\n", PrimerCandidato->nombre);
    }
    if (UltimoCandidato != NULL)
    {
        printf("Ultimo Candidato ingresado: %s\n", UltimoCandidato->nombre);
    }

    eliminarCandidato(pilaVotos);
    contarVotos(pilaVotos);

    return 0;
}