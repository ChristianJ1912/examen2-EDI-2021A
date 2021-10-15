#include<stdio.h>

#define m 30

int Captura(int clav[m], char nom[m][m], int estsue[m][m]);
int Alto(int n, int clav[m], char nom[m][m], int estsue[m][m]);
void Mayorsueldo(int n, int clav[m], char nom[m][m], int estsue[m][m]);
void Imprime(int n, int clav[m], char nom[m][m], int estsue[m][m]);

int main()
{
int clave[m], estaturasueldo[m][m], numero, masalto;
char nombre[m][m];

  numero = Captura(clave, nombre, estaturasueldo);
  masalto = Alto(numero, clave, nombre, estaturasueldo);
  Mayorsueldo(numero, clave, nombre, estaturasueldo);
  Imprime(numero, clave, nombre, estaturasueldo);
}

int Captura(int clav[m], char nom[m][m], int estsue[m][m])
{
  int i, n;
    printf("¿Cuantos empleados son?: " );
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Clave: ");
        scanf("%d", &clav[i]);
        printf("Nombre: ");
        scanf("%c", &nom[i]);
        printf("Estatura: ");
        scanf("%d", &estsue[0][i]);
        printf("Sueldo: ");
        scanf("%d", &estsue[1][i]);
    }
    return(n);
}

int Alto(int n, int clav[m], char nom[m][m], int estsue[m][m])
{
    int i, alt=0;
    for(i=0; i<n; i++)
    {
        if(estsue[0][i]>alt)
            alt=estsue[0][i];
    }
    return(alt);
}

void Mayorsueldo(int n, int clav[m], char nom[m][m], int estsue[m][m])
{
    int i,j, auxsue, auxest, auxclav;
    char auxnom[m];
    for (i=1;i<n;i++)
    {
       for (j=0; j<n-i; j++)
       {
          if (estsue[1][j] > estsue[i][j+1])
          {
            auxsue=estsue[1][j];
            auxest=estsue[0][j];
            auxnom=nom[j];
            auxclav=clav[j];
            estsue[1][j]=estsue[1][j+1];
            estsue[0][j]=estsue[0][j+1];
            nom[m][j]=nom[m][j+1];
            clav[j]=clav[j+1];
            estsue[1][j+1]=auxsue;
            estsue[0][j+1]=auxest;
            nom[m][j+1]=auxnom[m];
            clav[j+1]=auxclav;
          }
       }
    }
}

void Imprime(int n, int clav[m], char nom[m][m], int estsue[m][m])
{
    int i;
    printf("clave\t nombre\t estatura\t sueldo\t");
    for(i=0; i<n; i++)
        printf("%d\t %c\t %d\t %d\t\n", clav[i], nom[i], estsue[0][i], estsue[1][i]);
}
