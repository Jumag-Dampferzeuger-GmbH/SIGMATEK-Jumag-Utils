
/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl functionTrigger
VAR_INPUT 
  currentTime : UDINT;
  timeStamp : ^UDINT;
  targetTime : UDINT;
END_VAR
VAR_OUTPUT
  result : BOOL;
END_VAR;

*/

extern "C" bool functionTrigger(unsigned int uiCurrentTime, unsigned int *uiTimeStamp, unsigned int uiTargetTime)
{
  if((uiCurrentTime - *uiTimeStamp) >= uiTargetTime) 
  {
    *uiTimeStamp = uiCurrentTime;
    return true;
  }
  else
  {
    return false;
  }

}