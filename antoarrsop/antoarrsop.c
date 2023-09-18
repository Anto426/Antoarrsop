//--------------------------------------------------------------------------------------------------------------------
// Library include
#include "antoarrsop.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>

//--------------------------------------------------------------------------------------------------------------------

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

// Cast
int *__putint1(void *p)
{
    __putint(p);
}
float *__putfloat1(void *p)
{
    __putfloat(p);
}
char *__putchars1(void *p)
{
    __putchars(p);
}
bool *__putbool1(void *p)
{
    __putbool(p);
}

// converion fun puntatori
int (*__putintf(void (*__fun_ptr)(void *)))(void *)
{
    return (int (*)(void *))__fun_ptr;
}
float (*__putfloatf(void (*__fun_ptr)(void *)))(void *)
{
    return (float (*)(void *))__fun_ptr;
}
char((*__putcharsf(void (*__fun_ptr)(void *))))(void *)
{
    return (char (*)(void *))__fun_ptr;
}
bool (*__putboolf(void (*__fun_ptr)(void *)))(void *)
{
    return (bool (*)(void *))__fun_ptr;
}

int (*__putintf1(void (*__fun_ptr)(void *)))(void *)
{
    __putintf(__fun_ptr);
}
float (*__putfloatf1(void (*__fun_ptr)(void *)))(void *)
{
    __putfloatf(__fun_ptr);
}
char((*__putcharsf1(void (*__fun_ptr)(void *))))(void *)
{
    __putcharsf(__fun_ptr);
}
bool (*__putboolf1(void (*__fun_ptr)(void *)))(void *)
{
    __putboolf(__fun_ptr);
}

//--------------------------------------------------------------------------------------------------------------------

int __randomint(int plus)
{
    int intc;
    srand(time(NULL) + plus);
    intc = rand() % (MAX - MIN + 1) + MIN;
    return intc;
}

float __randomfloat(int plus)
{
    float floatc;
    srand(time(NULL) + plus);
    floatc = ((float)rand() / (float)RAND_MAX) * (MAX - MIN) + MIN;
    return floatc;
}
char __randomchar(int plus)
{

    MIN = 33, MAX = 127;
    return __randomint(plus);
}

bool __randombool(int plus)
{
    int numero_casuale = __randomint(plus);
    bool booleano_casuale = (numero_casuale % 2 == 0) ? true : false;
    return booleano_casuale;
}

//--------------------------------------------------------------------------------------------------------------------
// Input

void inputallauto(void *__po, void (*fun)(void *), char temp[], int _addbyte)
{

    fun(__po);
    *((__po + _addbyte)) = __randomint(_addbyte);
}

void inputallmanual(void *__po, void (*fun)(void *), char temp[], int _addbyte)
{
    fun(__po);
    scanf(temp, (__po) + _addbyte);
}

void inputstringauto(void *__po, void (*fun)(void *), char temp[], int _addbyte, char __mode)
{

    _addbyte *= STRING_SIZE;

    int t1 = MAX, t2 = MIN;
    for (size_t i = 0; i < 5; i++)
    {
        fun(__po);
        *(__po + _addbyte + i) = __randomchar(_addbyte + i);
    }
    MAX = t1;
    MIN = t2;
}

void inputstringmanual(void *__po, void (*fun)(void *), char temp[], int _addbyte, char __mode)
{
    _addbyte *= STRING_SIZE;
    fun(__po);
    scanf(temp, (__po + _addbyte));
}

//--------------------------------------------------------------------------------------------------------------------
// output

void outputall(void *__po, void (*fun)(void *), char temp[], int _addbyte)
{
    fun(__po);
    printf(temp, (__po + _addbyte));
}
void outputbool(void *__po, void (*fun)(void *), char temp[], int _addbyte)
{

    printf(temp, *(__putchars(__po) + _addbyte));
}

