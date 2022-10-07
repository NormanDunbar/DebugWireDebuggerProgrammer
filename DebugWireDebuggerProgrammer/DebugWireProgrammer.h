//
//  I'm publishing this source code under the MIT License (See: https://opensource.org/licenses/MIT)
//
//    Copyright 2018 Wayne Holder (https://sites.google.com/site/wayneholder/)
//
//    Portions Copyright Copyright (c) 2008-2011 Randall Bohn
//  
//    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
//    documentation files (the "Software"), to deal in the Software without restriction, including without limitation
//    the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
//    to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//  
//    The above copyright notice and this permission notice shall be included in all copies or substantial portions of
//    the Software.
//  
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//    THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
//    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#ifndef DEBUGWIREPROGRAMMER_H
#define DEBUGWIREPROGRAMMER_H


#include <Arduino.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "OnePinSerial.h"
#include <stdint.h>

void setup ();
void selectDebugger();
void powerOn ();
void powerOff ();
void enableSpiPins ();
void disableSpiPins ();
byte transfer (byte val);
byte ispSend (byte c1, byte c2, byte c3, byte c4);
boolean enterProgramMode ();
void getChipId ();
unsigned int identifyDevice ();
void busyWait ();
void printPartFromId (byte sig1, byte sig2);
void sendBreak ();
boolean doBreak ();
byte toHex (char cc);
unsigned int convertHex (byte idx);
byte after (char cc);
byte convertToHex (byte off);
byte readDecimal (byte off);
int getString ();
void printBufToHex8 (int count, boolean trailCrLF);
char toHexDigit (byte nib);
boolean isDecDigit (char cc);
boolean isHexDigit (char cc);
boolean bufMatches (const __FlashStringHelper* ref);
boolean bufStartsWith (const __FlashStringHelper* ref);
void sendCmd (byte* data, byte count);
byte getResponse (int expected);
byte getResponse (byte *data, int expected);
void setTimeoutDelay (unsigned int rate);
unsigned int getWordResponse ();
boolean checkCmdOk ();
boolean checkCmdOk2 ();
byte outHigh (byte add, byte reg);
byte outLow (byte add, byte reg);
byte inHigh  (byte add, byte reg);
byte inLow  (byte add, byte reg);
void writeRegister (byte reg, byte val);
byte readRegister (byte reg);
boolean  readAllRegisters ();
void setClrIOBit (byte addr, byte bit, boolean set);
void writeSRamByte (unsigned int addr, byte val);
byte readSRamByte (unsigned int addr);
boolean readSRamBytes (unsigned int addr, byte len);
byte readEepromByte (unsigned int addr);
void writeEepromByte (unsigned int addr, byte val);
int readFlashPage (char *data, unsigned int len, unsigned int addr);
void printCommErr (byte read, byte expected);
unsigned int getFlashWord (unsigned int addr);
void printCmd (const __FlashStringHelper* cmd);
void printCmd ();
void echoCmd ();
void echoSetCmd (byte len);
unsigned int getPc ();
unsigned int getBp ();
unsigned int getOpcode ();
void setPc (unsigned int pc);
void setBp (unsigned int bp);
void printDebugCommands ();
void setRepeatCmd (const __FlashStringHelper* cmd, unsigned int addr);
void loop ();
void debugger ();
void printMenu ();
void dAsm (unsigned int addr, byte count);
void dAsm2Byte (unsigned int addr, unsigned int opcode);
void print (char *txt);
void print (const __FlashStringHelper* txt);
void println (char *txt);
void println (const __FlashStringHelper* txt);
void println ();
void write (char cc);
void tabTo (byte pos);
void printHex (byte val);
void printHex8 (byte val);
void printHex16 (unsigned int val);
void printHex24 (unsigned long val);
void printDec (byte val);
void printStatus ();
void printSpecialReg (byte sr);
void printRegsUsed ();
void printInst (const __FlashStringHelper* str);
void printDstReg (byte reg);
void printSrcReg (byte reg);
void printDstPair (byte reg);
void printSrcPair (byte reg);
boolean dAsmNoArgs (unsigned int opcode);
boolean dAsmSetClr (unsigned int opcode);
boolean dAsmLogic (unsigned int opcode);
byte dAsmXYZStore (unsigned int opcode);
boolean dAsmXYZLoad (unsigned int opcode);
boolean dAsmLddYZQ (unsigned int opcode);
boolean dAsmStdYZQ (unsigned int opcode);
boolean dAsmRelCallJmp (unsigned int opcode);
boolean dAsmBitOps2  (unsigned int opcode);
boolean dAsmByteImd (unsigned int opcode);
boolean dAsmArith (unsigned int opcode);
boolean dAsmWordImd (unsigned int opcode);
boolean dAsmBitOps (unsigned int opcode);
boolean dAsmBranch (unsigned int opcode);
boolean dAsmMul (unsigned int opcode);


// Functions used by In-System Programmer code
void programmer (void);
void selectProgrammer ();
uint8_t getch ();
void fill (int n);
void empty_reply ();
void breply (uint8_t b);
void avrisp ();


#endif      // DEBUGWIREPROGRAMMER_H
