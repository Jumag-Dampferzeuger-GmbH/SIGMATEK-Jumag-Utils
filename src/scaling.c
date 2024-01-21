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
extern "C" long int map(long int input, 
                        long int inLow, 
                        long int inHigh,
                        long int outLow,
                        long int outHigh)
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
extern "C" float fMap(float input, 
                      float inLow, 
                      float inHigh,
                      float outLow,
                      float outHigh)
{
    return outLow + (input - inLow) * (outHigh - outLow) / (inHigh - inLow);
}