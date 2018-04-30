/*****************************************************************************
 *
 * Copyright (C) 2018 Atmel Corporation, a wholly owned subsidiary of Microchip Technology Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ****************************************************************************/


#ifndef _AVR_AT90PWM3B_H_INCLUDED
#define _AVR_AT90PWM3B_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "io90pwm3b.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define PINB    _SFR_IO8(0x03)
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x04)
#define DDRB7   7
// Inserted "DDB7" from "DDRB7" due to compatibility
#define DDB7    7
#define DDRB6   6
// Inserted "DDB6" from "DDRB6" due to compatibility
#define DDB6    6
#define DDRB5   5
// Inserted "DDB5" from "DDRB5" due to compatibility
#define DDB5    5
#define DDRB4   4
// Inserted "DDB4" from "DDRB4" due to compatibility
#define DDB4    4
#define DDRB3   3
// Inserted "DDB3" from "DDRB3" due to compatibility
#define DDB3    3
#define DDRB2   2
// Inserted "DDB2" from "DDRB2" due to compatibility
#define DDB2    2
#define DDRB1   1
// Inserted "DDB1" from "DDRB1" due to compatibility
#define DDB1    1
#define DDRB0   0
// Inserted "DDB0" from "DDRB0" due to compatibility
#define DDB0    0

#define PORTB   _SFR_IO8(0x05)
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PINC    _SFR_IO8(0x06)
#define PINC7   7
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x07)
#define DDRC7   7
// Inserted "DDC7" from "DDRC7" due to compatibility
#define DDC7    7
#define DDRC6   6
// Inserted "DDC6" from "DDRC6" due to compatibility
#define DDC6    6
#define DDRC5   5
// Inserted "DDC5" from "DDRC5" due to compatibility
#define DDC5    5
#define DDRC4   4
// Inserted "DDC4" from "DDRC4" due to compatibility
#define DDC4    4
#define DDRC3   3
// Inserted "DDC3" from "DDRC3" due to compatibility
#define DDC3    3
#define DDRC2   2
// Inserted "DDC2" from "DDRC2" due to compatibility
#define DDC2    2
#define DDRC1   1
// Inserted "DDC1" from "DDRC1" due to compatibility
#define DDC1    1
#define DDRC0   0
// Inserted "DDC0" from "DDRC0" due to compatibility
#define DDC0    0

#define PORTC   _SFR_IO8(0x08)
#define PORTC7  7
#define PORTC6  6
#define PORTC5  5
#define PORTC4  4
#define PORTC3  3
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

#define PIND    _SFR_IO8(0x09)
#define PIND7   7
#define PIND6   6
#define PIND5   5
#define PIND4   4
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0

#define DDRD    _SFR_IO8(0x0A)
#define DDRD7   7
// Inserted "DDD7" from "DDRD7" due to compatibility
#define DDD7    7
#define DDRD6   6
// Inserted "DDD6" from "DDRD6" due to compatibility
#define DDD6    6
#define DDRD5   5
// Inserted "DDD5" from "DDRD5" due to compatibility
#define DDD5    5
#define DDRD4   4
// Inserted "DDD4" from "DDRD4" due to compatibility
#define DDD4    4
#define DDRD3   3
// Inserted "DDD3" from "DDRD3" due to compatibility
#define DDD3    3
#define DDRD2   2
// Inserted "DDD2" from "DDRD2" due to compatibility
#define DDD2    2
#define DDRD1   1
// Inserted "DDD1" from "DDRD1" due to compatibility
#define DDD1    1
#define DDRD0   0
// Inserted "DDD0" from "DDRD0" due to compatibility
#define DDD0    0

#define PORTD   _SFR_IO8(0x0B)
#define PORTD7  7
#define PORTD6  6
#define PORTD5  5
#define PORTD4  4
#define PORTD3  3
#define PORTD2  2
#define PORTD1  1
#define PORTD0  0

#define PINE    _SFR_IO8(0x0C)
#define PINE2   2
#define PINE1   1
#define PINE0   0

#define DDRE    _SFR_IO8(0x0D)
#define DDRE2   2
// Inserted "DDE2" from "DDRE2" due to compatibility
#define DDE2    2
#define DDRE1   1
// Inserted "DDE1" from "DDRE1" due to compatibility
#define DDE1    1
#define DDRE0   0
// Inserted "DDE0" from "DDRE0" due to compatibility
#define DDE0    0

#define PORTE   _SFR_IO8(0x0E)
#define PORTE2  2
#define PORTE1  1
#define PORTE0  0

/* Reserved [0x0F..0x14] */

#define TIFR0   _SFR_IO8(0x15)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2

#define TIFR1   _SFR_IO8(0x16)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

/* Reserved [0x17..0x18] */

#define GPIOR1  _SFR_IO8(0x19)
#define GPIOR10 0
#define GPIOR11 1
#define GPIOR12 2
#define GPIOR13 3
#define GPIOR14 4
#define GPIOR15 5
#define GPIOR16 6
#define GPIOR17 7

