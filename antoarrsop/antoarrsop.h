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

// min max
extern int MAX;
extern int MIN;
// functions
void FullArrs(void *__arr, const char __type[2], const char __mode[2], int __nda, ...);
void PrintArrs(void *__arr, const char __type[2], int __nda, ...);
#endif
