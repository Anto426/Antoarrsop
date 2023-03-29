#include "antoarrsop/antoarrsop.h"
#include <stdio.h>
int main()
{
    int A[3];
    FullArr(A, 3, "td", "ma");
    printf("Ecco l'arrey:\n");
    PrintArr(A, 3, "td");
}
