// Library for creating arrays with one or more dimensions, created by Anto426.
#ifndef antoarrsop_H
#define antoarrsop_H

// Library include

/*One-dimensional and two-dimensional array library.

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

void PrintArr(void *__arr, int __nlenarr, const char __type[2]);
void FullArr(void *__arr, int __nlenarr, const char __type[2], const char __mode[2]);
void PrintMat(void *__matt, int __nlenarrR, int __nlenarrC, const char __type[2]);
void FullMat(void *__matt, int __nlenarrR, int __nlenarrC, const char __type[2], const char __mode[2]);
#endif
