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
    |int  =>   ti|
    |float =>  tf|
    |char  =>  tc|
    |bool  =>  tb|
    --------------

        _dim
    ---------------
    |n => arrnd  |
    |1 => arr1d  |
    |2 => arr2d  |
    |            |
    |            |
    ---------------
*/
void __changpt(char __type, void *__po, char *temp)
{
    auto *__pt = __po;
    switch (__type)
    {
    case 'i':
        __pt = (int *)__po;
        *temp = 'd';
        break;
    case 'f':
        __pt = (float *)__po;
        *temp = 'f';
        break;
    case 'c':
        __pt = (char *)__po;
        *temp = 'c';
        break;
    case 'b':
        __pt = (bool *)__po;
        *temp = 'b';
        break;
    default:
        exit(-1);
    }
    __po = __pt;
}
void printarr(void *__arr, char __type[2], int __nlenarr, int __dim)
{
    char temp[] = {'%', '?', ' '};
    if (__type[0] != 't' || __arr == NULL || __dim > 1)
        exit(-1);
    auto *tp = __arr;
    __changpt(*(__type + 1), tp, (temp + 1));
    for (size_t i = 0; i < __nlenarr; i++)
    {
        printf(temp, *(tp + i));
    }
    return;
}

void printmaatt(int __nlenarrR, int __nlenarrC, void *__matt, char __type[2])
{
    char temp[] = {'%', '?', ' '};
    if (__type[0] != 't' || __matt == NULL)
        exit(-1);
    auto *__matt1 = __matt1;
    __changpt(*(__type + 1), __matt, (temp + 1));
    for (size_t i = 0; i < __nlenarrR * __nlenarrC; i++)
    {
        printf(temp, *(__matt1 + i));
    }
}

#endif
