/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl twoPointCtrl
VAR_INPUT
  INPUT : DINT;
  ON_Setpoint : DINT;
  OFF_Setpoint : DINT;
  pOld : ^BOOL;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
extern "C" bool twoPointCtrl(const long int input,
                             const long int on,
                             const long int off,
                             bool *oldState)
{
    bool result = false;

    if (input <= off && *oldState)
    {
        result = true;
        return result;
    }
    
    if (input >= off && *oldState)
    {
        result = false;
        *oldState = result;
        return result; 
    }

    if (input <= on && !*oldState)
    {
        result = true;
        *oldState = result;
    }

    return result;
}


/*DECLARATION IN LASAL CLASS 2


Function Global __cdecl twoPointCtrlF
VAR_INPUT
  INPUT : REAL;
  ON_Setpoint : REAL;
  OFF_Setpoint : REAL;
  pOld : ^BOOL;
END_VAR
VAR_OUTPUT
  Q : BOOL;
END_VAR;

*/
extern "C" bool twoPointCtrlF(const float input,
                             const float on,
                             const float off,
                             bool *oldState)
{
    bool result = false;

    if (input <= off && *oldState)
    {
        result = true;
        return result;
    }
    
    if (input >= off && *oldState)
    {
        result = false;
        *oldState = result;
        return result; 
    }

    if (input <= on && !*oldState)
    {
        result = true;
        *oldState = result;
    }

    return result;
}