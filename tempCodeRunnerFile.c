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