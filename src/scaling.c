/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl map
VAR_INPUT
  INPUT : DINT;
  I_LO : DINT;
  I_HI : DINT;
  O_LO : DINT;
  O_HI : DINT;
END_VAR
VAR_OUTPUT
  Q : DINT;
END_VAR;

*/
extern "C" long int map(const long int input, 
                        const long int inLow, 
                        const long int inHigh,
                        const long int outLow,
                        const long int outHigh)
{
    return outLow + (input - inLow) * (outHigh - outLow) / (inHigh - inLow);
}

/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl fMap
VAR_INPUT
  INPUT : REAL;
  I_LO : REAL;
  I_HI : REAL;
  O_LO : REAL;
  O_HI : REAL;
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

*/
extern "C" float fMap(const float input, 
                      const float inLow, 
                      const float inHigh,
                      const float outLow,
                      const float outHigh)
{
    return outLow + (input - inLow) * (outHigh - outLow) / (inHigh - inLow);
}