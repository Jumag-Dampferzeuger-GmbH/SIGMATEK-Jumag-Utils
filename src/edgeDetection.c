/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl rTrig_DINT
VAR_INPUT
  INPUT : DINT;
  PREV : ^DINT;
  TRIGGER : DINT;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
extern "C" bool rTrig_DINT(int inputSignal, int *prevSignal, int triggerVal)
{
    if (inputSignal >= triggerVal && *prevSignal < triggerVal)
    {
        *prevSignal = inputSignal;
        return 1;
    }
    else if((inputSignal >= triggerVal && *prevSignal >= triggerVal) || (inputSignal < triggerVal && *prevSignal >= triggerVal)) 
    {
        *prevSignal = inputSignal;
        return 0;
    }
    else 
        return 0;
}

/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl fTrig_DINT
VAR_INPUT
  INPUT : DINT;
  PREV : ^DINT;
  TRIGGER : DINT;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/

extern "C" bool fTrig_DINT(int inputSignal, int *prevSignal, int triggerVal)
{
  if(inputSignal <= triggerVal && *prevSignal > triggerVal) 
  {
    *prevSignal = inputSignal;
    return 1;
  }
  else if((inputSignal <= triggerVal && *prevSignal <= triggerVal) || (inputSignal > triggerVal && *prevSignal <= triggerVal)) 
  {
    *prevSignal = inputSignal;
    return 0; 
  }
  else 
    return 0;

}
