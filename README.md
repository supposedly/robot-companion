# Robot companion
![Diagram and images](https://github.com/supposedly/robot-companion/assets/32081933/46e5e929-57b4-488f-88bc-83796a6248c7)

This code controls a robot running on two Arduinos communicating over SoftwareSerial: a Mega board to control its
motors and display, and an Uno board to control its environment sensors. I made this with a partner who was in charge
of designing and assembling the robot's chassis and physical internals.

At a high level, the Uno continuously streams sensor data to the Mega so it knows to update the display or the motors,
which it does by sending them "commands" that take different overwrite priorities based on the source of the data
(e.g. which sensor).

## Functionality

- Accept Bluetooth commands for movement and emoting.
- Follow a hand or other object placed near the front of the robot. (The "eyes" are an ultrasonic distance sensor, flanked
  by IR sensors for obstacle detection.)
- Sleep ("Zzz" emote) and stop moving if too dark.
- Sweat if too hot. Shiver if too cold.

## File structure and idiosyncrasies
The Arduino extension for VSCode lets you use a dropdown to easily select which .ino file you want to upload.
Unfortunately, the dropdown also includes all .cpp files, even though Arduinos are only "supposed" to use .ino.
In order to get around that and stop clicking the wrong file all the time, we decided to just name everything
with the extension .h. It's wrong and ugly, but it helped during development!

As a result, to tell those fake .h's apart from files that are more like "actual" headers, we decided to capitalize
the names of the latter. That's why Commands.h and Common.h are capitalized, for example.
