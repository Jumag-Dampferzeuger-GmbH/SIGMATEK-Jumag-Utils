
/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl functionTrigger
VAR_INPUT 
  CURR_TIME : UDINT;
  TIME_STAMP : ^UDINT;
  TAR_TIME : UDINT;
END_VAR
VAR_OUTPUT
  Q : BOOL;
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