#define GPIOR2  _SFR_IO8(0x1A)
#define GPIOR20 0
#define GPIOR21 1
#define GPIOR22 2
#define GPIOR23 3
#define GPIOR24 4
#define GPIOR25 5
#define GPIOR26 6
#define GPIOR27 7

#define GPIOR3  _SFR_IO8(0x1B)
#define GPIOR30 0
#define GPIOR31 1
#define GPIOR32 2
#define GPIOR33 3
#define GPIOR34 4
#define GPIOR35 5
#define GPIOR36 6
#define GPIOR37 7

#define EIFR    _SFR_IO8(0x1C)
#define INTF0   0
#define INTF1   1
#define INTF2   2
#define INTF3   3

#define EIMSK   _SFR_IO8(0x1D)
#define INT0    0
#define INT1    1
#define INT2    2
#define INT3    3

#define GPIOR0  _SFR_IO8(0x1E)
#define GPIOR00 0
#define GPIOR01 1
#define GPIOR02 2
#define GPIOR03 3
#define GPIOR04 4
#define GPIOR05 5
#define GPIOR06 6
#define GPIOR07 7

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

#define EEDR    _SFR_IO8(0x20)
#define EEDR0   0
#define EEDR1   1
#define EEDR2   2
#define EEDR3   3
#define EEDR4   4
#define EEDR5   5
#define EEDR6   6
#define EEDR7   7

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEAR0   0
#define EEAR1   1
#define EEAR2   2
#define EEAR3   3
#define EEAR4   4
#define EEAR5   5
#define EEAR6   6
#define EEAR7   7
#define EEARH   _SFR_IO8(0x22)
#define EEAR8   0
#define EEAR9   1
#define EEAR10  2
#define EEAR11  3

#define GTCCR   _SFR_IO8(0x23)
#define PSR10   0
#define ICPSEL1 6
#define TSM     7
#define PSRSYNC 0

#define TCCR0A  _SFR_IO8(0x24)
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

#define TCCR0B  _SFR_IO8(0x25)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define FOC0B   6
#define FOC0A   7

#define TCNT0   _SFR_IO8(0x26)
#define TCNT00  0
#define TCNT01  1
#define TCNT02  2
#define TCNT03  3
#define TCNT04  4
#define TCNT05  5
#define TCNT06  6
#define TCNT07  7

#define OCR0A   _SFR_IO8(0x27)
#define OCR0A0  0
#define OCR0A1  1
#define OCR0A2  2
#define OCR0A3  3
#define OCR0A4  4
#define OCR0A5  5
#define OCR0A6  6
#define OCR0A7  7

#define OCR0B   _SFR_IO8(0x28)
#define OCR0B0  0
#define OCR0B1  1
#define OCR0B2  2
#define OCR0B3  3
#define OCR0B4  4
#define OCR0B5  5
#define OCR0B6  6
#define OCR0B7  7

#define PLLCSR  _SFR_IO8(0x29)
#define PLOCK   0
#define PLLE    1
#define PLLF    2

/* Reserved [0x2A..0x2B] */

#define SPCR    _SFR_IO8(0x2C)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR    _SFR_IO8(0x2D)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPDR    _SFR_IO8(0x2E)
#define SPD0    0
#define SPD1    1
#define SPD2    2
#define SPD3    3
#define SPD4    4
#define SPD5    5
#define SPD6    6
#define SPD7    7

/* Reserved [0x2F] */

#define ACSR    _SFR_IO8(0x30)
#define AC0O    0
#define AC1O    1
#define AC2O    2
#define AC0IF   4
#define AC1IF   5
#define AC2IF   6
#define ACCKDIV 7

/* Reserved [0x31..0x32] */

#define SMCR    _SFR_IO8(0x33)
#define SE      0
#define SM0     1
#define SM1     2
#define SM2     3

#define MCUSR   _SFR_IO8(0x34)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

#define MCUCR   _SFR_IO8(0x35)
#define IVCE    0
#define IVSEL   1
#define PUD     4
#define SPIPS   7

/* Reserved [0x36] */

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define RWWSRE  4
#define RWWSB   6
#define SPMIE   7

/* Reserved [0x38..0x3C] */

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define WDTCSR  _SFR_MEM8(0x60)
#define WDE     3
#define WDCE    4
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

#define CLKPR   _SFR_MEM8(0x61)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3
#define CLKPCE  7

/* Reserved [0x62..0x63] */

#define PRR     _SFR_MEM8(0x64)
#define PRADC   0
#define PRUSART0 1
#define PRSPI   2
#define PRTIM0  3
#define PRTIM1  4
#define PRPSC0  5
#define PRPSC1  6
#define PRPSC2  7

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRPSC0)|(1<<PRPSC1)|(1<<PRPSC2))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSART0
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRPSC0
#define __AVR_HAVE_PRR_PRPSC1
#define __AVR_HAVE_PRR_PRPSC2

/* Reserved [0x65] */

