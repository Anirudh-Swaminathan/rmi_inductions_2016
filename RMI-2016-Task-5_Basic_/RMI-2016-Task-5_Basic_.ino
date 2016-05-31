#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int main()
{
  //enable interrupts
  Serial.begin(9600);
  sei();
  DDRB|=0xFF;
  PORTB|=0b00000010;
  
 sei();
  //TIMSK1=(1<<OCIE1A);
  
  EIMSK|=(1<<INT0);
  EICRA|=(1<<ISC01);
  
  DDRD|=0b00000000;
  while(1)
  {
   PORTB = 0b00000001;
   _delay_ms(500);
   PORTB = 0b00000010;
   _delay_ms(500);
  }
  return 0;
}

ISR(INT0_vect)
{
  //unsigned a;
  //if(PORTB == 0b00000010) a=2;
  //else a = 1;
  Serial.println("Hi");
  PORTB = 0b00000011;
  _delay_ms(200);
  PORTB = 0b00000000;
  _delay_ms(200);
  Serial.println("Bye");
  
  //if(a==2) PORTB = 0b00000010;
  //else PORTB = 0b00000001;

}
