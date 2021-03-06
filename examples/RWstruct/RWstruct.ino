/* Example program for use with EEPROMsimple.h - sending structures to 25LC1024
   Arduino Uno Memory Expansion Sample Program
   Author: This headache belonged to David Dubins 12-Dec-18
   Library created and expanded by: D. Dubins 23-Jan-20
   Sample program to use a Serial EEPROM chip to expand memory for an Arduino Uno
   giving access to an additional 128kB of random access memory.  The 25LC1024 uses
   the Serial Peripheral Interface (SPI) to transfer data and commands between the
   UNO and the memory chip.
   Used the following components:
   (1) Arduino Uno
   (2) Microchip 25LC1024 SPI EEPROM chip
   
   Wiring:
   25LC1024 - Uno:
   ---------------
   pin 1 -- D10 (SS)
   pin 2 -- D12 (MISO)
   pin 3, 7, 8 -- +5V
   pin 4 -- GND
   pin 5 -- D11 (MOSI)
   pin 6 -- D13 (SCK)
*/

#include <EEPROMsimple.h>

#define CSPIN 10       // Default Chip Select Line for Uno (change as needed)

EEPROMsimple EEPROM;       // initialize an instance of this class

void setup()
{
  Serial.begin(9600);                         // set communication speed for the serial monitor
  SPI.begin();                                // start communicating with the memory chip
  
  /*******************  Create a dummy structure and objects  ******************/
  struct chemElements {  // declaring a structured array
    char atomName[10];   // size of largest length char array + 1 for null character
    int atomNum;
    float MW;
  }; //declare organicA to send data and organicB to receive data

  union txUnion{
    chemElements organicA[4]; // object organicA as an array of chemElements
    byte byteArrA[sizeof(organicA)]; // byte array sharing the same space
  };
  union txUnion txData; // create a new union instance called txData
  
  // Fill objects with data
  strcpy(txData.organicA[0].atomName,"Hydrogen");
  txData.organicA[0].atomNum=1;
  txData.organicA[0].MW=1.000794;

  strcpy(txData.organicA[1].atomName,"Carbon");
  txData.organicA[1].atomNum=6;
  txData.organicA[1].MW=12.0107;

  strcpy(txData.organicA[2].atomName,"Nitrogen");
  txData.organicA[2].atomNum=7;
  txData.organicA[2].MW=14.0067;

  strcpy(txData.organicA[3].atomName,"Oxygen");
  txData.organicA[3].atomNum=8;
  txData.organicA[3].MW=15.9994;
  
/************  Write a Sequence of Bytes from an Array *******************/
  Serial.println("\nWriting byte array using Sequential:");
  EEPROM.WriteByteArray(0, txData.byteArrA, sizeof(txData.byteArrA));        // Write array to memory starting at address 0

/************ Read a Sequence of Bytes from Memory into an Array **********/
  union rxUnion{  // create a union for receiving data and reading as chemElements structure
    chemElements organicB[4];  // object organicB as an array of chemElements
    byte byteArrB[sizeof(organicB)]; // byte array sharing the same space
  };
  union rxUnion rxData; // create a new union instance called rxData
   
  Serial.println("Reading byte array using sequential: ");
  EEPROM.ReadByteArray(0, rxData.byteArrB, sizeof(rxData.byteArrB));   // Read array into byteArrB starting at address 0

  for(int i=0;i<4;i++){
    Serial.println(rxData.organicB[i].atomName); // print received char array
    Serial.println(rxData.organicB[i].atomNum); // print received int
    Serial.println(rxData.organicB[i].MW,4); // print received float
  }
}

void loop()
{
}
