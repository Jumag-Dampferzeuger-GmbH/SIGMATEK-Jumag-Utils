/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl ms_to_s
VAR_INPUT
  millis : UDINT;
END_VAR
VAR_OUTPUT
  seconds : UDINT;
END_VAR;

*/
extern "C" long unsigned int ms_to_s (const long unsigned int millis)
{
    return millis / 1000; 
}

/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl ms_to_min
VAR_INPUT
  millis : UDINT;
END_VAR
VAR_OUTPUT
  minutes : UDINT;
END_VAR;


*/
extern "C" long unsigned int ms_to_min (const long unsigned int millis)
{
    return millis / 60000; 
}