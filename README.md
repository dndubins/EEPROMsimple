# EEPROMsimple
Local EEPROM library for 25LC1024 chip

This library was created from the example program SPIRamSimple.ino, created by J.B. Gallaher on 07/09/2016. From the comments of this program:

Sample program to use a Serial SRAM chip to expand memory for an Arduino Uno giving access to an additional 128kB of random access memory. The 23LC1024 uses the Serial Peripheral Interface (SPI) to transfer data and commands between the UNO and the memory chip. Note that the functions could be extracted as a beginning for a library for this chip.

This program was adapted to the library SRAMsimple. Then, The library was converted to write to the 25LC1024 EEPROM chip using the algorithm provided in the sketch posed here: https://forum.arduino.cc/index.php?topic=141066.0
The sketch was written by guest user sdarque, and corrected by John Wasser on 06-Jan-13.
   
   Used the following components:
   
   (1) Arduino Uno
   
   (2) Microchip 25LC1024 SPI EEPROM chip

Function Properties:

    void SetMode(byte CSpin);
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
