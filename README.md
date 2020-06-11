# Fork of Cloug42 Lathe Electronic Leadscrew Controller

This is the firmware for an experimental lathe electronic leadscrew controller.  The goal is to replace the change
gears or gearbox on a metalworking lathe with a stepper motor controlled electronically based on an encoder on the
lathe spindle.  The electronic controller allows setting different virtual gear ratios for feeds and threading.

## Fork Status

This is a fork of the original project.  The display has been replaced with a Nextion color LCD + touch screen to
allow for a better UI.  Most of the hardware interface code on the microcontroller has also been re-written to use
Ti's latest libraries and recommendations (and it makes for easier to read and modify code).

This is an early drop and has bugs, but I've been using it for months on my own system.

Future plans:
* Read DRO input over serial to provide virtual compound angle feature.  This is helpful on lathes where the
compound has been removed and replaced by a stouter toolpost mount.
* Threading mode
* Turning mode with a fixed stop point

The documentation below is only lightly edited from Clough42's version.

## Project Status
Design and prototyping.

**NOTE: This is still a work in progress and is subject to change.  Many people have expressed interest in buying parts
and following along with the build.  That's great!  Just be aware that this hasn't been tested and refined end-to-end yet, so
things like stepper motors, servos, drivers, display boards are likely to change as the project progresses.**

## Documentation
For documentation, please [**visit the project wiki**](https://github.com/clough42/electronic-leadscrew/wiki).

## Current Concept
The project is still in the early stages of development.  The current hardware looks like this:
* Use a TI F280049C Piccolo microcontroller on a LaunchXL prototyping board
* Read the spindle position using a rotary encoder
* Use a standard stepper motor and driver on the lathe leadscrew
* Use a simple control interface 
* Make as few modifications to the lathe as possible:
  * Use the original leadscrew and halfnuts without machining
  * Drive the leadscrew through the factory input shaft
  * Drive the encoder from the factory spindle gear train
  * Make it easy to restore the lathe to the original change gear configuration  

## Non-Goals
This is not a CNC project.  The goal is not to control the lathe automatically, but rather to transparently
replace the lathe change gears or quick-change gearbox with an electronic virtual gearbox that can be quickly
set to almost any ratio.  The lathe will continue to operate normally, with the operator closing and opening
the half-nuts to control feeding and threading.

### External Connections

#### Serial Port to Nextion Display
The serial is mapped to the microcontrollers Serial Port B
* GPIO40 is pin 3 and SCIBRX
* GPIO13 is pin 4 and SCIBTX

#### Encoder
A quadrature encoder for the spindle is connected to the eQEP connector, J12.

#### Stepper Driver
A Step-direction stepper motor driver should be connected to the following GPIO pins:
* `GPIO0` (J8 pin 80) - Step
* `GPIO1` (J8 pin 79) - Direction
* `GPIO6` (J8 pin 78) - Enable
* `GPIO7` (J8 pin 77) - Alarm input

#### SCI Bus
SCI Bus is no longer used (that went to the control panel on Clough42's version)
