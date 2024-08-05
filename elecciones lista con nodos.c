#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
    char nombre[50];
    int votos;
    struct Nodo *siguiente;
} Nodo;

Nodo *crearNodo(const char *nombre)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->votos = 0;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void agregarCandidato(Nodo **cabeza, const char *nombre)
{
    Nodo *nuevoNodo = crearNodo(nombre);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
    printf("Candidato %s agregado correctamente.\n", nombre);
}

void votar(Nodo *cabeza, const char *nombre)
{
    Nodo *actual = cabeza;
    while (actual != NULL)
    {
        if (strcmp(actual->nombre, nombre) == 0)
        {
            actual->votos++;
            printf("Voto registrado para %s.\n", nombre);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Candidato %s no encontrado.\n", nombre);
}

int eliminarCandidato(Nodo **cabeza, const char *nombre)
{
    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;
    while (actual != NULL)
    {
        if (strcmp(actual->nombre, nombre) == 0)
        {
            if (anterior == NULL)
            {
                *cabeza = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("Candidato %s eliminado. \n", nombre);
            return 1;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    printf("Candidato %s no encontrado.\n", nombre);
    return 0;
}
int perteneceCandidato(Nodo *cabeza, const char *nombre)
{
    Nodo *actual = cabeza;
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
Nodo *obtenerPrimerCandidato(Nodo *cabeza)
{
    return cabeza;
}
Nodo *obtenerUltimoCandidato(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    while (actual != NULL && actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }

    return actual;
}
void mostrarCandidatos(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    printf("Lista de candidatos y sus votos:\n");
    while (actual != NULL)
    {
        printf("%s - %d votos\n", actual->nombre, actual->votos);
        actual = actual->siguiente;
    }
}

int main()
{

    Nodo *listaCandidatos = NULL;

    agregarCandidato(&listaCandidatos, "juan");
    agregarCandidato(&listaCandidatos, "maria");
    agregarCandidato(&listaCandidatos, "carlos");

    votar(listaCandidatos, "juan");
    votar(listaCandidatos, "carlos");
    votar(listaCandidatos, "maria");
    votar(listaCandidatos, "juan");
    votar(listaCandidatos, "carlos");
    votar(listaCandidatos, "carlos");
    votar(listaCandidatos, "pedro");

    mostrarCandidatos(listaCandidatos);

    Nodo *primerCandidato = obtenerPrimerCandidato(listaCandidatos);
    Nodo *ultimoCandidato = obtenerUltimoCandidato(listaCandidatos);
    if (primerCandidato != NULL)
    {
        printf("Primer Candidato ingresado: %s\n", primerCandidato->nombre);
    }
    if (ultimoCandidato != NULL)
    {
        printf("Ultimo Candidato ingresado: %s\n", ultimoCandidato->nombre);
    }

    eliminarCandidato(&listaCandidatos, "juan");
    mostrarCandidatos(listaCandidatos);

    if (perteneceCandidato(listaCandidatos, "carlos"))
    {
        printf("Carlos pertenece a la lista de candidatos.\n");
    }
    else
    {

        printf("Carlos no pertenece a la lista de candidatos.\n");
    }

    return 0;
}
