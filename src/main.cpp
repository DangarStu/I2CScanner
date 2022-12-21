#include <Wire.h>
#include <Arduino.h>

void setup(void) 
{
    Serial.begin(115200);
    Wire.begin(16,17);
    Serial.println("Starting scanning.");
}

void loop()
{
  byte error, address; //variable for error and I2C address
  int nDevices = 0;


  for (address = 8; address < 120; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
  
   Serial.println("In loop.");

  delay(5000); // wait 5 seconds for the next I2C scan
}