/*
 * Program to interface FCT3065-XY Optical Mouse
 * Sensor with Arduino.
 * 
 * Author: Vineet Sukhthanker
 * Date: 6 October 2020
 * 
 * 
 */

const int SCLK = 2;
const int SDIO = 3;
//const int RESET = 4;

byte noSleep = 0xA0;

//Register Addresses from datasheet
#define PROD_ID1 0x00
#define PROD_ID2 0x01
#define MOTION_STATUS 0X02
#define DEL_X 0x03
#define DEL_Y 0x04
#define OP_MODE 0x05
#define CONF 0x06
#define IMG_QUALITY 0x07
#define OP_STATE 0x08
#define W_PROTECT 0x09
#define SLEEP1_SET 0x0A
#define ENTER_TIME 0x0B
#define SLEEP2_SET 0x0C
#define IMG_THRESHOLD 0x0D
#define IMG_RECOG 0x0E

void setup() {
  pinMode (SCLK, OUTPUT);
  Serial.begin(115200);
  
  mouseInit();
  byte prodId1 = readRegister(PROD_ID1);
  byte opMode = readRegister(OP_MODE);
  Serial.print("\nProduct ID1:");
  Serial.print(prodId1,HEX);
  Serial.print("\nOperation Mode:");
  Serial.print(opMode,HEX);
}

void loop() {

}

void mouseInit(void)
{
  digitalWrite(SCLK, HIGH);
  digitalWrite(SCLK, LOW);
  delayMicroseconds(1); // tRESYNC = 1us (mentioned in datasheet)
  digitalWrite(SCLK, HIGH);
  delay(320); // tSIWTT = 320ms (mentioned in datasheet)
  digitalWrite(SCLK, LOW);
  writeRegister(OP_MODE, noSleep); // disable sleep mode
}

byte readRegister(byte address) {
  pinMode (SDIO, OUTPUT);

  for (byte i=128; i >0 ; i >>= 1) {
    digitalWrite (SCLK, LOW);
    digitalWrite (SDIO, (address & i) != 0 ? HIGH : LOW);
    digitalWrite (SCLK, HIGH);
  }

  pinMode (SDIO, INPUT);

  delayMicroseconds(3); // tHOLD = 3us (mentioned in datasheet)

  byte res = 0;
  for (byte i=128; i >0 ; i >>= 1) {
    digitalWrite (SCLK, LOW);
    digitalWrite (SCLK, HIGH);
    if( digitalRead (SDIO) == HIGH )
      res |= i;
  }

  delayMicroseconds(3); // tHOLD = 3us min. (mentioned in datasheet)
 
  return res;
}

void writeRegister(byte address, byte data) {
  address |= 0x80; // MSB indicates write mode.
  pinMode (SDIO, OUTPUT);

  for (byte i = 128; i > 0 ; i >>= 1) {
    digitalWrite (SCLK, LOW);
    digitalWrite (SDIO, (address & i) != 0 ? HIGH : LOW);
    digitalWrite (SCLK, HIGH);
  }

  for (byte i = 128; i > 0 ; i >>= 1) {
    digitalWrite (SCLK, LOW);
    digitalWrite (SDIO, (data & i) != 0 ? HIGH : LOW);
    digitalWrite (SCLK, HIGH);
  }

  delayMicroseconds(100);
}
