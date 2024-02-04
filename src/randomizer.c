#include "cConstants.h"
/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl linCongGen
VAR_INPUT 
  INPUT : DINT;
  FACTOR : DINT; 
  INCREMENT : DINT; 
  MODULO : DINT; 
END_VAR
VAR_OUTPUT
  Q : DINT;
END_VAR;

*/
// randomzier by using linear congruential generator (LCG)
// - PARAM_A and PARAM_B are optional parameters, if value "0" passed, default values will be used
// - do not use this for cryptographic purposes
// - modulo operator is limiting the range of the result
extern "C" int linCongGen(int iStart, int iFactor, int iIncrement, int iModulo) 
{
    // Default values
    iFactor = (iFactor == 0 || iFactor >= INT_MAXVAL || iFactor <= -INT_MAXVAL) ? 1103515245L : iFactor;
    iIncrement = (iIncrement == 0 || iIncrement >= INT_MAXVAL || iIncrement <= -INT_MAXVAL) ? 5234L : iIncrement;
    iModulo = (iModulo == 0 || iModulo >= INT_MAXVAL || iModulo <= -INT_MAXVAL) ? 2147483647L : iModulo;

    unsigned long long int iResult = iStart; 
    iResult = iFactor * iResult + iIncrement;
    iResult = iResult % iModulo;
    return iResult;

}