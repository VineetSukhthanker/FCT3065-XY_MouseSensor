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

**Arduino uses 5v logic and sensor uses 2.7-3.3v logic**
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

## Compatible Sensors ( List is incomplete )

1. Pixart(3204DB,3204L,3204LL,3204UL,3205,3207)
2. Sigma 8630/8630A/8640/8650A
3. OM15,0M16
4. PAW3212
5. VT108/KA8
6. FCT3065
7. FH8835
8. YS8008
9. S8321

## Resources

1. [Optical Mouse Camera | bidouille.org](https://www.bidouille.org/hack/mousecam)
2. [Optical Mouse Hacking | Conor Peterson](https://conorpeterson.wordpress.com/2010/06/04/optical-mouse-hacking-part-1/)