#define OSCCAL  _SFR_MEM8(0x66)
#define OSCCAL0 0
#define OSCCAL1 1
#define OSCCAL2 2
#define OSCCAL3 3
#define OSCCAL4 4
#define OSCCAL5 5
#define OSCCAL6 6
#define OSCCAL7 7

/* Reserved [0x67..0x68] */

#define EICRA   _SFR_MEM8(0x69)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC20   4
#define ISC21   5
#define ISC30   6
#define ISC31   7

/* Reserved [0x6A..0x6D] */

#define TIMSK0  _SFR_MEM8(0x6E)
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2

#define TIMSK1  _SFR_MEM8(0x6F)
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define ICIE1   5

/* Reserved [0x70..0x75] */

#define AMP0CSR _SFR_MEM8(0x76)
#define AMP0TS0 0
#define AMP0TS1 1
#define AMP0G0  4
#define AMP0G1  5
#define AMP0IS  6
#define AMP0EN  7

#define AMP1CSR _SFR_MEM8(0x77)
#define AMP1TS0 0
#define AMP1TS1 1
#define AMP1G0  4
#define AMP1G1  5
#define AMP1IS  6
#define AMP1EN  7

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_MEM16(0x78)
#endif
#define ADCW    _SFR_MEM16(0x78)

#define ADCL    _SFR_MEM8(0x78)
#define ADC0    0
#define ADC1    1
#define ADC2    2
#define ADC3    3
#define ADC4    4
#define ADC5    5
#define ADC6    6
#define ADC7    7
#define ADCH    _SFR_MEM8(0x79)
#define ADC8    0
#define ADC9    1
#define ADC10   2
#define ADC11   3
#define ADC12   4
#define ADC13   5
#define ADC14   6
#define ADC15   7

#define ADCSRA  _SFR_MEM8(0x7A)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADCSRB  _SFR_MEM8(0x7B)
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADTS3   3
#define ADHSM   7

#define ADMUX   _SFR_MEM8(0x7C)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define ADLAR   5
#define REFS0   6
#define REFS1   7

/* Reserved [0x7D] */

#define DIDR0   _SFR_MEM8(0x7E)
#define ADC0D   0
#define ADC1D   1
#define ADC2D   2
#define ADC3D   3
#define ADC4D   4
#define ADC5D   5
#define ADC6D   6
#define ADC7D   7

#define DIDR1   _SFR_MEM8(0x7F)
#define ADC8D   0
#define ADC9D   1
#define ADC10D  2
#define AMP0ND  3
#define AMP0PD  4
#define ACMP0D  5

#define TCCR1A  _SFR_MEM8(0x80)
#define WGM10   0
#define WGM11   1
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR1B  _SFR_MEM8(0x81)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCCR1C  _SFR_MEM8(0x82)
#define FOC1B   6
#define FOC1A   7

/* Reserved [0x83] */

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_MEM16(0x84)

#define TCNT1L  _SFR_MEM8(0x84)
#define TCNT10  0
#define TCNT11  1
#define TCNT12  2
#define TCNT13  3
#define TCNT14  4
#define TCNT15  5
#define TCNT16  6
#define TCNT17  7
#define TCNT1H  _SFR_MEM8(0x85)
#define TCNT18  0
#define TCNT19  1
#define TCNT110 2
#define TCNT111 3
#define TCNT112 4
#define TCNT113 5
#define TCNT114 6
#define TCNT115 7

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_MEM16(0x86)

#define ICR1L   _SFR_MEM8(0x86)
#define ICR10   0
#define ICR11   1
#define ICR12   2
#define ICR13   3
#define ICR14   4
#define ICR15   5
#define ICR16   6
#define ICR17   7
#define ICR1H   _SFR_MEM8(0x87)
#define ICR18   0
#define ICR19   1
#define ICR110  2
#define ICR111  3
#define ICR112  4
#define ICR113  5
#define ICR114  6
#define ICR115  7

/* Combine OCR1AL and OCR1AH */
#define OCR1A   _SFR_MEM16(0x88)

#define OCR1AL  _SFR_MEM8(0x88)
#define OCR1A0  0
#define OCR1A1  1
#define OCR1A2  2
#define OCR1A3  3
#define OCR1A4  4
#define OCR1A5  5
#define OCR1A6  6
#define OCR1A7  7
#define OCR1AH  _SFR_MEM8(0x89)
#define OCR1A8  0
#define OCR1A9  1
#define OCR1A10 2
#define OCR1A11 3
#define OCR1A12 4
#define OCR1A13 5
#define OCR1A14 6
#define OCR1A15 7

/* Combine OCR1BL and OCR1BH */
#define OCR1B   _SFR_MEM16(0x8A)

#define OCR1BL  _SFR_MEM8(0x8A)
#define OCR1B0  0
#define OCR1B1  1
#define OCR1B2  2
#define OCR1B3  3
#define OCR1B4  4
#define OCR1B5  5
#define OCR1B6  6
#define OCR1B7  7
#define OCR1BH  _SFR_MEM8(0x8B)
#define OCR1B8  0
#define OCR1B9  1
#define OCR1B10 2
#define OCR1B11 3
#define OCR1B12 4
#define OCR1B13 5
#define OCR1B14 6
#define OCR1B15 7

