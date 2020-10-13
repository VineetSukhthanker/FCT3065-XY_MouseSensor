# FCT3065-XY Optical Mouse Sensor

Program to interface FCT3065-XY Optical Mouse Sensor with Arduino.
This code detects when mouse is moved and also prints the change
in x direction and change in y direction in the serial monitor.

Datasheets given are of other related Optical Mouse Sensors which I
referred to get register addresses and configurations available for
this mouse sensor as I couldn't find a datasheet for FCT3065-XY.

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
