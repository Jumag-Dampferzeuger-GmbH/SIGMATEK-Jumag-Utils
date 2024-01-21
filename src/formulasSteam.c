#include <math.h>

/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl antoineFormT
VAR_INPUT
  INPUT : REAL;
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/
// Calculates the temperature of saturated steam in °C by using the Antoine equation 
// Source: https://en.wikipedia.org/wiki/Antoine_equation
// - pressure in bar 
// - accurate up to 374°C
extern "C" float antoineFormT(float fPressure )
{
    static const float fA = 7.94917F;
    static const float fB = 1657.462F;
    static const float fC = 227.02F;

    float fMmHg = fPressure * 750.061561303F;

    if(fMmHg < 0.0F)
        return 0.0F;
    else
        return fB/(fA - (log(fMmHg) / log(10.0F))) - fC;
}