# Lathe Electronic Leadscrew Controller

This is the firmware for an experimental lathe electronic leadscrew controller.  The goal is to replace the change
gears or gearbox on a metalworking lathe with a stepper motor controlled electronically based on an encoder on the
lathe spindle.  The electronic controller allows setting different virtual gear ratios for feeds and threading.

## Project Status
Design and prototyping.

## Current Concept
The project is still in the early stages of development.  The current hardware looks like this:
* Use a TI F28069M Piccolo microcontroller on a LaunchXL prototyping board
* Use an inexpensive SPI "LED&Key" import display and keypad for the user interface
* Read the spindle position using a rotary encoder with a 3D-printed gear
* Use a standard stepper motor and driver on the lathe leadscrew

The current plan is to support the following operations:
* Multiple feeds in thousandths of an inch per revolution
* Multiple feeds in hundredths of a millimeter per revolution
* Multiple imperial thread pitches (in threads-per-inch)
* Multiple metric thread piches (in millimeters)

## Non-Goals
This is not a CNC project.  The goal is not to control the lathe automatically, but rather to transparently
replace the lathe change gears or quick-change gearbox with an electronic virtual gearbox that can be quickly
set to almost any ratio.  The lathe will continue to operate normally, with the operator closing and opening
the half-nuts to control feeding and threading.
