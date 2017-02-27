/* Sweep
 Lucas Berbesson for La Fabrique DIY
  <https://www.youtube.com/channel/UCV8D6u7_jkuGf_iUvNzXpmg/videos>

 modified 19 Jan 2017
 by Lucas Berbesson
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servo_max_angle = 90; // max angle of the flag
int servo_min_angle = 30; // min angle of the flag

int flag_left = servo_max_angle + 5; 
int flag_right = servo_min_angle - 5;

int infusion_time_ms = 90000;
int count = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  //Infusing the tea bag
  myservo.write(min_tea);
  delay(infusion_time_ms);
  myservo.write(max_tea);
  delay(2000);
  //shaking the tea bag
  for (count = 1; count <= 25; count += 1) {
    delay(150);
    myservo.write(flag_left);              
    delay(150);      
    myservo.write(flag_right);  
    if ((count % 5) == 0 ) {
      delay(2000);                  
    }
  }
    //wait until you unplug the machine
    delay(160000);
}
