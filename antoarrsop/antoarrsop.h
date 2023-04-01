// Library for creating arrays with one or more dimensions, created by Anto426.
#ifndef antoarrsop_H
#define antoarrsop_H

/*One-dimensional and two-dimensional array library.

       _type
   --------------
   |tipe => code|
   |int  =>   td|
   |float =>  tf|
   |char  =>  tc|
   |bool  =>  tb|
   |string => ts|
   --------------

         __mode
   --------------------
   |  ma = > automatic|
   |   mm => manual   |
   --------------------
*/

// Variable String
#define STRING_SIZE 1024
typedef char string[STRING_SIZE];

// functions
void PrintArr(void *__arr, int __nlenarr, const char __type[2]);
void FullArr(void *__arr, int __nlenarr, const char __type[2], const char __mode[2]);
void PrintMat(void *__matt, int __nlenarrR, int __nlenarrC, const char __type[2]);
void FullMat(void *__matt, int __nlenarrR, int __nlenarrC, const char __type[2], const char __mode[2]);
#endif
