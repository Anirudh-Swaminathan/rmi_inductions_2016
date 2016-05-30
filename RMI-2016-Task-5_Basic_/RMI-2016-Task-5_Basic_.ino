#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int main()
{
  //enable interrupts
  sei();
  DDRB|=0xFF;
  DDRD|=0x00;
  PORTB|=0b00000010;
  
  //enabling external interrupt
  //EIMSK|=(1<<INT0);
  //falling edge interrupt
  //EICRA|=(1<<ISC01);
  
  while(1)
  {
   PORTB^=0b00000011;
   _delay_ms(1000);
  }
  return 0;
}

ISR(INT0_VECT)
{
  unsigned a;
  if(PORTB == 0b00000010) a=2;
  else a = 1;
  
  PORTB = 0b00000000;
  _delay_ms(5000);
  PORTB = 0b00000011;
  _delay_ms(500);
  
  if(a==2) PORTB = 0b00000010;
  else PORTB = 0b00000001;

}
