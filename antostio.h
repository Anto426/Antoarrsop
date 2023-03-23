// libary input/ounput create to Anto426

#ifndef antostio_H
#define antostio_H
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

void betprintf(int);

void real(char *__arr, int __narr)
{
    if (__arr == NULL)
        return (-1);

    char *__new_arr = calloc(__arr, __narr * sizeof(char));
    if (__new_arr == NULL)
    {
        free(__new_arr);
        return (-1);
    }
    for (size_t i = 0; i < __narr; i++)
    {
        *(__new_arr + i) = *(__arr + i);
    }

    __arr = __new_arr;
}

bool chechint(char __arr[])
{
    size_t __C = 0;
    if (__arr == NULL)
        return -1;

    size_t __narr = sizeof(__arr) / sizeof(char);

    for (size_t i = 0; i < __narr; i++)
    {
        if (__arr[i] >= 0 && __arr[i] <= 10)
        {
            __C++;
        }
    }
    if (__C == __narr)
        return 1;
    else
        return 0;
}

bool chechfloat(char __arr[])
{
    size_t __C = 0;
    if (__arr == NULL)
        return -1;

    size_t __narr = sizeof(__arr) / sizeof(char);

    for (size_t i = 0; i < __narr; i++)
    {
        if (__arr[i] >= 0 && __arr[i] <= 10 || __arr[i] == '.' || __arr[i] == ',' && i == 0 || i == __narr)
        {
            __C++;
        }
    }
    if (__C == __narr)
        return 1;
    else
        return 0;
}

void betscanf(char *__pelement)
{
    bool __cint = 0, __cchar = 0, __cfloat = 0, __cstring = 0;
    char *__buffer = calloc(__buffer, 1024 * sizeof(char));
    size_t __nread;

    __nread = read(STDIN_FILENO, __buffer, sizeof(__buffer));

    char *__content = calloc(__content, __nread * sizeof(char));

    for (size_t i = 0; i < __nread; i++)
    {
        __content[i] = __buffer[i];
    }
    __cint = chechint(__content);
    __cfloat = chechfloat(__content);
    if (!((__cint) || (__cfloat)))
    {
        if (__nread - 1 == 1)
            __cchar = 1;
        else
            __cstring = 1;
    }
    if (__cstring)
    {
        __pelement = __content;
    }
    if (__cint)
    {
        __pelement = __content;
    }
    if (__cint)
    {
        __pelement = (int *)__pelement;
        *__pelement = 0;
        for (size_t i = 0; i < __nread; i++)
        {
            *__pelement += ((int)__content[i] * pow(10, i));
        }
    }
    if (__cfloat)
    {
        __pelement = (float *)__pelement;

        // non so come continuare pls 
    }

    return 0;
}

void betprintf(int){

};

#endif
