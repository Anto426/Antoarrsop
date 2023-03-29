#include "antoarrsop.h"
#include <stdio.h>
int main()
{
    int A[3];
    fullarr(A, 3, "td", "ma");
    printf("Ecco l'arrey:\n");
    printarr(A, 3, "td");
}
