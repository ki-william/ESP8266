/*
 * NodeMcue has only one ADC pin->17 (A0)(ADC0) 
 * its ADC register is 10-bit 
 * And its ADC's 
 * stable  
 * © kirolos Magdy
 */

#define A0 17

void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);

}

void loop() {

float x = analogRead(A0);
x *=(3.0/1023.0);  // equation to show the real reading value
Serial.println(x);
delay(500);


}
