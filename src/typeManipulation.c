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

Function Global __cdecl splitDINT
VAR_INPUT
  IN : DINT;
  MSB : BSINT;
  LSB : BSINT; 
END_VAR
VAR_OUTPUT
  Q : UINT;
END_VAR;

*/
// split one DINT (16bit) to two BSINT (8bit)
extern "C" void splitDINT(int iInput, unsigned char *msByte, unsigned char *lsByte)
{
    *msByte = (unsigned char)(iInput >> 8);
    *lsByte = (unsigned char)(iInput & 0xFF);
}

/* 

Function Global __cdecl unpackSigmatekIp
VAR_INPUT
  INPUT_IP : UDINT;
  BYTE4 : ^BSINT;
  BYTE3 : ^BSINT; 
  BYTE2 : ^BSINT;
  BYTE1 : ^BSINT;   
END_VAR
VAR_OUTPUT
END_VAR;

*/
// Unpack the Sigmatek specific ip address scheme into 4 bytes 
extern "C" void unpackSigmatekIp(unsigned int iInputIp, unsigned char *byte4, unsigned char *byte3, unsigned char *byte2, unsigned char *byte1)
{
    *byte1 = (iInputIp >> 24) & 0xFF;
    *byte2 = (iInputIp >> 16) & 0xFF;
    *byte3 = (iInputIp >> 8) & 0xFF;
    *byte4 = iInputIp & 0xFF;
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