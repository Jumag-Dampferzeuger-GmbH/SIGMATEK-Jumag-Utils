#include <math.h>
#include "physConstants.h"
/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl antoineFormT
VAR_INPUT
  INPUT : REAL;
  OPTION : BOOL;
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/
// Calculates the temperature of saturated steam in °C by using the Antoine equation
// Source: https://en.wikipedia.org/wiki/Antoine_equation
// bool IsOverpressure = true means that the pressure is given in barÜ
// - pressure in bar
// - accurate up to 374°C
extern "C" float antoineFormT(float fPressure, bool IsOverpressure)
{
  float fMmHg = fPressure * 750.061561303F;
  const float ATM = 1.01325F;
  
  if (IsOverpressure)
    fMmHg = (fPressure + ATM) * 750.061561303F;

  

  if (fMmHg < 0.0F)
    return 0.0F;
  else
    return ANTOINE_CONST_B / (ANTOINE_CONST_A - (log(fMmHg) / log(10.0F))) - ANTOINE_CONST_C;
}

/*DECLARATION IN LASAL CLASS 2

Function Global __cdecl antoineFormP
VAR_INPUT
  INPUT : REAL;
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/

// Calculates the pressure of saturated steam in bar by using the Antoine equation
extern "C" float antoineFormP(float fTemperature)
{
  if (fTemperature < 0.0F)
    return 0.0F;
  else
  {
    float fMmHg = pow(10.0F, (ANTOINE_CONST_A - ANTOINE_CONST_B / (fTemperature + ANTOINE_CONST_C)));
    return fMmHg / 750.061561303F;
  }
}