void outputstring(void *__po, void (*fun)(void *), char temp[], int _addbyte, char __mode)
{

    _addbyte *= STRING_SIZE;

    int t1 = MAX, t2 = MIN;
    for (size_t i = 0; i < 5; i++)
    {
        fun(__po);
        *(fun)(__po + _addbyte + i) = __randomchar(_addbyte + i);
    }
    MAX = t1;
    MIN = t2;
}

//--------------------------------------------------------------------------------------------------------------------

// choise fun
void __typesel(char __type, bool __mode, void (*fpconvert)(void *), void (*fpfconvert)(void (*)(void *)), void *fgen, void *finoon)
{

    switch (__type)
    {
    case 'd':
        fpconvert = __putint1;
        fpfconvert = __putintf1;

        if (__mode)
        {
            fgen = __randomint;
            finoon = inputallauto;
        }
        else
            finoon = inputallmanual;
        break;

    case 'f':
        fpconvert = __putint1;
        fpfconvert = __putintf1;
        if (__mode)
        {
            fgen = __randomint;
            finoon = ;
        }
        else
            finoon = ;
        break;
    case 'c':
        fpconvert = __putint1;
        fpfconvert = __putintf1;
        if (__mode)
        {
            fgen = __randomint;
            finoon = ;
        }
        else
            finoon = ;
        break;
    case 'b':
        fpconvert = __putint1;
        fpfconvert = __putintf1;
        if (__mode)
        {
            fgen = __randomint;
            finoon = ;
        }
        else
            finoon = ;
        break;
    case 's':
        fpconvert = __putint1;
        fpfconvert = __putintf1;
        if (__mode)
        {
            fgen = __randomint;
            finoon = ;
        }
        else
            finoon = ;
        break;

    default:
        exit(-1);
    }
}

// Printing function
void __printpt(char __type, void *__po, char temp[], int _addbyte)
{

    switch (__type)
    {
    case 'd':
        printf(temp, *(__putint(__po) + _addbyte));
        break;
    case 'f':
        printf(temp, *(__putfloat(__po) + _addbyte));
        break;
    case 'c':
        printf(temp, *(__putchars(__po) + _addbyte));
        break;
    case 'b':
        printf("%s\t", *(__putbool(__po) + _addbyte) ? "true" : "false");
        break;
    case 's':
        _addbyte *= STRING_SIZE;
        printf(temp, (__putchars(__po) + _addbyte));
        break;
    default:
        exit(-1);
    }
}

// Input function
void __inputpt(void *__po, void (*fun)(void *), void (*ins)(void *, void (*)(void *), char[], int, char), char temp[], int _addbyte, char __mode)
{
    ins(__po, fun, temp, _addbyte, __mode);
}

int lenarr(va_list args, int __nda, int *last)
{
    int _nlentot = 1, temp;
    for (int i = 0; i < __nda; i++)
    {
        temp = va_arg(args, int);
        _nlentot *= temp;
    }
    if (last != NULL)
        *last = temp;
    return _nlentot;
}

void FullArrs(void *__arr, const char __type[2], const char __mode[2], int __nda, ...)
{
    va_list args;
    va_start(args, __nda);
    int _nlentot = lenarr(args, __nda, NULL);
    char temp[] = {'%', __type[1], '\0'};
    void (*__fun_putfuncovers)(void *), (*__fun_putcovers)(void *);
    __typesel(__type[1], __fun_putfuncovers, __fun_putcovers);

    for (size_t i = 0; i < _nlentot; i++)
    {
        __inputpt(__arr, __fun_putcovers, temp, i, __mode[1]);
    }
    va_end(args);
}

void PrintArrs(void *__arr, const char __type[2], int __nda, ...)
{
    va_list args;
    va_start(args, __nda);
    int last;
    int _nlentot = lenarr(args, __nda, &last);
    char temp[] = {'%', __type[1], '\t', '\0'};

    for (size_t i = 0; i < _nlentot; i++)
    {
        if (i % last == 0)
            printf("\n");
        __printpt(*(__type + 1), __arr, temp, i);
    }
    printf("\n");
    return;
}