#include <stdio.h>
#include <string.h>

#define MAX_VOTOS 30
#define MAX_NOMBRE 50

// estructura para almacenar la informacion de un candidato
typedef struct
{
    char nombre[MAX_NOMBRE];
    int votos[MAX_VOTOS];
    int top;
} Candidato;

// Estructura para manejar una pila de votos
typedef struct
{
    Candidato candidatos[MAX_VOTOS];
    int totalCandidatos;
} PilaVotos;

// Funcion para inicializar la pila
void inicializarPila(PilaVotos *pila)
{
    pila->totalCandidatos = 0;
}

void agregarCandidato(PilaVotos *pila, const char *nombre)
{
    if (pila->totalCandidatos < MAX_VOTOS)
    {
        strcpy(pila->candidatos[pila->totalCandidatos].nombre, nombre);
        pila->candidatos[pila->totalCandidatos].top = -1;
        pila->totalCandidatos++;
        printf("Candidato %s agregado.\n", nombre);
    }
    else
    {
        printf("No se pueden agregar mas candidatos.\n");
    }
}

// Funcion para votar por un candidato

void votarCandidato(PilaVotos *pila, const char *nombre)
{
    for (int i = 0; i < pila->totalCandidatos; i++)
    {
        if (strcmp(pila->candidatos[i].nombre, nombre) == 0)
        {
            if (pila->candidatos[i].top < MAX_VOTOS - 1)
            {
                pila->candidatos[i].votos[++pila->candidatos[i].top] = 1;
                printf("Voto registrado para %s.\n", nombre);
            }
            else
            {
                printf("El Candidato %s alcanzò el maximo de votos.\n", nombre);
            }
        }
    }
}
void mostrarCandidatos(PilaVotos *pila)
{
    if (pila->totalCandidatos > 0)
    {
        printf("Lista de Candidatos y sus votos:\n");
        for (int i = 0; i < pila->totalCandidatos; i++)
        {
            printf("%s - %d votos\n", pila->candidatos[i].nombre, pila->candidatos[i].top + 1);
        }
    }
    else
    {
        printf("No hay candidatos en la lista.\n");
    }
}
int main()
{

    PilaVotos pila;

    inicializarPila(&pila);

    agregarCandidato(&pila, "juan");
    agregarCandidato(&pila, "maria");
    agregarCandidato(&pila, "carlos");

    votarCandidato(&pila, "juan");
    votarCandidato(&pila, "maria");
    votarCandidato(&pila, "carlos");
    votarCandidato(&pila, "pedro");

    mostrarCandidatos(&pila);

    return 0;
}