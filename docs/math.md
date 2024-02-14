# Math functions
The math.c file collects several mathematical functions


- [Math functions](#math-functions)
    - [Syntax in Lasal Class 2](#syntax-in-lasal-class-2)
  - [Min / Max Functions](#min--max-functions)
    - [fMin](#fmin)
    - [aMin](#amin)
  - [Lasal Class 2 Example](#lasal-class-2-example)
    - [ST Code](#st-code)
    - [Class View](#class-view)

### Syntax in Lasal Class 2

## Min / Max Functions
Functions for calculating the highest or lowest value of multiple input variables
### fMin
```
Q : REAL = fMin(CMP1 : REAL, CMP2 : REAL)
```
| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| CMP1  | DINT | compare value 1 |
| CMP2  | DINT  | compare value 2 |



### aMin
* the ARRAY must be a Pointer for this function
```
Q : REAL = aMin(INPUT : ^REAL, SIZE : DINT)
```

| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| INPUT  | REAL | Input ```ARRAY OF ^REAL ``` |
| SIZE  | REAL  | index size of the array  |


## Lasal Class 2 Example
* You can find a compialable example by clicking here: [Example](https://github.com/Jumag-Dampferzeuger-GmbH/SIGMATEK-Jumag-Utils-Examples/tree/main/math)

### ST Code

```
Function Global __cdecl fMin
VAR_INPUT
  CMP1 : REAL;
  CMP2 : REAL; 
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

Function Global __cdecl aMin
VAR_INPUT
  INPUT : ^REAL;
  SIZE : DINT; 
END_VAR
VAR_OUTPUT
  Q : REAL;
END_VAR;

Function Global __cdecl linCongGen
VAR_INPUT 
  INPUT : DINT;
  FACTOR : DINT; 
  INCREMENT : DINT; 
  MODULO : DINT; 
END_VAR
VAR_OUTPUT
  Q : DINT;
END_VAR;

(*
 cConstants.h && randomizer.c are also custom functions of the https://github.com/Jumag-Dampferzeuger-GmbH/SIGMATEK-Jumag-Utils Repo 
 which are only necessary for creating pseudo data for the array
*)

FUNCTION VIRTUAL GLOBAL Class0::CyWork
	VAR_INPUT
		EAX 	: UDINT;
	END_VAR
	VAR_OUTPUT
		state (EAX) 	: UDINT;
	END_VAR

  
  // get the min Values 
  fMinResult      := fMin(CMP1:= fTestValue0 , CMP2:= fTestValue1);
  fMinArrayResult := aMin(INPUT:=#aTestData[0], SIZE:=ARRAY_SIZE);
  
  

	state := READY;

END_FUNCTION


FUNCTION VIRTUAL GLOBAL Class0::Init 
  VAR
  	i : SINT; 
  END_VAR
  // Create pseudo data

    fTestValue0 := 234.0;
    fTestValue1 := 345345.0;
    
    for i := 0 to ARRAY_SIZE by 1 do
      aTestData[i] := to_real(linCongGen(INPUT:=i, FACTOR:=i+1, INCREMENT:=i*3, MODULO:=1000)); 
    end_for;


END_FUNCTION

```

### Class View
![Alt text](docs/img/image-9.png)