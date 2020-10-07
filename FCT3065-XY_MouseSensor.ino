/*
 * Program to interface FCT3065-XY Optical Mouse
 * Sensor with Arduino.
 * 
 * Author: Vineet Sukhthanker
 * Date: 6 October 2020
 * 
 * 
 */

int SCLK = 2;
int SDIO = 3;
int RESET = 4;

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
  Serial.begin(115200);

  reset();
  byte prodId1 = readRegister(PROD_ID1);
  byte prodId2 = readRegister(PROD_ID2);
  byte conf = readRegister(CONF);
  byte opMode = readRegister(OP_MODE);
  Serial.print("\nProduct ID1:");
  Serial.print(prodId1);
  Serial.print("\nOperation Mode:");
  Serial.print(opMode);
}

void loop() {

}

void reset() {
  pinMode(SCLK, OUTPUT);
  pinMode(SDIO, INPUT);
  pinMode(RESET, OUTPUT);
  digitalWrite(SCLK, LOW);
  digitalWrite(RESET, HIGH);
  delayMicroseconds(1);
  digitalWrite(RESET, LOW);
}

byte readRegister(byte address) {
  pinMode (SDIO, OUTPUT);

  for (byte i=128; i >0 ; i >>= 1) {
    digitalWrite (SCLK, LOW);
    digitalWrite (SDIO, (address & i) != 0 ? HIGH : LOW);
    digitalWrite (SCLK, HIGH);
  }

  pinMode (SDIO, INPUT);

  delayMicroseconds(3); // tHOLD = 3us min.

  byte res = 0;
  for (byte i=128; i >0 ; i >>= 1) {
    digitalWrite (SCLK, LOW);
    digitalWrite (SCLK, HIGH);
    if( digitalRead (SDIO) == HIGH )
      res |= i;
  }

  return res;
}
