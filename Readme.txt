Readme file for Arduino EEPROM Library

EEPROM Library is a "librarified" version of the example program "SPIRamSimple.ino" written by J.B. Gallaher on 07/09/2016, written for the 23LC1024. The library was adapted to the 25LC1024 EEPROM chip using the sketch posed here: https://forum.arduino.cc/index.php?topic=141066.0
The sketch was written by guest user sdarque and corrected by John Wasser on 06-Jan-13.

Arduino Uno Memory Expansion Sample Program.
The example sketch is the original sketch re-written to use the library functions. 

The functions available in the library include:

    void SetMode(byte CSpin, char Mode);
    void WriteByte(uint32_t address, byte data_byte);
    byte ReadByte(uint32_t address);
    void WriteByteArray(uint32_t address, byte *data, uint16_t big);
    void ReadByteArray(uint32_t address, byte *data, uint16_t big);
    void WriteInt(uint32_t address, int data);  
    int ReadInt(uint32_t address);
    void WriteIntArray(uint32_t address, int *data, uint16_t big);
    void ReadIntArray(uint32_t address, int *data, uint16_t big);
    void WriteUnsignedInt(uint32_t address, unsigned int data);
    unsigned int ReadUnsignedInt(uint32_t address);
    void WriteUnsignedIntArray(uint32_t address, unsigned int *data, uint16_t big);
    void ReadUnsignedIntArray(uint32_t address, unsigned int *data, uint16_t big);
    void WriteLong(uint32_t address, long data);
    long ReadLong(uint32_t address);
    void WriteLongArray(uint32_t address, long *data, uint16_t big);
    void ReadLongArray(uint32_t address, long *data, uint16_t big);
    void WriteUnsignedLong(uint32_t address, unsigned long data);
    unsigned long ReadUnsignedLong(uint32_t address);
    void WriteUnsignedLongArray(uint32_t address, unsigned long *data, uint16_t big);
    void ReadUnsignedLongArray(uint32_t address, unsigned long *data, uint16_t big);
    void WriteFloat(uint32_t address, float data);
    float ReadFloat(uint32_t address);
    void WriteFloatArray(uint32_t address, float *data, uint16_t big);
    void ReadFloatArray(uint32_t address, float *data, uint16_t big);

To use the library, copy the download to the Library directory.

Wiring the 25LC1024 to the Uno:
   25LC1024 - Uno:
   ---------------
   pin 1 -- D10 (SS)
   pin 2 -- D12 (MISO)
   pin 3, 7, 8 -- +5V
   pin 4 -- GND
   pin 5 -- D11 (MOSI)
   pin 6 -- D13 (SCK)

