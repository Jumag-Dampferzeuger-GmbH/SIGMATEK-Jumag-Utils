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
extern "C" unsigned int mergeBSINT(const unsigned char msByte, const unsigned char lsByte)
{
    return (((unsigned int)msByte << 8) | lsByte);
}

/* 

Function Global __cdecl splitDINT
VAR_INPUT
  IN : DINT;
  MSB : ^BSINT;
  MID_MSB : ^BSINT;
  MID_LSB : ^BSINT;
  LSB : ^BSINT; 
END_VAR
VAR_OUTPUT
END_VAR;

*/
// split one DINT (32bit) to  BSINTs (8bit)
extern "C" void splitDINT(const long int iInput, unsigned char *byte1, unsigned char *byte2, unsigned char *byte3, unsigned char *byte4)
{
    *byte1 = (unsigned char)((iInput >> 24) & 0xFF);
    *byte2 = (unsigned char)((iInput >> 16) & 0xFF);
    *byte3 = (unsigned char)((iInput >> 8) & 0xFF);
    *byte4 = (unsigned char)(iInput & 0xFF);
}

/* 

Function Global __cdecl splitUDINT
VAR_INPUT
  IN : UDINT;
  MSB : ^BSINT;
  MID_MSB : ^BSINT;
  MID_LSB : ^BSINT;
  LSB : ^BSINT; 
END_VAR
VAR_OUTPUT
END_VAR;

*/
// split one UDINT (32bit) to  BSINTs (8bit)
extern "C" void splitUDINT(const unsigned long int iInput, unsigned char *byte1, unsigned char *byte2, unsigned char *byte3, unsigned char *byte4)
{
    *byte1 = (unsigned char)((iInput >> 24) & 0xFF);
    *byte2 = (unsigned char)((iInput >> 16) & 0xFF);
    *byte3 = (unsigned char)((iInput >> 8) & 0xFF);
    *byte4 = (unsigned char)(iInput & 0xFF);
}


/* 

Function Global __cdecl packSigmatekIp
VAR_INPUT
  IN_BYTE4 : BSINT;
  IN_BYTE3 : BSINT; 
  IN_BYTE2 : BSINT;
  IN_BYTE1 : BSINT;  
  OUTPUT_IP : ^UDINT; 
END_VAR
VAR_OUTPUT
END_VAR;

*/
// Pack 4 bytes into a Sigmatek specific ip address scheme
extern "C" void packSigmatekIp(const unsigned char byte4, const unsigned char byte3, const unsigned char byte2, const unsigned char byte1, unsigned int *iOutputIp)
{
    *iOutputIp = ((unsigned int)byte1 << 24) | ((unsigned int)byte2 << 16) | ((unsigned int)byte3 << 8) | byte4;
}

/* 

Function Global __cdecl mergeUINT
VAR_INPUT
  MSB : UINT;
  LSB : UINT; 
END_VAR
VAR_OUTPUT
  Q : UDINT;
END_VAR;

*/
// merge two UINT Variables to one UDINT
extern "C" unsigned long int mergeUINT(const unsigned int msb, const unsigned int lsb)
{
    return (((unsigned long int)msb << 16) | (unsigned long int)lsb);
}