/* Reserved [0x8C..0x9F] */

#define PIFR0   _SFR_MEM8(0xA0)
#define PEOP0   0
#define PRN00   1
#define PRN01   2
#define PEV0A   3
#define PEV0B   4
#define PSEI0   5
#define POAC0A  6
#define POAC0B  7

#define PIM0    _SFR_MEM8(0xA1)
#define PEOPE0  0
#define PEVE0A  3
#define PEVE0B  4
#define PSEIE0  5

#define PIFR1   _SFR_MEM8(0xA2)
#define PEOP1   0
#define PRN10   1
#define PRN11   2
#define PEV1A   3
#define PEV1B   4
#define PSEI1   5
#define POAC1A  6
#define POAC1B  7

#define PIM1    _SFR_MEM8(0xA3)
#define PEOPE1  0
#define PEVE1A  3
#define PEVE1B  4
#define PSEIE1  5

#define PIFR2   _SFR_MEM8(0xA4)
#define PEOP2   0
#define PRN20   1
#define PRN21   2
#define PEV2A   3
#define PEV2B   4
#define PSEI2   5
#define POAC2A  6
#define POAC2B  7

#define PIM2    _SFR_MEM8(0xA5)
#define PEOPE2  0
#define PEVE2A  3
#define PEVE2B  4
#define PSEIE2  5

/* Reserved [0xA6..0xA9] */

#define DACON   _SFR_MEM8(0xAA)
#define DAEN    0
#define DAOE    1
#define DALA    2
#define DATS0   4
#define DATS1   5
#define DATS2   6
#define DAATE   7

/* Combine DACL and DACH */
#define DAC     _SFR_MEM16(0xAB)

#define DACL    _SFR_MEM8(0xAB)
#define DAC0    0
#define DAC1    1
#define DAC2    2
#define DAC3    3
#define DAC4    4
#define DAC5    5
#define DAC6    6
#define DAC7    7
#define DACH    _SFR_MEM8(0xAC)
#define DAC8    0
#define DAC9    1
#define DAC10   2
#define DAC11   3
#define DAC12   4
#define DAC13   5
#define DAC14   6
#define DAC15   7

#define AC0CON  _SFR_MEM8(0xAD)
#define AC0M0   0
#define AC0M1   1
#define AC0M2   2
#define AC0IS0  4
#define AC0IS1  5
#define AC0IE   6
#define AC0EN   7

#define AC1CON  _SFR_MEM8(0xAE)
#define AC1M0   0
#define AC1M1   1
#define AC1M2   2
#define AC1ICE  3
#define AC1IS0  4
#define AC1IS1  5
#define AC1IE   6
#define AC1EN   7

#define AC2CON  _SFR_MEM8(0xAF)
#define AC2M0   0
#define AC2M1   1
#define AC2M2   2
#define AC2IS0  4
#define AC2IS1  5
#define AC2IE   6
#define AC2EN   7

/* Reserved [0xB0..0xBF] */

#define UCSRA   _SFR_MEM8(0xC0)
#define MPCM    0
#define U2X     1
#define UPE     2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UCSRB   _SFR_MEM8(0xC1)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRC   _SFR_MEM8(0xC2)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL0  6

/* Reserved [0xC3] */

/* Combine UBRRL and UBRRH */
#define UBRR    _SFR_MEM16(0xC4)

#define UBRRL   _SFR_MEM8(0xC4)
#define UBRR0   0
#define UBRR1   1
#define UBRR2   2
#define UBRR3   3
#define UBRR4   4
#define UBRR5   5
#define UBRR6   6
#define UBRR7   7
#define UBRRH   _SFR_MEM8(0xC5)
#define UBRR8   0
#define UBRR9   1
#define UBRR10  2
#define UBRR11  3

#define UDR     _SFR_MEM8(0xC6)
#define UDR0    0
#define UDR1    1
#define UDR2    2
#define UDR3    3
#define UDR4    4
#define UDR5    5
#define UDR6    6
#define UDR7    7

/* Reserved [0xC7] */

#define EUCSRA  _SFR_MEM8(0xC8)
#define URxS0   0
#define URxS1   1
#define URxS2   2
#define URxS3   3
#define UTxS0   4
#define UTxS1   5
#define UTxS2   6
#define UTxS3   7

#define EUCSRB  _SFR_MEM8(0xC9)
#define BODR    0
#define EMCH    1
#define EUSBS   3
#define EUSART  4

#define EUCSRC  _SFR_MEM8(0xCA)
#define STP0    0
#define STP1    1
#define F1617   2
#define FEM     3

/* Reserved [0xCB] */

/* Combine MUBRRL and MUBRRH */
#define MUBRR   _SFR_MEM16(0xCC)

