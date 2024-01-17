/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl map
VAR_INPUT
  input : DINT;
  inLow : DINT;
  inHigh : DINT;
  outLow : DINT;
  outHigh : DINT;
END_VAR
VAR_OUTPUT
  result : DINT;
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
  input : REAL;
  inLow : REAL;
  inHigh : REAL;
  outLow : REAL;
  outHigh : REAL;
END_VAR
VAR_OUTPUT
  result : REAL;
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