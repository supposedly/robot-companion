Quick explanation of our file structure:

The Arduino extension for VSCode lets you use a dropdown to easily select which .ino file you want to upload.
Unfortunately, the dropdown also includes all .cpp files, even though Arduinos are only "supposed" to use .ino.
In order to get around that and stop clicking the wrong file all the time, we decided to just name everything
with the extension .h. It's wrong and ugly, but it helped during development!

As a result, to tell those fake .h's apart from files that are more like "actual" headers, we decided to capitalize
the names of the latter. That's why Commands.h and Common.h are capitalized, for example.