#define MUBRRL  _SFR_MEM8(0xCC)
#define MUBRR0  0
#define MUBRR1  1
#define MUBRR2  2
#define MUBRR3  3
#define MUBRR4  4
#define MUBRR5  5
#define MUBRR6  6
#define MUBRR7  7
#define MUBRRH  _SFR_MEM8(0xCD)
#define MUBRR8  0
#define MUBRR9  1
#define MUBRR10 2
#define MUBRR11 3
#define MUBRR12 4
#define MUBRR13 5
#define MUBRR14 6
#define MUBRR15 7

#define EUDR    _SFR_MEM8(0xCE)
#define EUDR0   0
#define EUDR1   1
#define EUDR2   2
#define EUDR3   3
#define EUDR4   4
#define EUDR5   5
#define EUDR6   6
#define EUDR7   7

/* Reserved [0xCF] */

#define PSOC0   _SFR_MEM8(0xD0)
#define POEN0A  0
#define POEN0B  2
#define PSYNC00 4
#define PSYNC01 5

/* Reserved [0xD1] */

/* Combine OCR0SAL and OCR0SAH */
#define OCR0SA  _SFR_MEM16(0xD2)

#define OCR0SAL _SFR_MEM8(0xD2)
#define OCR0SA0 0
#define OCR0SA1 1
#define OCR0SA2 2
#define OCR0SA3 3
#define OCR0SA4 4
#define OCR0SA5 5
#define OCR0SA6 6
#define OCR0SA7 7
#define OCR0SAH _SFR_MEM8(0xD3)
#define OCR0SA8 0
#define OCR0SA9 1
#define OCR0SA10 2
#define OCR0SA11 3

/* Combine OCR0RAL and OCR0RAH */
#define OCR0RA  _SFR_MEM16(0xD4)

#define OCR0RAL _SFR_MEM8(0xD4)
#define OCR0RA0 0
#define OCR0RA1 1
#define OCR0RA2 2
#define OCR0RA3 3
#define OCR0RA4 4
#define OCR0RA5 5
#define OCR0RA6 6
#define OCR0RA7 7
#define OCR0RAH _SFR_MEM8(0xD5)
#define OCR0RA8 0
#define OCR0RA9 1
#define OCR0RA10 2
#define OCR0RA11 3

/* Combine OCR0SBL and OCR0SBH */
#define OCR0SB  _SFR_MEM16(0xD6)

#define OCR0SBL _SFR_MEM8(0xD6)
#define OCR0SB0 0
#define OCR0SB1 1
#define OCR0SB2 2
#define OCR0SB3 3
#define OCR0SB4 4
#define OCR0SB5 5
#define OCR0SB6 6
#define OCR0SB7 7
#define OCR0SBH _SFR_MEM8(0xD7)
#define OCR0SB8 0
#define OCR0SB9 1
#define OCR0SB10 2
#define OCR0SB11 3

/* Combine OCR0RBL and OCR0RBH */
#define OCR0RB  _SFR_MEM16(0xD8)

#define OCR0RBL _SFR_MEM8(0xD8)
#define OCR0RB0 0
#define OCR0RB1 1
#define OCR0RB2 2
#define OCR0RB3 3
#define OCR0RB4 4
#define OCR0RB5 5
#define OCR0RB6 6
#define OCR0RB7 7
#define OCR0RBH _SFR_MEM8(0xD9)
#define OCR0RB8 0
#define OCR0RB9 1
#define OCR0RB10 2
#define OCR0RB11 3
#define OCR0RB12 4
#define OCR0RB13 5
#define OCR0RB14 6
#define OCR0RB15 7

#define PCNF0   _SFR_MEM8(0xDA)
#define PCLKSEL0 1
#define POP0    2
#define PMODE00 3
#define PMODE01 4
#define PLOCK0  5
#define PALOCK0 6
#define PFIFTY0 7

#define PCTL0   _SFR_MEM8(0xDB)
#define PRUN0   0
#define PCCYC0  1
#define PARUN0  2
#define PAOC0A  3
#define PAOC0B  4
#define PBFM0   5
#define PPRE00  6
#define PPRE01  7

#define PFRC0A  _SFR_MEM8(0xDC)
#define PRFM0A0 0
#define PRFM0A1 1
#define PRFM0A2 2
#define PRFM0A3 3
#define PFLTE0A 4
#define PELEV0A 5
#define PISEL0A 6
#define PCAE0A  7

#define PFRC0B  _SFR_MEM8(0xDD)
#define PRFM0B0 0
#define PRFM0B1 1
#define PRFM0B2 2
#define PRFM0B3 3
#define PFLTE0B 4
#define PELEV0B 5
#define PISEL0B 6
#define PCAE0B  7

/* Combine PICR0L and PICR0H */
#define PICR0   _SFR_MEM16(0xDE)

