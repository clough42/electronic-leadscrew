/*
  Quadrature Encoder Simulator

  Generates a stream of quadrature count signals to simulate an encoder
  for testing and other purposes.
*/

#include "DelayTable.h"

#define ENC_A_PIN 7
#define ENC_B_PIN 8

#define POT_PIN A0

volatile uint8_t *ENC_A_PORT;
uint8_t ENC_A_PIN_MASK;
volatile uint8_t *ENC_B_PORT;
uint8_t ENC_B_PIN_MASK;

volatile int analogReady;
volatile int analogVal;

uint16_t calculatedDelay = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  initADC();
  
  ENC_A_PORT = portOutputRegister(digitalPinToPort(ENC_A_PIN));
  ENC_A_PIN_MASK = digitalPinToBitMask(ENC_A_PIN);

  ENC_B_PORT = portOutputRegister(digitalPinToPort(ENC_B_PIN));
  ENC_B_PIN_MASK = digitalPinToBitMask(ENC_B_PIN);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(ENC_A_PIN, OUTPUT);
  pinMode(ENC_B_PIN, OUTPUT);

  digitalWrite(ENC_A_PIN, 0);
  digitalWrite(ENC_B_PIN, 0);
}

// the loop function runs over and over again forever
void loop() {
  readPot();
  
  *ENC_A_PORT |= ENC_A_PIN_MASK;
  wait();
  *ENC_B_PORT |= ENC_B_PIN_MASK;
  wait();
  *ENC_A_PORT &= ~ENC_A_PIN_MASK;
  wait();
  *ENC_B_PORT &= ~ENC_B_PIN_MASK;
  wait();

}

void wait() {
  delayMicroseconds(calculatedDelay);
}

void readPot() {
  if( analogReady == 1 ) {
    uint16_t raw = analogVal;
    analogReady = 0;
   
    calculatedDelay = pgm_read_byte_near(delayTable + raw) - 1;
  }
}

void initADC() {
   
  // clear ADLAR in ADMUX (0x7C) to right-adjust the result
  // ADCL will contain lower 8 bits, ADCH upper 2 (in last two bits)
  ADMUX &= B11011111;
 
  // Set REFS1..0 in ADMUX (0x7C) to change reference voltage to the
  // proper source (01)
  ADMUX |= B01000000;
 
  // Clear MUX3..0 in ADMUX (0x7C) in preparation for setting the analog
  // input
  ADMUX &= B11110000;
 
  // Set MUX3..0 in ADMUX (0x7C) to read from ADIN0
  // Do not set above 15! You will overrun other parts of ADMUX. A full
  // list of possible inputs is available in Table 24-4 of the ATMega328
  // datasheet
  //ADMUX |= 8;
  ADMUX |= B00000000; // Binary equivalent
 
  // Set ADEN in ADCSRA (0x7A) to enable the ADC.
  // Note, this instruction takes 12 ADC clocks to execute
  ADCSRA |= B10000000;
 
  // Set ADATE in ADCSRA (0x7A) to enable auto-triggering.
  ADCSRA |= B00100000;
 
  // Clear ADTS2..0 in ADCSRB (0x7B) to set trigger mode to free running.
  // This means that as soon as an ADC has finished, the next will be
  // immediately started.
  ADCSRB &= B11111000;
 
  // Set the Prescaler to 128 (16000KHz/128 = 125KHz)
  // Above 200KHz 10-bit results are not reliable.
  ADCSRA |= B00000111;
 
  // Set ADIE in ADCSRA (0x7A) to enable the ADC interrupt.
  // Without this, the internal interrupt will not trigger.
  ADCSRA |= B00001000;
 
  // Enable global interrupts
  // AVR macro included in <avr/interrupts.h>, which the Arduino IDE
  // supplies by default.
  sei();
 
  // Kick off the first ADC
  analogReady = 0;
  // Set ADSC in ADCSRA (0x7A) to start the ADC conversion
  ADCSRA |=B01000000;
}

// Interrupt service routine for the ADC completion
ISR(ADC_vect){

  // Done reading
  analogReady = 1;
 
  // Must read low first
  analogVal = ADCL | (ADCH << 8);
 
  // Not needed because free-running mode is enabled.
  // Set ADSC in ADCSRA (0x7A) to start another ADC conversion
  // ADCSRA |= B01000000;
}
