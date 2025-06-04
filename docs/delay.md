# Delay 
The ton and tof functions are used for delaying signals. 

- [Delay](#delay)
  - [Syntax in Lasal Class 2](#syntax-in-lasal-class-2)
    - [DelayTof](#delaytof)
    - [DelayTon](#delayton)
    - [Lasal Class 2 Example](#lasal-class-2-example)
    - [ST Code](#st-code)
    - [Class View](#class-view)
    - [DelayTonOff](#delaytonoff)
    - [Lasal Class 2 Example](#lasal-class-2-example-1)
    - [ST Code](#st-code-1)

## Syntax in Lasal Class 2

### DelayTof
* If the input signal is falling from true to false the output signal will be true for the time of PT. The output is immediately true if the input signal is true.
```
Q : BOOL = DelayTof(IN : BOOL, PT : DINT , ET: ^UDINT , TIMESTAMP: ^UDINT, CLOCK : UDINT)
```

| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| IN  | BOOL | Input signal |
| PT  | DINT | Time in ms |
| ET  | ^UDINT | Pointer to the elapsed time |
| TIMESTAMP  | ^UDINT | Pointer to the timestamp for saving the  ```ops.tAbsolute```  time|
| CLOCK  | UDINT | Clock signal ```ops.tAbsolute``` |
| Q  | BOOL | Output signal |

### DelayTon
* if the input signal is switching from false to true the output is true after reaching the time PT. If the input signal is switching to false the output will be immediately false.


```
Q : BOOL = DelayTon(IN : BOOL, PT : DINT , ET: ^UDINT , TIMESTAMP: ^UDINT, CLOCK : UDINT)
```

| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| IN  | BOOL | Input signal |
| PT  | DINT | Time in ms |
| ET  | ^UDINT | Pointer to the elapsed time |
| TIMESTAMP  | ^UDINT | Pointer to the timestamp for saving the  ```ops.tAbsolute```  time|
| CLOCK  | UDINT | Clock signal ```ops.tAbsolute``` |
| Q  | BOOL | Output signal |



### Lasal Class 2 Example
* You can find a compialable example by clicking here: [Example](https://github.com/Jumag-Dampferzeuger-GmbH/SIGMATEK-Jumag-Utils-Examples/tree/main/delay)

### ST Code

```

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


FUNCTION VIRTUAL GLOBAL ton::CyWork
	VAR_INPUT
		EAX 	: UDINT;
	END_VAR
	VAR_OUTPUT
		state (EAX) 	: UDINT;
	END_VAR
  VAR
  	x : BOOL; 
  END_VAR


  if (input = 1)  then
    x := true; 
    else 
      x := false; 
  end_if;

  
  ClassSvr := DelayTon(IN:=x, PT:=targetTime, ET:=#elapsedTime, TIMESTAMP:=#timeStamp, CLOCK:=ops.tAbsolute);

	state := READY;

END_FUNCTION

```


### Class View
![alt text](img/image-12.png)


### DelayTonOff
* if the input signal is switching from false to true the output is true after reaching the PT_on time. If the input signal is switching to false the output will be false after the PT_off time.


```
Q : BOOL = DelayTon(IN : BOOL, PT_ON : DINT , PT_OFF : DINT ,ET_ON: ^UDINT ,ET_OFF: ^UDINT , TIMESTAMP: ^UDINT, CLOCK : UDINT)
```

| Argument | Datatype | Meaning |
| ------------- | ------------- | ------------- |
| IN  | BOOL | Input signal |
| PT_ON  | DINT | On Delay time in ms |
| PT_OFF  | DINT | Off Delay time in ms |
| ET_ON  | ^UDINT | Pointer to the elapsed On time |
| ET_OFF  | ^UDINT | Pointer to the elapsed Off time |
| TIMESTAMP  | ^UDINT | Pointer to the timestamp for saving the  ```ops.tAbsolute```  time|
| CLOCK  | UDINT | Clock signal ```ops.tAbsolute``` |
| Q  | BOOL | Output signal |



### Lasal Class 2 Example
* You can find a compialable example by clicking here: [Example](https://github.com/Jumag-Dampferzeuger-GmbH/SIGMATEK-Jumag-Utils-Examples/tree/main/delay)

### ST Code

```

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

FUNCTION VIRTUAL GLOBAL tonof::CyWork
	VAR_INPUT
		EAX 	: UDINT;
	END_VAR
	VAR_OUTPUT
		state (EAX) 	: UDINT;
	END_VAR
  
  ClassSvr := DelayTonOff(IN:=input=1, PT_ON:=targetTimeOn, PT_OFF:=targetTimeOff, ET_ON:=#elapsedOn, ET_OFF:=#elapsedOff, TIMESTAMP:=#ts, CLOCK:=ops.tAbsolute);

	state := READY;

END_FUNCTION


```