#define PICR0L  _SFR_MEM8(0xDE)
#define PICR00  0
#define PICR01  1
#define PICR02  2
#define PICR03  3
#define PICR04  4
#define PICR05  5
#define PICR06  6
#define PICR07  7
#define PICR0H  _SFR_MEM8(0xDF)
#define PICR08  0
#define PICR09  1
#define PICR010 2
#define PICR011 3
#define PCST0   7

#define PSOC1   _SFR_MEM8(0xE0)
#define POEN1A  0
#define POEN1B  2
#define PSYNC1_0 4
#define PSYNC1_1 5

/* Reserved [0xE1] */

/* Combine OCR1SAL and OCR1SAH */
#define OCR1SA  _SFR_MEM16(0xE2)

#define OCR1SAL _SFR_MEM8(0xE2)
#define OCR1SA0 0
#define OCR1SA1 1
#define OCR1SA2 2
#define OCR1SA3 3
#define OCR1SA4 4
#define OCR1SA5 5
#define OCR1SA6 6
#define OCR1SA7 7
#define OCR1SAH _SFR_MEM8(0xE3)
#define OCR1SA8 0
#define OCR1SA9 1
#define OCR1SA10 2
#define OCR1SA11 3

/* Combine OCR1RAL and OCR1RAH */
#define OCR1RA  _SFR_MEM16(0xE4)

#define OCR1RAL _SFR_MEM8(0xE4)
#define OCR1RA0 0
#define OCR1RA1 1
#define OCR1RA2 2
#define OCR1RA3 3
#define OCR1RA4 4
#define OCR1RA5 5
#define OCR1RA6 6
#define OCR1RA7 7
#define OCR1RAH _SFR_MEM8(0xE5)
#define OCR1RA8 0
#define OCR1RA9 1
#define OCR1RA10 2
#define OCR1RA11 3

/* Combine OCR1SBL and OCR1SBH */
#define OCR1SB  _SFR_MEM16(0xE6)

#define OCR1SBL _SFR_MEM8(0xE6)
#define OCR1SB0 0
#define OCR1SB1 1
#define OCR1SB2 2
#define OCR1SB3 3
#define OCR1SB4 4
#define OCR1SB5 5
#define OCR1SB6 6
#define OCR1SB7 7
#define OCR1SBH _SFR_MEM8(0xE7)
#define OCR1SB8 0
#define OCR1SB9 1
#define OCR1SB10 2
#define OCR1SB11 3

/* Combine OCR1RBL and OCR1RBH */
#define OCR1RB  _SFR_MEM16(0xE8)

#define OCR1RBL _SFR_MEM8(0xE8)
#define OCR1RB0 0
#define OCR1RB1 1
#define OCR1RB2 2
#define OCR1RB3 3
#define OCR1RB4 4
#define OCR1RB5 5
#define OCR1RB6 6
#define OCR1RB7 7
#define OCR1RBH _SFR_MEM8(0xE9)
#define OCR1RB8 0
#define OCR1RB9 1
#define OCR1RB10 2
#define OCR1RB11 3
#define OCR1RB12 4
#define OCR1RB13 5
#define OCR1RB14 6
#define OCR1RB15 7

#define PCNF1   _SFR_MEM8(0xEA)
#define PCLKSEL1 1
#define POP1    2
#define PMODE10 3
#define PMODE11 4
#define PLOCK1  5
#define PALOCK1 6
#define PFIFTY1 7

#define PCTL1   _SFR_MEM8(0xEB)
#define PRUN1   0
#define PCCYC1  1
#define PARUN1  2
#define PAOC1A  3
#define PAOC1B  4
#define PBFM1   5
#define PPRE10  6
#define PPRE11  7

#define PFRC1A  _SFR_MEM8(0xEC)
#define PRFM1A0 0
#define PRFM1A1 1
#define PRFM1A2 2
#define PRFM1A3 3
#define PFLTE1A 4
#define PELEV1A 5
#define PISEL1A 6
#define PCAE1A  7

#define PFRC1B  _SFR_MEM8(0xED)
#define PRFM1B0 0
#define PRFM1B1 1
#define PRFM1B2 2
#define PRFM1B3 3
#define PFLTE1B 4
#define PELEV1B 5
#define PISEL1B 6
#define PCAE1B  7

/* Combine PICR1L and PICR1H */
#define PICR1   _SFR_MEM16(0xEE)

#define PICR1L  _SFR_MEM8(0xEE)
#define PICR10  0
#define PICR11  1
#define PICR12  2
#define PICR13  3
#define PICR14  4
#define PICR15  5
#define PICR16  6
#define PICR17  7
#define PICR1H  _SFR_MEM8(0xEF)
#define PICR18  0
#define PICR19  1
#define PICR110 2
#define PICR111 3
#define PCST1   7

#define PSOC2   _SFR_MEM8(0xF0)
#define POEN2A  0
#define POEN2C  1
#define POEN2B  2
#define POEN2D  3
#define PSYNC2_0 4
#define PSYNC2_1 5
#define POS22   6
#define POS23   7

