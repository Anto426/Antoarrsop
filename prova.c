#include "antoarrsop.h"
#include <stdio.h>

void fullarray(int n, char (*__matt)[n], int *na)
{
    for (int i = 0; i < n; i++)
    {
        for (int z = 0; z < n; z++)
        {
            printf("Inserisci il %d° elemento nella %d° riga del %d° array: ", z + 1, i + 1, *na);

            // Pulisci il buffer di input
            while (getchar() != '\n');

            scanf("%c", &__matt[i][z]);
        }
    }
    (*na)++;
}

int main()
{
    bool A[3][3] = {{1,0,1}, {1,0,1}, {0,1,0}};
    printf("Ecco l'arrey:\n");
    printmaatt(3, 3, A, "tb");
}
