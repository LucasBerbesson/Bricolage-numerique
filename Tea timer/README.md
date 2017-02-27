# Tea Machine
This is the code of the machine you can see on this video :

https://www.youtube.com/watch?v=OaB_y4gYeH8

The machine itself is really simple, everything works with a single servo motor. 
The servo power cables (normally red and brown) is attached to the 5V and GND outputs of the Arduino.
The command cable (normally orange) is attached to pin 9 of the Arduino Uno.

# Expected behaviour

The machine should put the tea bag inside the cup and wait during `infusion_time_ms` milliseconds (to be re-defined inside the .ino file) before removing the bag from the cup and shaking it 25 times to remove the drops.

The overall movement is controlled by the string attached to the flag, therefore by the angle of the flag, therefore by the min and max angles of the servo motor in the programm: `servo_max_angle` and `servo_min_angle`

Good Luck !
