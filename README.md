# vacuum-shut-off

## This code is for an easy control vacuum pump with vacuum shut off valve. Pretty often need if you are building something using vacuum bagging process.

What you are going to need:
- Arduino nano, or any other arduino you can prgram.. I was using nano just because i had a few of them and they have usb on board so it is easy to flush them. Plus, they are pretty small.
this is my arduino: ![Arduino image](/images/arduino.png)
- Power source (i am using 21v) and probably step down if your power source above 5v. I am using dc to dc ajustable step down, just because i have few of them.
- Vacuum sensor. in My case it is the only one i was able to find on ebay. It is -14.5 - +30psi.
my sensor: ![sensor](/images/sensor.png)
- Solid state relay so you can control your high voltage pump (110/220 AC or whatever you have). Using this relay because you can connect tit directly to arduino digital pin.
soid state relay: ![relay](/images/relay.png)
- Screen for Arduino - optional but I had one so I am using one to display what is going on.
my screen: ![screen](/images/screen.png)
