#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATOS 20
#define MAX_NOMBRE 50

// Estructura para almacenar la informacion del candidato

typedef struct
{
    char nombre[MAX_NOMBRE];
    int votos;
} Candidato;

typedef struct
{
    Candidato Candidatos[MAX_CANDIDATOS];
    int frente;
    int fin;
} FilaCandidatos;

void inicializarFila(FilaCandidatos *fila)
{
    fila->frente = 0;
    fila->fin = -1;
}

void agregarCandidato(FilaCandidatos *fila, const char *nombre)
{
    if (fila->fin < MAX_CANDIDATOS - 1)
    {
        fila->fin++;
        strcpy(fila->Candidatos[fila->fin].nombre, nombre);
        fila->Candidatos[fila->fin].votos = 0;
        printf("Candidato %s agregado Correctamente.\n", nombre);
    }
    else
    {
        printf("No se pueden agregar mas candidatos.\n");
    }
}

// funcion para eliminar el primer candidato de la fila
void eliminarCandidato(FilaCandidatos *fila)
{
    if (fila->frente <= fila->fin)
    {
        printf("Candidato %s eliminado.\n", fila->Candidatos[fila->frente].nombre);
        fila->frente++;
    }
    else
    {
        printf("No hay candidatos para eliminar.\n");
    }
}

// funcion para votar por un candidato
void votarCandidato(FilaCandidatos *fila, const char *nombre)
{
    for (int i = fila->frente; i <= fila->fin; i++)
    {
        if (strcmp(fila->Candidatos[i].nombre, nombre) == 0)
        {
            fila->Candidatos[i].votos++;
            printf("Voto registrado para %s.\n", nombre);
            return;
        }
    }
    printf("Candidato %s no encontrado.\n", nombre);
}
// funcion para verificar si un candidato pertenece a la fila
void verificarCandidato(FilaCandidatos *fila, const char *nombre)
{

    for (int i = fila->frente; i <= fila->fin; i++)
    {
        if (strcmp(fila->Candidatos[i].nombre, nombre) == 0)
        {
            printf("El Candidato %s pertenece a la fila.\n", nombre);
            return;
        }
    }
    printf("El Candidato %s no pertenece a la fila.\n", nombre);
}

// funcion para mostrar todos los candidatos y sus votos

void mostrarCandidatos(FilaCandidatos *fila)
{

    if (fila->frente <= fila->fin)
    {
        printf("Lista de Candidatos con su total de votos:\n");
        for (int i = fila->frente; i <= fila->fin; i++)
        {
            printf("%s - %d votos\n", fila->Candidatos[i].nombre, fila->Candidatos[i].votos);
        }
    }
    else
    {
        printf("No hay candidatos en la lista.\n");
    }
}

int main()
{

    FilaCandidatos fila;
    inicializarFila(&fila);
    mostrarCandidatos(&fila);

    agregarCandidato(&fila, "juan");
    agregarCandidato(&fila, "maria");
    agregarCandidato(&fila, "carlos");

    votarCandidato(&fila, "juan");
    votarCandidato(&fila, "carlos");
    votarCandidato(&fila, "pedro");
    votarCandidato(&fila, "maria");
    votarCandidato(&fila, "maria");
    votarCandidato(&fila, "carlos");
    votarCandidato(&fila, "juan");
    votarCandidato(&fila, "juan");
    votarCandidato(&fila, "carlos");
    votarCandidato(&fila, "maria");
    votarCandidato(&fila, "juan");
    votarCandidato(&fila, "maria");
    votarCandidato(&fila, "carlos");

    mostrarCandidatos(&fila);
    verificarCandidato(&fila,"carlos");
    verificarCandidato(&fila,"pedro");
    eliminarCandidato(&fila);
    mostrarCandidatos(&fila);

    return 0;
}