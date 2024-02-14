/* 

Function Global __cdecl mergeBSINT
VAR_INPUT
  MSB : BSINT;
  LSB : BSINT; 
END_VAR
VAR_OUTPUT
  Q : UINT;
END_VAR;

*/
// merge two BSINT Variables to one UINT
extern "C" unsigned int mergeBSINT(unsigned char msByte, unsigned char lsByte)
{
    return (((unsigned int)msByte << 8) | lsByte);
}

/* 