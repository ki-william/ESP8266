#include <ESP8266WiFi.h>

// <GPIO Definitions
# define D0 16
# define D1 5
# define D2 4
# define D3 0
# define D4 2
# define D5 14
# define D6 12 
# define D7 13
# define D8 1
# define RX 3        //RX//     (D9)  //when using UART(Serial) dont' touch RX
# define TX 1        //TX//     (D10) //when using UART(Serial) dont' touch RX
# define S3 10       //S3//     (D12) //deosn't work
# define S2 9        //S2//     (D11) //deosn't work
# define CMD 11
# define CLK 6
// Pins from 1 to 12 is PWM ~ pins only (D1,D2,D4,D6) are stable 
// don't use any other pins for pwm only -> (D1,D2,D4,D6)
// don't use s2 or s3 as a GPIO at any case ... ur hole programe will crash
//  GPIO/>  

void pwmTest (int pin );

void setup() {
  Serial.begin(115200);
//pinMode(0,OUTPUT); //D3                       
//pinMode(1,OUTPUT); //TX      
  pinMode(2,OUTPUT); //D4
//pinMode(3,OUTPUT); //RX      
  pinMode(4,OUTPUT); //D2
  pinMode(5,OUTPUT); //D1
//pinMode(6,OUTPUT); //CLK
//pinMode(7,OUTPUT); // ?
//pinMode(8,OUTPUT); // ?
//pinMode(9,OUTPUT); //s2     
//pinMode(10,OUTPUT); //s3 
//pinMode(11,OUTPUT); //CMD  
  pinMode(12,OUTPUT);//D9
  

}

void loop() {
Serial.println("\n--------------------------------");

//Serial.println(" pwm test for TX  ");
 //pwmTest ( 1 );
///
 Serial.println(" pwm test for D4  ");
 pwmTest ( 2 );
 ///
 //Serial.println(" pwm test for RX  ");
// pwmTest ( 3 );
///
 Serial.println(" pwm test for D2  ");
pwmTest ( 4 );
///
 Serial.println(" pwm test for D1  ");
 pwmTest ( 5 );
 ///
 //Serial.println(" pwm test for clk  ");
 //pwmTest ( 6 );
 ///
 //Serial.println(" pwm test for 7?  ");
 //pwmTest ( 7 ); //pwm for this pin cause shutdown to the nodeMcu
 ///
 //Serial.println(" pwm test for 8?  ");
 //pwmTest ( 8 );
 ///
// Serial.println(" pwm test for S2  ");
 //pwmTest ( 9 );
 ///
 //Serial.println(" pwm test for S3  ");
 //pwmTest ( 10 );
 ///
 //Serial.println(" pwm test for CMD  ");
 //pwmTest ( 11 ); //pwm on this pin make node forced shutdown (bug)
///
Serial.println(" pwm test for D6  ");
 pwmTest ( 12 );

 
}


//////// GPIOs testin Function /////////
void pwmTest (int pin )
{
  Serial.print("PIN ");
   Serial.print(pin);
   Serial.println(" PWM testing");
   delay (5000);
for (int i =0 ; i<=255 ; i++)
{ 
  analogWrite(pin,i);
  delay (50);
}

Serial.println("--------------------------------");

}
//////// GPIOs testin Function //////
