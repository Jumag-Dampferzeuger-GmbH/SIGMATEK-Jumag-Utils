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
/*

Function Global __cdecl DelayTonOff
VAR_INPUT
  IN : BOOL;
  PT_ON : DINT;
  PT_OFF : DINT;
  ET_ON : ^UDINT;
  ET_OFF : ^UDINT;
  TIMESTAMP : ^UDINT;
  CLOCK : UDINT;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
// turn on the output for a certain time if IN Condition is true
extern "C" bool DelayTonOff(const bool condition, const int targetOn, const int targetOff, unsigned int *elapsedOn,unsigned int *elapsedOff, unsigned int *timestamp, const unsigned int clock)
{

  if( (!condition && *elapsedOn >= targetOn && *elapsedOff >= targetOff) ||
      (!condition && *elapsedOn == 0 && *elapsedOff == 0) ||
      (!condition && *elapsedOn > 0 && *elapsedOn < targetOn) )
  {
    // reset timers
    *elapsedOn = 0; 
    *elapsedOff = 0; 
    *timestamp = clock;
    return false; 
  }


  //on timer
  if(condition && *elapsedOn < targetOn)
  {
    if(clock > (*timestamp + targetOn))
    {
      *elapsedOn = targetOn;
      return true; 
    }
    else 
    {
      *elapsedOn = clock - *timestamp;
      return false; 
    }
  }

  if(condition && *elapsedOn >= targetOn)
  {
    *timestamp = clock;
    return true; 
  }

  if (!condition && *elapsedOn >= targetOn)
  {
    // off timer
    if(clock > (*timestamp + targetOff))
    {
      *elapsedOff = targetOff;
      return false; 
    }
    else 
    {
      *elapsedOff = clock - *timestamp;
      return true; 
    }
  }

  if(!condition && *elapsedOff >= targetOff)
  {
    *timestamp = clock;
    return false; 
  }


}