/*

Function Global __cdecl DelayTon
VAR_INPUT
  IN : BOOL;
  PT : DINT;
  ET : ^UDINT;
  TIMESTAMP : ^UDINT;
  CLOCK : UDINT;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// turn on the output Q after the input IN has been on for the time PT.
// The time is measured in CLOCK units. The elapsed time is stored in ET.
extern "C" bool DelayTon(bool condition, int targetTime, unsigned int *elapsed, unsigned int *timestamp, unsigned int clock)
{
  if (!condition)
  {
    *elapsed = 0; 
    *timestamp = clock;
    return false;
  }
  else
  {
    if (clock > (*timestamp + targetTime))
    {
      *elapsed = targetTime;
      return true;
    }
    else
    {
      *elapsed = clock - *timestamp;
      return false;
    }
  }
}

/*

Function Global __cdecl DelayTof
VAR_INPUT
  IN : BOOL;
  PT : DINT;
  ET : ^UDINT;
  TIMESTAMP : ^UDINT;
  CLOCK : UDINT;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// turn on the output for a certain time if IN Condition is true
extern "C" bool DelayTof(bool condition, int targetTime, unsigned int *elapsed, unsigned int *timestamp, unsigned int clock)
{
  if (condition)
  {
    *elapsed = 0; 
    *timestamp = clock;
    return true;
  }
  else
  {
    if (clock > (*timestamp + targetTime))
    {
      *elapsed = targetTime;
      return false;
    }

    else
    {
      *elapsed = clock - *timestamp;
      return true;
    }
  }
}