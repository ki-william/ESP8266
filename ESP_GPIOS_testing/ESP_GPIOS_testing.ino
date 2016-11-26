#include <ESP8266WiFi.h>
// <GPIO Definitions
# define d0 16
# define d1 5
# define d2 4
# define d3 0
# define d4 2
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
// Pins from 1 to 12 is PWM ~ pins
// don't use s2 or s3 as a GPIO at any case ... ur hole programe will crash
//  GPIO/>  

#define testMode input // make testMode  input to select input_test_mode and output to select output_test_mode //this line used only in advanced IDEs
void testOut (int pin );
void testin (int pin );

void setup ()
{  Serial.begin(115200);

  Serial.begin(115200);

}

void loop ()
{
 
#if testMode==output  //this line used only in advanced IDEs
Serial.println("OUTPUT testing");
Serial.println("--------------------------------");
/////////////////////////////
 pinMode(0,OUTPUT); //D3                       
//pinMode(1,OUTPUT); //TX      
  pinMode(2,OUTPUT); //D4
//pinMode(3,OUTPUT); //RX      
  pinMode(4,OUTPUT); //D2
  pinMode(5,OUTPUT); //D1
//pinMode(9,OUTPUT); //s2     
//pinMode(10,OUTPUT); //s3   
  pinMode(12,OUTPUT);//D9
  pinMode(13,OUTPUT);//D7
  pinMode(14,OUTPUT);//D5
  pinMode(15,OUTPUT);//D8
  pinMode(16,OUTPUT);//D0
////////////////////////////
 Serial.println(" writing to D3  ");
 testOut ( 0 );
///
 Serial.println(" writing to D4  ");
 testOut ( 2 );
///
 Serial.println(" writing to D2  ");
testOut ( 4 );
///
 Serial.println(" writing to D1  ");
 testOut ( 5 );
///
Serial.println(" writing to D9  ");
 testOut ( 12 );
///
 Serial.println(" writing to D7  ");
 testOut ( 13 );
///
 Serial.println(" writing to D5  ");
 testOut ( 14 );
///
 Serial.println(" writing to D8  ");
 testOut ( 15 );
///
 Serial.println(" writing to D0  ");
 testOut ( 16 );
#endif   //this line used only in advanced IDEs



#if testMode == input   //this line used only in advanced IDEs
 Serial.println("intput testing");
Serial.println("--------------------------------");
/////////////////////////////
 pinMode(0,INPUT); //D3                       
//pinMode(1,INPUT); //TX      
  pinMode(2,INPUT); //D4
//pinMode(3,INPUT); //RX      
  pinMode(4,INPUT); //D2
  pinMode(5,INPUT); //D1
//pinMode(9,INPUT); //s2     
//pinMode(10,INPUT); //s3   
  pinMode(12,INPUT);//D9
  pinMode(13,INPUT);//D7
  pinMode(14,INPUT);//D5
  pinMode(15,INPUT);//D8
  pinMode(16,INPUT);//D0
////////////////////////////
 Serial.println(" Reading from D3  ");
 testin ( 0 );
///
 Serial.println(" Reading from D4  ");
 testin ( 2 );
///
 Serial.println(" Reading from D2  ");
testin ( 4 );
///
 Serial.println(" Reading from D1  ");
 testin ( 5 );
///
Serial.println(" Reading from D9  ");
 testin ( 12 );
///
 Serial.println(" Reading from D7  ");
 testin ( 13 );
///
 Serial.println(" Reading from D5  ");
 testin ( 14 );
///
 Serial.println(" Reading from D8  ");
 testin ( 15 );
///
 Serial.println(" Reading from D0  ");
 testin ( 16 );
#endif  //this line used only in advanced IDEs not arduino IDE

//note that//
/* the pins d9,d3,d4,d7,d5 when nothing connected to them
 * its readingss usually equal 1 
 * And other pins usually equal 0
 */
}


//////// GPIOs testOut Function /////////
void testOut (int pin )
{
   Serial.print("pin " );
   Serial.print(pin);
   Serial.println(" is on");
   digitalWrite(pin,1);
   delay(10000);
   Serial.print("pin " );
   Serial.print(pin);
   Serial.println(" is off");
   digitalWrite(pin,0);
   delay(500);
   Serial.println("--------------------------------------");
}
//////// GPIOs testOut Function //////



//////// GPIOs testin Function /////////
void testin (int pin )
{
  delay(500);
   int x ;
   x=digitalRead(pin);
   Serial.print("pin " );
   Serial.print(pin);
   Serial.print(" reading is : ");
   Serial.println(x);
   delay(10000);
   x=digitalRead(pin);
   Serial.print("pin " );
   Serial.print(pin);
   Serial.print(" reading is : ");
   Serial.println(x);
   Serial.println("--------------------------------------");

}
//////// GPIOs testin Function //////
