# Edge Detection
This funtion is similiar to R_TRIG and F_TRIG of Codesys and is used to detect a rising or falling edge of a ```DINT``` variable. 


- [Edge Detection](#edge-detection)
  - [Syntax](#syntax)
    - [Rising Edge Detection](#rising-edge-detection)
    - [Falling Edge Detection](#falling-edge-detection)
  - [Lasal Class 2 Example](#lasal-class-2-example)
    - [ST Code](#st-code)
    - [Necessary Variables](#necessary-variables)

## Syntax
* this function needs a locale ```^DINT``` Pointer in the Class

### Rising Edge Detection
```
result : BOOL = rTrig_DINT(DINT : inputSignal, ^DINT : prevSignal, DINT : triggerVal)
```

| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| inputSignal  | DINT | Your 0/1 value or analog signal which should be triggered |
| prevSignal  | ^DINT  | locale pointer variable for storing the old signal value  |
| triggerVal  | DINT  | target trigger value |

### Falling Edge Detection
```
result : BOOL = fTrig_DINT(DINT : inputSignal, ^DINT : prevSignal, DINT : triggerVal)
```

| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| inputSignal  | DINT | Your 0/1 value or analog signal which should be triggered |
| prevSignal  | ^DINT  | locale pointer variable for storing the old signal value  |
| triggerVal  | DINT  | target trigger value |



## Lasal Class 2 Example
* You can find a compialable example by clicking here: [Example](https://github.com/Jumag-Dampferzeuger-GmbH/SIGMATEK-Jumag-Utils-Examples/tree/main/edgeDetection)

### ST Code

```
Function Global __cdecl rTrig_DINT
VAR_INPUT 
  inputSignal : DINT;
  prevSignal : ^DINT;
  triggerVal : DINT;
END_VAR
VAR_OUTPUT
  result : BOOL;
END_VAR;

Function Global __cdecl fTrig_DINT
VAR_INPUT
  inputSignal : DINT;
  prevSignal : ^DINT;
  triggerVal : DINT;
END_VAR
VAR_OUTPUT
  result : BOOL;
END_VAR;

FUNCTION VIRTUAL GLOBAL Class0::CyWork
	VAR_INPUT
		EAX 	: UDINT;
	END_VAR
	VAR_OUTPUT
		state (EAX) 	: UDINT;
	END_VAR
  
  VAR
  	oldSignal0 : ^DINT; 
    oldSignal1 : ^DINT; 
  END_VAR
  
  signal := signal.Read();
  
  risingTriggered := rTrig_DINT(inputSignal:= signal, prevSignal:= oldSignal0, triggerVal:= targetValue);

  fallingTriggered := fTrig_DINT(inputSignal:= signal, prevSignal:= oldSignal1, triggerVal:= targetValue);
 
	state := READY;

END_FUNCTION

```






### Necessary Variables
![Alt text](img\image-1.png)