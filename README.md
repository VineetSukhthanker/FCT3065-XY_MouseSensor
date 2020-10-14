# FCT3065-XY Optical Mouse Sensor with Arduino

Program to interface FCT3065-XY Optical Mouse Sensor with Arduino.
This code detects when mouse is moved and also prints the change
in x direction and change in y direction in the serial monitor.

Datasheets given are of other related Optical Mouse Sensors which I
referred to get register addresses and configurations available for
this mouse sensor as I couldn't find a datasheet for FCT3065-XY.

## Connections

[Mouse Sensor Pinout](MouseSensor.png)

1. Connect pin 7 (VDD) of sensor to 3.3v of Arduino.
2. Connect pin 6 (GND) of sensor to GND of Arduino.
3. Connect pin 4 (SCLK/ Clock) of sensor to pin 2 of Arduino.
4. Connect pin 3 (SDIO/ Data) of sensor to pin 3 of Arduino.

**Arduino uses 5v voltage logic and sensor uses 3.3v voltage logic**
**Use a voltage level shifter or a voltage divider to interface sensor with arduino**
**5 volts can damage the Sensor**

## What is working

- Read registers
- Write to registers
- Fetch changes on X and Y axes

## What is not working

- Cannot retrieve surface image as image is processed internally by sensor.

## Unknown information

- Sensor resolution
- Frames per second

## Resources

1. [Optical Mouse Camera | bidouille.org](https://www.bidouille.org/hack/mousecam)
2. [Optical Mouse Hacking | Conor Peterson](https://conorpeterson.wordpress.com/2010/06/04/optical-mouse-hacking-part-1/)
