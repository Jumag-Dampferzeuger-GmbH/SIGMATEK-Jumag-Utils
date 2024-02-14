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
extern "C" float fMin(float f1, float f2)
{
    return (f1 < f2) ? f1 : f2;
}

/* 

Function Global __cdecl aMin
VAR_INPUT
  INPUT : ^REAL;
  SIZE : DINT; 
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/

// calc the min value of an array of float values
extern "C" float aMin(float *f , int size)
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
extern "C" float fMax(float f1, float f2)
{
  return (f1 > f2) ? f1 : f2;
}

/* 

Function Global __cdecl aMax
VAR_INPUT
  INPUT : ^REAL;
  SIZE : DINT; 
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/

// calc the max value of an array of float values
extern "C" float aMax(float *f , int size)
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

Function Global __cdecl isFinite
VAR_INPUT
  INPUT : REAL; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/ 
// true (1) if f is finite.
extern "C" bool isFinite(float f)
{
    return (f <= FLOAT_MAXVAL && f >= -FLOAT_MAXVAL) ? true : false;
}

/* 

Function Global __cdecl isGreaterF
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// true (1) if f1 is greater than f2.
extern "C" bool isGreaterF(float f1, float f2)
{
    return (f1 > f2) ? true : false;
}

/* 

Function Global __cdecl isGreaterEqualF
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// true (1) if f1 is greater equal than f2.
extern "C" bool isGreaterEqualF(float f1, float f2)
{
    return (f1 >= f2) ? true : false;
}

/* 

Function Global __cdecl isEqualF
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// true (1) if f1 is equal to f2.
extern "C" bool isEqualF(float f1, float f2)
{
    return (f1 == f2) ? true : false;
}
/* 

Function Global __cdecl isEqualI
VAR_INPUT
  CMP1 : DINT;
  CMP2 : DINT; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
extern "C" bool isEqualI(int i1, int i2)
{
    return (i1 == i2) ? true : false;
}

/* 

Function Global __cdecl isUnequalI
VAR_INPUT
  CMP1 : DINT;
  CMP2 : DINT; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// returns true
extern "C" bool isUnequalI(int i1, int i2)
{
    return (i1 != i2) ? true : false;
}

/* 

Function Global __cdecl isUnequalF
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// returns true
extern "C" bool isUnequalF(float f1, float f2)
{
    return (f1 != f2) ? true : false;
}