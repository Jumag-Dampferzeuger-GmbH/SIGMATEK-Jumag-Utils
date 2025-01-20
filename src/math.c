#include "cConstants.h"
/* 

Function Global __cdecl fMin
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/


// calc the min value of two float values
extern "C" float fMin(const float f1, const float f2)
{
    return (f1 < f2) ? f1 : f2;
}

/* 

Function Global __cdecl aMinF
VAR_INPUT
  pINPUT : ^REAL;
  SIZE : DINT; 
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/

// calc the min value of an array of float values
extern "C" float aMinF(const float *f , const long int size)
{
    float fMin = f[0];

    for (int i = 1; i < size; i++)
    {
        if (f[i] < fMin)
            fMin = f[i];
    }
    return fMin; 
}

/* 

Function Global __cdecl fMax
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/


// calc the max value of two float values
extern "C" float fMax(const float f1, const float f2)
{
  return (f1 > f2) ? f1 : f2;
}

/* 

Function Global __cdecl aMaxF
VAR_INPUT
  pINPUT : ^REAL;
  SIZE : DINT; 
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/

// calc the max value of an array of float values
extern "C" float aMaxF(const float *f , const int size)
{
    float fMax = f[0];

    for (int i = 1; i < size; i++)
    {
        if (f[i] > fMax)
            fMax = f[i];
    }
    return fMax; 
}

/* 

Function Global __cdecl aMinF
VAR_INPUT
  pINPUT : ^DINT;
  SIZE : DINT; 
END_VAR
VAR_OUTPUT
  Q : DINT;
END_VAR;

*/

// calc the min value of an array of DINTs
extern "C" long int aMin(const long int *input , const long int size)
{
    long int minValue = input[0];

    for (int i = 1; i < size; i++)
    {
        if (input[i] < minValue)
            minValue = input[i];
    }
    return minValue; 
}



/* 

Function Global __cdecl isFinite
VAR_INPUT
  INPUT : REAL; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/ 
// true (1) if f is finite.
extern "C" bool isFinite(const float f)
{
    return (f <= FLOAT_MAXVAL && f >= -FLOAT_MAXVAL) ? true : false;
}

/* 

Function Global __cdecl isGreater
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// true (1) if f1 is greater than f2.
extern "C" bool isGreater(const float f1, const float f2)
{
    return (f1 > f2) ? true : false;
}

/* 

Function Global __cdecl isGreaterEqual
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// true (1) if f1 is greater equal than f2.
extern "C" bool isGreaterEqual(const float f1, const float f2)
{
    return (f1 >= f2) ? true : false;
}








