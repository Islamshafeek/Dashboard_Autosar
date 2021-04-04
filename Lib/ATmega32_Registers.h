#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

typedef union{ 
	struct 	{
 		u8 Bit0 :1;
 		u8 Bit1 :1;
 		u8 Bit2 :1;
 		u8 Bit3 :1;
 		u8 Bit4 :1;
 		u8 Bit5 :1;
 		u8 Bit6 :1;
 		u8 Bit7 :1;
 	}Bits; 
 	u8 u8RegData; 
 }tuniRegType;

#define _SREG			(*( ( volatile tuniRegType *)  0x5F ))
#define _SPH			( ( ( volatile tuniRegType *)  0x5E )-> u8RegData )
#define _SPL			( ( ( volatile tuniRegType *)  0x5D )-> u8RegData )
#define _OCR0			( ( ( volatile tuniRegType *)  0x5C )-> u8RegData )
#define _GICR			(*( ( volatile tuniRegType *)  0x5B ))
#define _GIFR			(*( ( volatile tuniRegType *)  0x5A ))
#define _TIMSK			( ( ( volatile tuniRegType *)  0x59 )-> u8RegData )
#define _TIFR			( ( ( volatile tuniRegType *)  0x58 )-> u8RegData )
#define _SPMCR			( ( ( volatile tuniRegType *)  0x57 )-> u8RegData )
#define _TWCR			( ( ( volatile tuniRegType *)  0x56 )-> u8RegData )
#define _MCUCR			(*( ( volatile tuniRegType *)  0x55 ))
#define _MCUCSR			(*( ( volatile tuniRegType *)  0x54 ))
#define _TCCR0			( ( ( volatile tuniRegType *)  0x53 )-> u8RegData )
#define _TCNT0			( ( ( volatile tuniRegType *)  0x52 )-> u8RegData )
#define _OSCCAL			( ( ( volatile tuniRegType *)  0x51 )-> u8RegData )
#define _OCDR			( ( ( volatile tuniRegType *)  0x51 )-> u8RegData )
#define _SFIOR			( ( ( volatile tuniRegType *)  0x50 )-> u8RegData )
#define _TCCR1A			( ( ( volatile tuniRegType *)  0x4F )-> u8RegData )
#define _TCCR1B			( ( ( volatile tuniRegType *)  0x4E )-> u8RegData )
#define _TCNT1H			( ( ( volatile tuniRegType *)  0x4D )-> u8RegData )
#define _TCNT1L			( ( ( volatile tuniRegType *)  0x4C )-> u8RegData )
#define _OCR1AH			( ( ( volatile tuniRegType *)  0x4B )-> u8RegData )
#define _OCR1AL			( ( ( volatile tuniRegType *)  0x4A )-> u8RegData )
#define _OCR1BH			( ( ( volatile tuniRegType *)  0x49 )-> u8RegData )
#define _OCR1BL			( ( ( volatile tuniRegType *)  0x48 )-> u8RegData )
#define _ICR1H			( ( ( volatile tuniRegType *)  0x47 )-> u8RegData )
#define _ICR1L			( ( ( volatile tuniRegType *)  0x46 )-> u8RegData )
#define _TCCR2			( ( ( volatile tuniRegType *)  0x45 )-> u8RegData )
#define _TCNT2			( ( ( volatile tuniRegType *)  0x44 )-> u8RegData )
#define _OCR2			( ( ( volatile tuniRegType *)  0x43 )-> u8RegData )
#define _ASSR			( ( ( volatile tuniRegType *)  0x42 )-> u8RegData )
#define _WDTCR			( ( ( volatile tuniRegType *)  0x41 )-> u8RegData )
#define _UBRRH			( ( ( volatile tuniRegType *)  0x40 )-> u8RegData )
#define _UCSRC			( ( ( volatile tuniRegType *)  0x40 )-> u8RegData )
#define _EEARH			( ( ( volatile tuniRegType *)  0x3F )-> u8RegData )
#define _EEARL			( ( ( volatile tuniRegType *)  0x3E )-> u8RegData )
#define _EEDR			( ( ( volatile tuniRegType *)  0x3D )-> u8RegData )
#define _EECR			( ( ( volatile tuniRegType *)  0x3C )-> u8RegData )
#define _PORTA			( ( ( volatile tuniRegType *)  0x3B )-> u8RegData )
#define _DDRA			( ( ( volatile tuniRegType *)  0x3A )-> u8RegData )
#define _PINA			( ( ( volatile tuniRegType *)  0x39 )-> u8RegData )
#define _PORTB			( ( ( volatile tuniRegType *)  0x38 )-> u8RegData )
#define _DDRB			( ( ( volatile tuniRegType *)  0x37 )-> u8RegData )
#define _PINB			( ( ( volatile tuniRegType *)  0x36 )-> u8RegData )
#define _PORTC			( ( ( volatile tuniRegType *)  0x35 )-> u8RegData )
#define _DDRC			( ( ( volatile tuniRegType *)  0x34 )-> u8RegData )
#define _PINC			( ( ( volatile tuniRegType *)  0x33 )-> u8RegData )
#define _PORTD			( ( ( volatile tuniRegType *)  0x32 )-> u8RegData )
#define _DDRD			( ( ( volatile tuniRegType *)  0x31 )-> u8RegData )
#define _PIND			( ( ( volatile tuniRegType *)  0x30 )-> u8RegData )
#define _SPDR			( ( ( volatile tuniRegType *)  0x2F )-> u8RegData )
#define _SPSR			( ( ( volatile tuniRegType *)  0x2E )-> u8RegData )
#define _SPCR			( ( ( volatile tuniRegType *)  0x2D )-> u8RegData )
#define _UDR			( ( ( volatile tuniRegType *)  0x2C )-> u8RegData )
#define _UCSRA			( ( ( volatile tuniRegType *)  0x2B )-> u8RegData )
#define _UCSRB			( ( ( volatile tuniRegType *)  0x2A )-> u8RegData )
#define _UBRRL			( ( ( volatile tuniRegType *)  0x29 )-> u8RegData )
#define _ACSR			( ( ( volatile tuniRegType *)  0x28 )-> u8RegData )
#define _ADMUX			( ( ( volatile tuniRegType *)  0x27 )-> u8RegData )
#define _ADCSRA			( ( ( volatile tuniRegType *)  0x26 )-> u8RegData )
#define _ADCH			( ( ( volatile tuniRegType *)  0x25 )-> u8RegData )
#define _ADCL			( ( ( volatile tuniRegType *)  0x24 )-> u8RegData )
#define _TWDR			( ( ( volatile tuniRegType *)  0x23 )-> u8RegData )
#define _TWAR			( ( ( volatile tuniRegType *)  0x22 )-> u8RegData )
#define _TWSR			( ( ( volatile tuniRegType *)  0x21 )-> u8RegData )
#define _TWBR			( ( ( volatile tuniRegType *)  0x20 )-> u8RegData )


#endif /* ATMEGA32_REGISTERS_H_ */