#define POM2    _SFR_MEM8(0xF1)
#define POMV2A0 0
#define POMV2A1 1
#define POMV2A2 2
#define POMV2A3 3
#define POMV2B0 4
#define POMV2B1 5
#define POMV2B2 6
#define POMV2B3 7

/* Combine OCR2SAL and OCR2SAH */
#define OCR2SA  _SFR_MEM16(0xF2)

#define OCR2SAL _SFR_MEM8(0xF2)
#define OCR2SA0 0
#define OCR2SA1 1
#define OCR2SA2 2
#define OCR2SA3 3
#define OCR2SA4 4
#define OCR2SA5 5
#define OCR2SA6 6
#define OCR2SA7 7
#define OCR2SAH _SFR_MEM8(0xF3)
#define OCR2SA8 0
#define OCR2SA9 1
#define OCR2SA10 2
#define OCR2SA11 3

/* Combine OCR2RAL and OCR2RAH */
#define OCR2RA  _SFR_MEM16(0xF4)

#define OCR2RAL _SFR_MEM8(0xF4)
#define OCR2RA0 0
#define OCR2RA1 1
#define OCR2RA2 2
#define OCR2RA3 3
#define OCR2RA4 4
#define OCR2RA5 5
#define OCR2RA6 6
#define OCR2RA7 7
#define OCR2RAH _SFR_MEM8(0xF5)
#define OCR2RA8 0
#define OCR2RA9 1
#define OCR2RA10 2
#define OCR2RA11 3

/* Combine OCR2SBL and OCR2SBH */
#define OCR2SB  _SFR_MEM16(0xF6)

#define OCR2SBL _SFR_MEM8(0xF6)
#define OCR2SB0 0
#define OCR2SB1 1
#define OCR2SB2 2
#define OCR2SB3 3
#define OCR2SB4 4
#define OCR2SB5 5
#define OCR2SB6 6
#define OCR2SB7 7
#define OCR2SBH _SFR_MEM8(0xF7)
#define OCR2SB8 0
#define OCR2SB9 1
#define OCR2SB10 2
#define OCR2SB11 3

/* Combine OCR2RBL and OCR2RBH */
#define OCR2RB  _SFR_MEM16(0xF8)

#define OCR2RBL _SFR_MEM8(0xF8)
#define OCR2RB0 0
#define OCR2RB1 1
#define OCR2RB2 2
#define OCR2RB3 3
#define OCR2RB4 4
#define OCR2RB5 5
#define OCR2RB6 6
#define OCR2RB7 7
#define OCR2RBH _SFR_MEM8(0xF9)
#define OCR2RB8 0
#define OCR2RB9 1
#define OCR2RB10 2
#define OCR2RB11 3
#define OCR2RB12 4
#define OCR2RB13 5
#define OCR2RB14 6
#define OCR2RB15 7

#define PCNF2   _SFR_MEM8(0xFA)
#define POME2   0
#define PCLKSEL2 1
#define POP2    2
#define PMODE20 3
#define PMODE21 4
#define PLOCK2  5
#define PALOCK2 6
#define PFIFTY2 7

#define PCTL2   _SFR_MEM8(0xFB)
#define PRUN2   0
#define PCCYC2  1
#define PARUN2  2
#define PAOC2A  3
#define PAOC2B  4
#define PBFM2   5
#define PPRE20  6
#define PPRE21  7

#define PFRC2A  _SFR_MEM8(0xFC)
#define PRFM2A0 0
#define PRFM2A1 1
#define PRFM2A2 2
#define PRFM2A3 3
#define PFLTE2A 4
#define PELEV2A 5
#define PISEL2A 6
#define PCAE2A  7

#define PFRC2B  _SFR_MEM8(0xFD)
#define PRFM2B0 0
#define PRFM2B1 1
#define PRFM2B2 2
#define PRFM2B3 3
#define PFLTE2B 4
#define PELEV2B 5
#define PISEL2B 6
#define PCAE2B  7

/* Combine PICR2L and PICR2H */
#define PICR2   _SFR_MEM16(0xFE)

#define PICR2L  _SFR_MEM8(0xFE)
#define PICR20  0
#define PICR21  1
#define PICR22  2
#define PICR23  3
#define PICR24  4
#define PICR25  5
#define PICR26  6
#define PICR27  7
#define PICR2H  _SFR_MEM8(0xFF)
#define PICR28  0
#define PICR29  1
#define PICR210 2
#define PICR211 3
#define PCST2   7



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* PSC2 Capture Event */
#define PSC2_CAPT_vect            _VECTOR(1)
#define PSC2_CAPT_vect_num        1

/* PSC2 End Cycle */
#define PSC2_EC_vect            _VECTOR(2)
#define PSC2_EC_vect_num        2

/* PSC1 Capture Event */
#define PSC1_CAPT_vect            _VECTOR(3)
#define PSC1_CAPT_vect_num        3

/* PSC1 End Cycle */
#define PSC1_EC_vect            _VECTOR(4)
#define PSC1_EC_vect_num        4

