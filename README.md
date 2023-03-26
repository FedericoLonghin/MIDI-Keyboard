# MIDI Keyboard
## Short summary:
In this document I'm trying to document all the steps and details behind the transformation from an old organ to a MIDI controller.

## Schematics and PCBs:
Here you can find schematics and PCB's gerber files:
- [Keyboard Serializer](https://oshwlab.com/federicolonghin/midi-keyboard)
- [Analog Multiplexer](https://oshwlab.com/federicolonghin/analog-multiplexer)

## Parts and Composition:
The controller composed of two 44 keys keyboard, one pedal board, one pedal, sliders, knobs, switches etc.

One big obstacle of the project is the amount of inputs to be managed. For doing that I used four custom pcbs mounting 6 PISO (Parallel In Serial Out) shift register each. In this way I can read all Inputs using only 3 GPIO.

At the moment everything is running on an Arduino Leonardo board mounting an Atmega 32U4 chip. 

## IO Connections
| Board's pin | Type  | Name     |
| ----------- | ----- | -------- |
| D1          | D-OUT | DIN_CLK  |
| D2          | D-OUT | DIN_LD   |
| D3          | D_IN  | DIN_IN   |
| D4          | D_OUT | AIN_SEL0 |
| D5          | D_OUT | AIN_SEL1 |
| D6          | D_IN  | POW_PRES |
| A0          | A_IN  | AIN_A1   |
| A1          | A_IN  | AIN_A2   |
| A2          | A_IN  | AIN_A3   |
| A3          | A_IN  | AIN_A4   |

