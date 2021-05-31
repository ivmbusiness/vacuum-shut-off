# vacuum-shut-off

## This code is for an easy control vacuum pump with vacuum shut off valve. Pretty often need if you are building something using vacuum bagging process.

Code is very simple, bare minimum you need to control your pump (plus screen logic). Vacuum range is hard coded to from -60% to -70%. (assuming that -100% is full vacuum). Feel free to adjust it if needed by modifying constants. But in my case maximum pump was able to achieve is -80% and I am not sure that I want more - just so i don't crash my foam. In 60-70 range I see pretty awesome results (carbon fiber with epoxy, while most of the epoxy is pressed out into absorb fabric). 
```
const float onLimit=-60;
const float offLimit=-70;
```

What you are going to need:
- Arduino nano, or any other arduino you can program.. I was using nano just because I had a few of them and they have USB on board so it is easy to flush them. Plus, they are pretty small.
![Arduino image](/images/arduino.jpeg)
- Power source (I am using 21v) and probably step down if your power source above 5v. I am using dc to dc adjustable step down, just because I have few of them.
![sensor](/images/stepdown.jpeg)
- Vacuum sensor. In my case it is the only one i was able to find on ebay for reasonable price. It is -14.5 - +30psi. If you use different one you may have to adjust code.
![sensor](/images/sensor.jpeg)
- Solid state relay so you can control your AC vacuum pump (110/220 AC or whatever you have). Using this relay because you can connect it directly to arduino digital out pin.
![relay](/images/relay.jpeg)
- Screen for Arduino 128x128 SPI TFT - optional but I had one so I am using one to display what is going on.
![screen](/images/screen.jpeg) ![screen](/images/screen1.jpeg)

what to do Step By Step:

1. Solder you DC power supply to dc step down. It has IN- and IN+. Plug it in and adjust it so OUT- and OUT+ has 5-6v. It Depend on Nano manufacturer but most of them don't like 12v.
1. Flush program from this repository into Arduino
  1. Install Arduino IDE if you don't have it yet
  1. Open the only .ino file through File > Open
  1. Select Arduino nano as you device through Tools > Board > Arduino AVR Boards > Arduino NANO
  1. Connect your arduino to USB on your laptop and make sure Port is selected through Tools > Port. Ususally port is selected automatically.
  1. Hit Compile button just in case. Observer "Done compiling." message at the bottom. Hit Upload button and observe progress and done upload messages in the output at the bottom. 
1. Solder everything to arduino:
   1. Screen
      1. Arduino D8 to A0 pin on screen
      1. Arduino D9 to RESET pin on screen 
      1. Arduino D10 to CS pin on screen
      1. Arduino D11 to SDA pin on screen
      1. Arduino D13 to SCK pin on screen
      1. Arduino GND - to GND on screen
      1. Arduino 5v to VCC on screen and to LED on screen. 
   1. If you don't want screen you can reduce this program to minimum by removing everything screen related. Or just comment out every line which has `screen.` in it.
   1. Vacuum sensor
      1. Arduino 5v to Red on sensor
      1. Arduino GND to Balck on sensor
      1. Arduino A4 to Green on sensor
   1. Solid state relay
      1. Arduino D4 to to Input+ on relay
      1. Arduino GND to Input- on relay
      1. Cut hot wire on your pump power line and connect it to AC relay contacts
   1. Connect output of step-down (or power supply if you don't use a step down) to Arduino
      1. step down Out- to Arduino GND
      2. step down Out+ to Arduino VIN

Here is my schematics drawings, just to see whole picture all togather:
![schematic](/images/schematic.jpeg)
        
