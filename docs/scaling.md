# Scaling
The scaling function is used to scale a value from one range to another range. This function is often used to scale analog values from a sensor to a value that can be used in the PLC. For example, theresistance of an potentio meter can be scaled from 0-5000 Ohm to 0-100 %.

This function is also used to scale values from one unit to another. For example, a value in meters can be scaled to a value in millimeters.

Depending of the input datatyoe you have to choose the right function.


- [Scaling](#scaling)
  - [Syntax in Lasal Class 2](#syntax-in-lasal-class-2)
    - [map](#map)
    - [fMap](#fmap)
  - [Lasal Class 2 Example](#lasal-class-2-example)
    - [ST Code](#st-code)
    - [Class View](#class-view)

## Syntax in Lasal Class 2

### map
```
result : DINT = map(DINT : input, DINT : inLow, DINT : inHigh, DINT : outLow, DINT : outHigh)
```
| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| input  | DINT | Your input value |
| inLow  | DINT  | Your input value range low  |
| inHigh  | DINT  | Your input value range high  |
| outLow  | DINT  | Your output value range low  |
| outHigh  | DINT  | Your output value range high  |


### fMap
```
result : REAL = fMap(REAL : input, REAL : inLow, REAL : inHigh, REAL : outLow, REAL : outHigh)
```

| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| input  | REAL | Your input value |
| inLow  | REAL  | Your input value range low  |
| inHigh  | REAL  | Your input value range high  |
| outLow  | REAL  | Your output value range low  |
| outHigh  | REAL  | Your output value range high  |




## Lasal Class 2 Example
* You can find a compialable example by clicking here: [Example](https://github.com/Jumag-Dampferzeuger-GmbH/SIGMATEK-Jumag-Utils-Examples/tree/main/scaling)

### ST Code

```
Function Global __cdecl map
VAR_INPUT
  input : DINT;
  inLow : DINT;
  inHigh : DINT;
  outLow : DINT;
  outHigh : DINT;
END_VAR
VAR_OUTPUT
  result : DINT;
END_VAR;

Function Global __cdecl fMap
VAR_INPUT
  input : REAL;
  inLow : REAL;
  inHigh : REAL;
  outLow : REAL;
  outHigh : REAL;
END_VAR
VAR_OUTPUT
  result : REAL;
END_VAR;

FUNCTION VIRTUAL GLOBAL Class0::CyWork
	VAR_INPUT
		EAX 	: UDINT;
	END_VAR
	VAR_OUTPUT
		state (EAX) 	: UDINT;
	END_VAR
  
  input := input.Read();
  
  iScaled := map(input:= input, inLow:= -200, inHigh:=200, outLow:= 0, outHigh:= 100);
  fScaled := fMap(input:= TO_REAL(input), inLow:= TO_REAL(-200), inHigh:= TO_REAL(200), outLow:= 0.0, outHigh:= 1000.0);


	state := READY;

END_FUNCTION

```






### Class View
![Alt text](img/image-7.png)