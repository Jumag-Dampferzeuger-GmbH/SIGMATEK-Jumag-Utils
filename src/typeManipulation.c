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
  Q : UINT;
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
extern "C" void packSigmatekIp(unsigned char byte4, unsigned char byte3, unsigned char byte2, unsigned char byte1, unsigned int *iOutputIp)
{
    *iOutputIp = ((unsigned int)byte1 << 24) | ((unsigned int)byte2 << 16) | ((unsigned int)byte3 << 8) | byte4;
}