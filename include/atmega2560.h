#ifndef ATMEGA2560_H
#define ATMEGA2560_H

// TODO figure out why some registers weren't listed with a shifted address
// TODO make own delay function to replace arduino/util-time.h

#define byte unsigned char

/* atmega2560 register addresses
 */
#define PORTG (*(volatile byte *)(0x34))
#define DDRG (*(volatile byte *)(0x33))
#define PORTE (*(volatile byte *)(0x2E))
#define DDRE (*(volatile byte *)(0x2D))
#define PORTB (*(volatile byte *)(0x25))
#define DDRB (*(volatile byte *)(0x24))
#define PORTD (*(volatile byte *)(0x2B))
#define DDRD (*(volatile byte *)(0x2A))
#define PORTC (*(volatile byte *)(0x28))
#define DDRC (*(volatile byte *)(0x27))
#define PORTA (*(volatile byte *)(0x22))
#define DDRA (*(volatile byte *)(0x21))
#define PORTF (*(volatile byte *)(0x31))
#define DDRF (*(volatile byte *)(0x30))

// I need to read about these. They didn't have the second address shifted by 0x20 so I'm
// worried they are different
#define PORTH (*(volatile byte *)(0x102)) // THIS MIGHT NEED TO BE SHIFTED
#define DDRH (*(volatile byte *)(0x101))  // THIS MIGHT NEED TO BE SHIFTED

#define PORTL (*(volatile byte *)(0x10B)) // THIS MIGHT NEED TO BE SHIFTED
#define DDRL (*(volatile byte *)(0x10A))  // THIS MIGHT NEED TO BE SHIFTED

#define PORTJ (*(volatile byte *)(0x105)) // THIS MIGHT NEED TO BE SHIFTED
#define DDRJ (*(volatile byte *)(0x104))  // THIS MIGHT NEED TO BE SHIFTED

#define PORTK (*(volatile byte *)(0x108)) // THIS MIGHT NEED TO BE SHIFTED
#define DDRK (*(volatile byte *)(0x107))  // THIS MIGHT NEED TO BE SHIFTED

#endif // ATMEGA2560_H

/*
There is something weird that I haven't figured out with the registers having two memory
address seperated by 0x20. I don't know what the difference is but I'm using the ones that
work when I change the bits.

"
So the datasheet says:
When using the I/O specific commands IN and OUT, the I/O addresses $00 - $3F must be used.
When addressing I/O regis- ters as data space using LD and ST instructions, $20 must be
added to these addresses. The ATmega640/1280/1281/2560/2561 is a complex microcontroller
with more peripheral units than can be supported within the 64 location reserved in Opcode
for the IN and OUT instructions. For the Extended I/O space from $60 - $1FF in SRAM, only
the ST/STS/STD and LD/LDS/LDD instructions can be used
"

So, this defintely means something. Yes, for sure, there is meaning here that I
understand.

Seriously though, something about extra(?) functionality when addressing the register with
different instructions? pls help
 */
