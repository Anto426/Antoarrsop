// Library include
#include "antoarrsop.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

int *__putint(void *p)
{
    return (int *)p;
}
float *__putfloat(void *p)
{
    return (float *)p;
}
char *__putchars(void *p)
{
    return (char *)p;
}
bool *__putbool(void *p)
{
    return (bool *)p;
}

// Random number generator
int __randomint(int min, int max, int plus)
{
    int intc;
    srand(time(NULL) + plus);
    intc = rand() % (max - min + 1) + min;
    return intc;
}

float __randomfloat(int plus)
{
    float min = 0.0, max = 1000.0, floatc;
    srand(time(NULL) + plus);
    floatc = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
    return floatc;
}
char __randomchar(int plus)
{
    return __randomint(33, 127, plus);
}

bool __randombool(int plus)
{
    int numero_casuale = __randomint(33, 127, plus);
    bool booleano_casuale = (numero_casuale % 2 == 0) ? true : false;
    return booleano_casuale;
}
// Printing function
void __printpt(char __type, void *__po, char temp[], int _addbyte)
{
    switch (__type)
    {
    case 'd':
        _addbyte *= sizeof(int);
        printf(temp, *(__putint(__po + _addbyte)));
        break;
    case 'f':
        _addbyte *= sizeof(float);
        printf(temp, *(__putfloat(__po + _addbyte)));
        break;
    case 'c':
        _addbyte *= sizeof(char);
        printf(temp, *(__putchars(__po + _addbyte)));
        break;
    case 'b':
        _addbyte *= sizeof(bool);
        printf(temp, *(__putbool(__po + _addbyte)));
        break;
    case 's':
        _addbyte *= 1024;
        printf(temp, (__putchars(__po + _addbyte)));

        break;
    default:
        exit(-1);
    }
}
// Input function
void __inputpt(char __type, void *__po, char temp[], int _addbyte, char __mode)
{
    switch (__type)
    {
    case 'd':
        _addbyte *= sizeof(int);
        if (__mode == 'a')

            *(__putint(__po + _addbyte)) = __randomint(1, 1000, _addbyte);
        else
            scanf(temp, (__putint(__po + _addbyte)));
        break;
    case 'f':
        _addbyte *= sizeof(float);
        if (__mode == 'a')
            *(__putfloat(__po + _addbyte)) = __randomfloat(_addbyte);
        else
            scanf(temp, (__putfloat(__po + _addbyte)));
        break;
    case 'c':
        _addbyte *= sizeof(char);
        if (__mode == 'a')
            *(__putchars(__po + _addbyte)) = __randomchar(_addbyte);
        else
            scanf(temp, (__putchars(__po + _addbyte)));
        break;
    case 'b':
        _addbyte *= sizeof(bool);
        if (__mode == 'a')
            *(__putbool(__po + _addbyte)) = __randombool(_addbyte);
        else
            scanf(temp, (__putbool(__po + _addbyte)));
        break;
    case 's':
        _addbyte *= 1024;
        if (__mode == 'a')
            exit(-1);
        else
            scanf(temp, (__putchars(__po + _addbyte)));

        break;
    default:
        exit(-1);
    }
}
// 2D array
void FullArr(void *__arr, int __nlenarr, const char __type[2], const char __mode[2])
{
    if (__type[0] != 't' || __mode[0] != 'm' || __arr == NULL || __nlenarr <= 1)
        exit(-1);
    char temp[] = {'%', __type[1]};
    for (size_t i = 0; i < __nlenarr; i++)
    {
        __inputpt(*(__type + 1), __arr, temp, i, *(__mode + 1));
    }

    return;
}

void PrintArr(void *__arr, int __nlenarr, const char __type[2])
{
    int n = sizeof(__arr);
    if (__type[0] != 't' || __arr == NULL || __nlenarr <= 1)
        exit(-1);
    char temp[] = {'%', __type[1], '\t'};
    for (size_t i = 0; i < __nlenarr; i++)
    {
        __printpt(*(__type + 1), __arr, temp, i);
    }
    printf("\n");
    return;
}

// 3D array
void FullMat(void *__matt, int __nlenarrR, int __nlenarrC, const char __type[2], const char __mode[2])
{
    if (__type[0] != 't' || __mode[0] != 'm' || __matt == NULL)
        exit(-1);
    char temp[] = {'%', __type[1]};

    for (size_t i = 0; i < __nlenarrR * __nlenarrC; i++)
    {
        __inputpt(*(__type + 1), __matt, temp, i, *(__mode + 1));
    }
}

void PrintMat(void *__matt, int __nlenarrR, int __nlenarrC, const char __type[2])
{
    if (__type[0] != 't' || __matt == NULL)
        exit(-1);
    char temp[] = {'%', __type[1], '\t'};

    for (size_t i = 0; i < __nlenarrR * __nlenarrC; i++)
    {
        if (i != 0 && i % __nlenarrC == 0)
        {
            printf("\n");
        }
        __printpt(*(__type + 1), __matt, temp, i);
    }
    printf("\n");
}
