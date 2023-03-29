// libary for array 1 or plus dimension dimension create to Anto426

#ifndef antoarrsop_H
#define antoarrsop_H

// lybrary include
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

// arreymonodimensionali e bidimensionali
/*
        _type
    --------------
    |tipe => code|
    |int  =>   td|
    |float =>  tf|
    |char  =>  tc|
    |bool  =>  tb|
    --------------

        _dim
    -------------
    |n => arrnd |
    |1 => arr1d |
    |2 => arr2d |
    -------------

          __mode
    --------------------
    |  ma = > automatic|
    |   mm => manual   |
    --------------------
*/

// covertitore di putatori
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

// funzioni random
int __randomint(int plus)
{
    int min = 0, max = 1000, intc;
    srand(time(NULL)+ plus);
    intc = rand() % (max - min + 1) + min;
    return intc;
}

float __randomfloat(int plus)
{
    float min = 0.0, max = 1000.0, floatc;
    srand(time(NULL)+ plus);
    floatc = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
    return floatc;
}
char __randomchar(int plus)
{
    srand(time(NULL)+ plus);
    int num_casuale = rand() % 26;
    return 'a' + num_casuale;
}

bool __randombool(int plus)
{
    srand(time(NULL)+ plus);
    int numero_casuale = rand();
    bool booleano_casuale = (numero_casuale % 2 == 0) ? true : false;
    return booleano_casuale;
}
// funzione stampa
void __printpt(char __type, void *__po, char temp[], int _addbyte)
{
    void *__pt = __po;
    switch (__type)
    {
    case 'd':
        _addbyte *= sizeof(int);
        printf(temp, *(__putint(__pt + _addbyte)));
        break;
    case 'f':
        _addbyte *= sizeof(float);
        printf(temp, *(__putfloat(__pt + _addbyte)));
        break;
    case 'c':
        _addbyte *= sizeof(char);
        printf(temp, *(__putchars(__pt + _addbyte)));
        break;
    case 'b':
        _addbyte *= sizeof(bool);
        printf(temp, *(__putbool(__pt + _addbyte)));
        break;
    default:
        exit(-1);
    }
}
// funzione di input
void __inputpt(char __type, void *__po, char temp[], int _addbyte, char __mode)
{
    void *__pt = __po;
    switch (__type)
    {
    case 'd':
        _addbyte *= sizeof(int);
        if (__mode == 'a')
            *(__putint(__pt + _addbyte)) = __randomint(_addbyte);
        else
            scanf(temp, (__putint(__pt + _addbyte)));
        break;
    case 'f':
        _addbyte *= sizeof(float);
        if (__mode == 'a')
            *(__putfloat(__pt + _addbyte)) = __randomfloat(_addbyte);
        else
            scanf(temp, (__putfloat(__pt + _addbyte)));
        break;
    case 'c':
        _addbyte *= sizeof(char);
        if (__mode == 'a')
            *(__putchars(__pt + _addbyte)) = __randomchar(_addbyte);
        else
            scanf(temp, (__putchars(__pt + _addbyte)));
        break;
    case 'b':
        _addbyte *= sizeof(bool);
        if (__mode == 'a')
            *(__putbool(__pt + _addbyte)) = __randombool(_addbyte);
        else
            scanf(temp, (__putbool(__pt + _addbyte)));
        break;
    default:
        exit(-1);
    }
}

// vettori 2d
void printarr(void *__arr, int __nlenarr, const char __type[2])
{
    if (__type[0] != 't' || __arr == NULL || __nlenarr <= 1)
        exit(-1);
    char temp[] = {'%', __type[1], '\t'};
    for (size_t i = 0; i < __nlenarr; i++)
    {
        __printpt(*(__type + 1), __arr, temp, i);
    }
    return;
}

void fullarr(void *__arr, int __nlenarr, const char __type[2], const char __mode[2])
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

// vettori 3d
void printmaatt(void *__matt, int __nlenarrR, int __nlenarrC, const char __type[2])
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
}

void fullmaatt(void *__matt, int __nlenarrR, int __nlenarrC, const char __type[2], const char __mode[2])
{
    if (__type[0] != 't' || __mode[0] != 'm' || __matt == NULL)
        exit(-1);
    char temp[] = {'%', __type[1]};

    for (size_t i = 0; i < __nlenarrR * __nlenarrC; i++)
    {
        __inputpt(*(__type + 1), __matt, temp, i, *(__mode + 1));
    }
}
#endif