/* PSC0 Capture Event */
#define PSC0_CAPT_vect            _VECTOR(5)
#define PSC0_CAPT_vect_num        5

/* PSC0 End Cycle */
#define PSC0_EC_vect            _VECTOR(6)
#define PSC0_EC_vect_num        6

/* Analog Comparator 0 */
#define ANALOG_COMP_0_vect            _VECTOR(7)
#define ANALOG_COMP_0_vect_num        7

/* Analog Comparator 1 */
#define ANALOG_COMP_1_vect            _VECTOR(8)
#define ANALOG_COMP_1_vect_num        8

/* Analog Comparator 2 */
#define ANALOG_COMP_2_vect            _VECTOR(9)
#define ANALOG_COMP_2_vect_num        9

/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(10)
#define INT0_vect_num        10

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(11)
#define TIMER1_CAPT_vect_num        11

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(12)
#define TIMER1_COMPA_vect_num        12

/* Timer/Counter Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(13)
#define TIMER1_COMPB_vect_num        13

/*  */
#define RESERVED15_vect            _VECTOR(14)
#define RESERVED15_vect_num        14

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(15)
#define TIMER1_OVF_vect_num        15

/* Timer/Counter0 Compare Match A */
#define TIMER0_COMPA_vect            _VECTOR(16)
#define TIMER0_COMPA_vect_num        16

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(17)
#define TIMER0_OVF_vect_num        17

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(18)
#define ADC_vect_num        18

/* External Interrupt Request 1 */
#define INT1_vect            _VECTOR(19)
#define INT1_vect_num        19

/* SPI Serial Transfer Complete */
#define SPI_STC_vect            _VECTOR(20)
#define SPI_STC_vect_num        20

/* USART, Rx Complete */
#define USART_RX_vect            _VECTOR(21)
#define USART_RX_vect_num        21

/* USART Data Register Empty */
#define USART_UDRE_vect            _VECTOR(22)
#define USART_UDRE_vect_num        22

/* USART, Tx Complete */
#define USART_TX_vect            _VECTOR(23)
#define USART_TX_vect_num        23

/* External Interrupt Request 2 */
#define INT2_vect            _VECTOR(24)
#define INT2_vect_num        24

/* Watchdog Timeout Interrupt */
#define WDT_vect            _VECTOR(25)
#define WDT_vect_num        25

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(26)
#define EE_READY_vect_num        26

/* Timer Counter 0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(27)
#define TIMER0_COMPB_vect_num        27

/* External Interrupt Request 3 */
#define INT3_vect            _VECTOR(28)
#define INT3_vect_num        28

/*  */
#define RESERVED30_vect            _VECTOR(29)
#define RESERVED30_vect_num        29

/*  */
#define RESERVED31_vect            _VECTOR(30)
#define RESERVED31_vect_num        30

/* Store Program Memory Read */
#define SPM_READY_vect            _VECTOR(31)
#define SPM_READY_vect_num        31

#define _VECTORS_SIZE 64


/* Constants */

#define SPM_PAGESIZE 64
#define FLASHSTART   0x0000
#define FLASHEND     0x1FFF
#define RAMSTART     0x0100
#define RAMSIZE      512
#define RAMEND       0x02FF
#define E2START     0
#define E2SIZE      512
#define E2PAGESIZE  4
#define E2END       0x01FF
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_SUT_CKSEL0  (unsigned char)~_BV(0)
#define FUSE_SUT_CKSEL1  (unsigned char)~_BV(1)
#define FUSE_SUT_CKSEL2  (unsigned char)~_BV(2)
#define FUSE_SUT_CKSEL3  (unsigned char)~_BV(3)
#define FUSE_SUT_CKSEL4  (unsigned char)~_BV(4)
#define FUSE_SUT_CKSEL5  (unsigned char)~_BV(5)
#define FUSE_CKOUT       (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_SUT_CKSEL0 & FUSE_SUT_CKSEL2 & FUSE_SUT_CKSEL3 & FUSE_SUT_CKSEL4 & FUSE_CKDIV8)


/* High Fuse Byte */
#define FUSE_BODLEVEL0   (unsigned char)~_BV(0)
#define FUSE_BODLEVEL1   (unsigned char)~_BV(1)
#define FUSE_BODLEVEL2   (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_WDTON       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_DWEN        (unsigned char)~_BV(6)
#define FUSE_RSTDISBL    (unsigned char)~_BV(7)
#define HFUSE_DEFAULT    (FUSE_SPIEN)


/* Extended Fuse Byte */
#define FUSE_BOOTRST     (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
#define FUSE_PSCRV       (unsigned char)~_BV(4)
#define FUSE_PSC0RB      (unsigned char)~_BV(5)
#define FUSE_PSC1RB      (unsigned char)~_BV(6)
#define FUSE_PSC2RB      (unsigned char)~_BV(7)
#define EFUSE_DEFAULT    (FUSE_BOOTSZ0 & FUSE_BOOTSZ1)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x83




#endif /* #ifdef _AVR_AT90PWM3B_H_INCLUDED */

