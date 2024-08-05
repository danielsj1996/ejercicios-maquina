#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATOS 20
#define MAX_NOMBRE 50

// estructura para almacenar la informacion de un candidato

typedef struct
{
    char nombre[MAX_NOMBRE];
    int votos;
} Candidato;

// estructura para almacenar la lista de candidatos

typedef struct
{
    Candidato candidatos[MAX_CANDIDATOS];
    int totalCandidatos;
} ListaCandidatos;

// funcion para inicializar la lista de candidatos

void inicializarLista(ListaCandidatos *lista)
{
    lista->totalCandidatos = 0;
}

// funcion para agregar un candidato a la lista
void agregarCandidato(ListaCandidatos *lista, const char *nombre)
{
    if (lista->totalCandidatos < MAX_CANDIDATOS)
    {
        strcpy(lista->candidatos[lista->totalCandidatos].nombre, nombre);
        lista->candidatos[lista->totalCandidatos].votos = 0;
        lista->totalCandidatos++;
        printf("Candidato %s agregado.\n", nombre);
    }
    else
    {
        printf("no se puede agregar mas candidatos");
    }
}

// funcion para eliminar un candidato de la lista
void eliminarCandidato(ListaCandidatos *lista, const char *nombre)
{
    int i, encontrado = 0;
    for (i = 0; i < lista->totalCandidatos; i++)
    {
        if (strcmp(lista->candidatos[i].nombre, nombre) == 0)
        {
            encontrado = 1;
            break;
        }
    }
    if (encontrado)
    {
        for (int j = 0; j < lista->totalCandidatos - 1; j++)
        {
            lista->candidatos[j] = lista->candidatos[j + 1];
        }
        lista->totalCandidatos--;
        printf("Candidato %s eliminado.\n", nombre);
    }
    else
    {
        printf("Candidato %s no encontrado.\n", nombre);
    }
}

// funcion para verificar si un candidato està en la lista
void verificarCandidato(ListaCandidatos *lista, const char *nombre)
{

    for (int i = 0; i < lista->totalCandidatos; i++)
    {
        if (strcmp(lista->candidatos[i].nombre, nombre) == 0)
        {
            printf("El Candidato %s pertenece a la lista\n", nombre); // candidato encontrado
            return;
        }
    }
    printf("El Candidato %s no pertenece a la lista\n", nombre); // candidato no encontrado
}

// funcion para votar por un candidato
void votarCandidato(ListaCandidatos *lista, const char *nombre)
{
    for (int i = 0; i < lista->totalCandidatos; i++)
    {
        if (strcmp(lista->candidatos[i].nombre, nombre) == 0)
        {
            lista->candidatos[i].votos++;
            printf("Voto Registrado para %s.\n", nombre);
            return;
        }
    }
    printf("Candidato %s no encontrado.\n", nombre);
}

// funcion para contar el numero total de candidatos
int contarCandidatos(ListaCandidatos *lista)
{
    return lista->totalCandidatos;
}

// funcion para mostrar todos los candidaatos y sus votos

void mostrarCandidatos(ListaCandidatos *lista)
{
    printf("Lista de Candidatos y sus Votos:\n");
    for (int i = 0; i < lista->totalCandidatos; i++)
    {
        printf("%d. %s - %d votos\n", i + 1, lista->candidatos[i].nombre, lista->candidatos[i].votos);
    }
}

int main()
{

    ListaCandidatos lista;
    inicializarLista(&lista);

    agregarCandidato(&lista, "juan");
    agregarCandidato(&lista, "maria");
    agregarCandidato(&lista, "carlos");

    votarCandidato(&lista, "juan");
    votarCandidato(&lista, "maria");
    votarCandidato(&lista, "carlos");
    votarCandidato(&lista, "juan");
    votarCandidato(&lista, "carlos");
    votarCandidato(&lista, "carlos");
    votarCandidato(&lista, "maria");

    mostrarCandidatos(&lista);

    eliminarCandidato(&lista, "maria");
    eliminarCandidato(&lista, "ruben");
    mostrarCandidatos(&lista);
    verificarCandidato(&lista, "carlos");
    verificarCandidato(&lista, "ruben");
    printf("Total de candidatos: %d\n", contarCandidatos(&lista));

    return 0;
}