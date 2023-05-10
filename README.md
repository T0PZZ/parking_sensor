# Parking Sensor
My first arduino project with parking sensor, turn signals, front and back lights.  

## Libraries
```#include <U8glib.h>```

## Functionality
1) Button 1 turns on  white and red diodes (front and back lights) on the fist press, and disables them on the second press.
2) Button 2 turns on right turn singnals            <i>(blinking 7 times due to ```for loop``` usage).</i>
3) Button 3 turns on left  turn singnals            <i>(blinking 7 times due to ```for loop``` usage).</i>
4) Button 4 enables buzzer with first press and disables with second .
5) Buzzer is silent when distance to obstacle is <b>greater than 100 cm.</b>
6) Buzzer is  buzzing with 500ms interval when distance to obstacle is <b>between 100 and 50 cm.</b>
7) Buzzer is constantly buzzing when distance to obstacle is <b>lesser than 50 cm.</b>
8) Oled screen is displaying string <b>"Distance:       [cm]"</b> with int (distance).

### Component list:
- 1 x HC-SR04 Ultrasonic sensor
- 4 x tact swith
- 4 x yellow led 
- 2 x white led 
- 2 x red led 
- 4 x 330 kOHM resistors
- 1 x buzzer 
- 1x oled screen (SPI)
- bunch of cables

## *DISCLAIMER* 
<b><i> SPI OLED display is currently not supported by wokwi.com, so I have used I2C one in example below</b></i>.

### Virtual arduino build 
Virtual build was made using  [wokwi.com](https://wokwi.com/)

Virtual model [CLICK](https://wokwi.com/projects/364366618965865473).

### Electrical Scheme 
![Scheme](https://i.imgur.com/M7tUTZr.png)
