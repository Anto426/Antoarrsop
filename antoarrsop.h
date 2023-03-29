// libary for array 1 or plus dimension dimension create to Anto426

#ifndef antoarrsop_H
#define antoarrsop_H

// lybrary include
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

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
*/

// covertitore di putatori
char *__putchars(void *p)
{
    return (char *)p;
}
int *__putint(void *p)
{
    return (int *)p;
}
float *__putfloat(void *p)
{
    return (float *)p;
}
bool *__putbool(void *p)
{
    return (bool *)p;
}

// funzioni random
int __randomint(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}
char __randomchar()
{
    __srand(time(NULL));
    int num_casuale = rand() % 26;
    return 'a' + num_casuale;
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

// vettori 2d
void printarr(void *__arr, char __type[2], int __nlenarr, int __dim)
{
    if (__type[0] != 't' || __arr == NULL || __dim > 1)
        exit(-1);
    char temp[] = {'%', __type[1], ' '};
    for (size_t i = 0; i < __nlenarr; i++)
    {
        __printpt(*(__type + 1), __arr, temp, i);
    }
    return;
}

void fullarr(void *__arr, char __type[2], int __nlenarr, int __dim)
{
    if (__type[0] != 't' || __arr == NULL || __dim > 1)
        exit(-1);
    char temp[] = {'%', __type[1], ' '};
    for (size_t i = 0; i < __nlenarr; i++)
    {
        __printpt(*(__type + 1), __arr, temp, i);
    }
    return;
}

// vettori 3d
void printmaatt(int __nlenarrR, int __nlenarrC, void *__matt, char __type[2])
{
    if (__type[0] != 't' || __matt == NULL)
        exit(-1);
    char temp[] = {'%', __type[1], ' '};
    for (size_t i = 0; i < __nlenarrR * __nlenarrC; i++)
    {
        if (i != 0 && i % __nlenarrC == 0)
        {
            printf("\n");
        }
        __printpt(*(__type + 1), __matt, temp, i);
    }
}

void fullmaatt(int __nlenarrR, int __nlenarrC, void *__matt, char __type[2], char __mode)
{
    if (__type[0] != 't' || __matt == NULL)
        exit(-1);
    char temp[] = {'%', __type[1], ' '};

    for (size_t i = 0; i < __nlenarrR * __nlenarrC; i++)
    {
        if (i != 0 && i % __nlenarrC == 0)
        {
            printf("\n");
        }
        __printpt(*(__type + 1), __matt, temp, i);
    }
}
#endif
