# Name The Game, Spin The Wheel

This repository houses all the code used to develop the fortunte-wheel-inspired game: Name The Game, Spin The Wheel.


**Description**

Simply put, Name The Game, Spin The Wheel (NS) is a user-centric game giving users the opportunity to choose which
game to play. From 21 to HighLow, this simple game allows for all sorts of fun! 



**Meet the Team**

Jeffrey Becko | Anthony Flores-Alvarez | Mahdi Ali-Raihan | Ekene Ezeunala | Mario Carrillo-Bello 



*Physical Components*

NS is made up of the characteristic wheel with  numbers 1 through 8, 2 buttons handling the speed of the wheel,
game lights, and a sound system.

**How it Works/Under the Wheel**

After selecting your game, the green button will spin the wheel. When you feel the moment is right, pressing the
red button will begin its halt, all while your wonderous music is played. With the results, determine your winners!


On the note of the wheel, instead of allowing for the wheel to come to a stop on its own, as is the case with most wheels, this wheel's stop is entirely programatically-driven. That is, we programmed the motor that creates the spin to stop in a certain amount of time by tampering with its velocity and rpm. This motor and the buttons are all connected to a breadboard that also houses the Arduino UNO where our code is stored, a microSD reader, a speaker, and a portable battery that powers the whole game. 


The sound system is another component consisting of a speaker that is connected to the microSD card reader through
the breadboard. On the microSD card we have .wav files of the songs (KC&TheSunshineBand was our obvious choice) that
are then passed and played by the speaker. 

