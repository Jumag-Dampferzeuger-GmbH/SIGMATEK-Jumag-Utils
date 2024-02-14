/* 

Function Global __cdecl DelayTon
VAR_INPUT
  IN : BOOL;
  PT : DINT; 
  ET : ^UDINT; 
  CLOCK : UDINT;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// turn on the output Q after the input IN has been on for the time PT. 
// The time is measured in CLOCK units. The elapsed time is stored in ET.
extern "C" bool DelayTon (bool xCondition, int iTargetTime, unsigned int *uiElapsedTime, unsigned int uiClock)
{
    if (!xCondition) 
    {
        *uiElapsedTime = uiClock; 
        return false;
    }
    else
    {
        if (uiClock > (*uiElapsedTime + iTargetTime)) 
            return true;
        else
            return false;
    }
}

/* 

Function Global __cdecl DelayTof
VAR_INPUT
  IN : BOOL;
  PT : DINT; 
  ET : ^UDINT; 
  CLOCK : UDINT;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// turn on the output for a certain time if IN Condition is true
extern "C" bool DelayTof (bool xCondition, int iTargetTime, unsigned int *uiElapsedTime, unsigned int uiClock)
{
    if (xCondition) 
    {
        *uiElapsedTime = uiClock; 
        return true; 
    }
    else
    {    
        if (uiClock > (*uiElapsedTime + iTargetTime)) 
            return false;
        else
            return true; 
    }
}