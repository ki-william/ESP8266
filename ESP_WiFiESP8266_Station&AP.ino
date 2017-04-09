/*
 * NodeMcue Can works in the following connection modes  
 * 1-Station "STA" 
 * 2-Acesspoint "AP" 
 * 3-Both "AP_STA"
 * © kirolos Magdy
 */
 
#include<ESP8266WiFi> //WiFi connections library

#define ConnectionMode 1 //1 for station 2 for AP and 3 for both 




void setup()
{

  
#if ConnectionMode==1 //this line used only in advanced IDEs

      //---------- Mode 1 (STA) ----------//  
      //Seting the ESP8266 WiFi interface Mode
      WiFi.mode(WIFI_STA); 
      
       
      //Tring to Connect to the WiFi Network
      WiFi.begin("NodeMCU","mypassword"); // uint8_t begin (char* SSID , char* Password ,int Channel) NOTE : you can ignore channel number and it'll be choosen auto
      
      
      //wait the MCU to be connected to the WiFi
      //Status Function'll return WL_CONNECTED when the connection to the WiFi network is sucsess @REFRENCE(1)  
      Serial.print("Tring to Connect");          //SERIAL MONITOR PRINTING LINE//
      while(WiFi.status()!=WL_CONNECTED) 
        {  
            delay(500);  
            Serial.print(".");                  //SERIAL MONITOR PRINTING LINE//
        } 
      Serial.println(" ");                     //SERIAL MONITOR PRINTING LINE//
      
      
      //Get the network info
      IPAddress local_ip = WiFi.localIP();
      IPAddress gateway_ip = WiFi.gatewayIP();
      String mac= WiFi.macAddress(); //ESP station interface MACAddress
      uint8_t ch = WiFi.channel() ;
      
      
      //Printing the network info. to the Serial monitor 
      Serial.println("\n------------------------------------\n**** Station interface info. ****\n");    //SERIAL MONITOR PRINTING LINE//
      
      Serial.print("Local IP :");                  //SERIAL MONITOR PRINTING LINE//
      Serial.println(local_ip);                    //SERIAL MONITOR PRINTING LINE//

      Serial.print("Gateway IP :");                //SERIAL MONITOR PRINTING LINE//
      Serial.println(gateway_ip);                  //SERIAL MONITOR PRINTING LINE//

      Serial.print("Station BSSID :");             //SERIAL MONITOR PRINTING LINE//
      Serial.println(mac);                        //SERIAL MONITOR PRINTING LINE//

      Serial.print("Current Channel :");          //SERIAL MONITOR PRINTING LINE//
      Serial.println(ch);                         //SERIAL MONITOR PRINTING LINE//
      Serial.println("------------------------------------ \n \n");                                     //SERIAL MONITOR PRINTING LINE//
    
      //---------- Mode 1 (STA) ----------//  
    
#endif   //this line used only in advanced IDEs








 
#if ConnectionMode==2  //this line used only in advanced IDEs

      //---------- Mode 2 (AP) ----------// 
      //Seting the ESP8266 WiFi interface Mode
      WiFi.mode(WIFI_AP);
      
      //Starting the AP 
      WiFi.softAP("kie","123456789");  // Void softAP(SSID , PASSWORD , CHANNEL )

      //Config. the AP
      //You have the choise to not using this function and DHCP will config. the AP auto
      //This function disables the DHCP for the AP interface
      WiFi.softAPConfig(string_to_ip("192.168.1.5"),string_to_ip("192.168.1.1") ,string_to_ip("255.255.255.0")) ;//void softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet)
      
      //Get the ESP8266 internal AP interface info.
      //Note : there's two interfaces that supports wireless connection inside the ESP8266 one works as a STATION and the other wotks as AP
      //Every interface have it's unique MacAddress and if they works at the same time every one of'em will get a diffent ip
      IPAddress AP_ip = WiFi.softAPIP();         //IPAddress softAPIP( void )
      String AP_mac = WiFi.softAPmacAddress();  // String softAPmacAddress ( void )

      //Printing the AP info. to the Serial monitor 
      Serial.println("\n------------------------------------\n**** Acess point interface info. ****\n");     //SERIAL MONITOR PRINTING LINE//
      Serial.print("AP IP :");                                //SERIAL MONITOR PRINTING LINE//
      Serial.println(AP_ip);                                  //SERIAL MONITOR PRINTING LINE//
      Serial.print("AP BSSID :");                            //SERIAL MONITOR PRINTING LINE//
      Serial.println(AP_mac);                                //SERIAL MONITOR PRINTING LINE//
      //---------- Mode 2 (AP) ----------//   
     
#endif   //this line used only in advanced IDEs





#if ConnectionMode==3  //this line used only in advanced IDEs

      //---------- Mode 3 (AP_STA) ----------// 
      //Seting the ESP8266 WiFi interface Mode
      WiFi.mode(WIFI_AP_STA);
             
      //Tring to Connect to the WiFi Network
      WiFi.begin("NodeMCU","mypassword"); // uint8_t begin (char* SSID , char* Password ,int Channel) NOTE : you can ignore channel number and it'll be choosen auto
          
          
      //wait the MCU to be connected to the WiFi
      //Status Function'll return WL_CONNECTED when the connection to the WiFi network is sucsess @REFRENCE(1)  
      Serial.print("Tring to Connect");           //SERIAL MONITOR PRINTING LINE//
      while(WiFi.status()!=WL_CONNECTED) 
        {  
            delay(500);  
            Serial.print(".");                    //SERIAL MONITOR PRINTING LINE//
        } 
      Serial.println(" ");                     //SERIAL MONITOR PRINTING LINE//
    

      //Get the network info
      IPAddress local_ip = WiFi.localIP();
      IPAddress gateway_ip = WiFi.gatewayIP();
      String mac= WiFi.macAddress(); //ESP station interface MACAddress
      uint8_t ch = WiFi.channel() ;


      //Printing the network info. to the Serial monitor 
      Serial.println("\n------------------------------------\n**** Station interface info. ****\n");    //SERIAL MONITOR PRINTING LINE//
    
      Serial.print("Local IP :");                  //SERIAL MONITOR PRINTING LINE//
      Serial.println(local_ip);                    //SERIAL MONITOR PRINTING LINE//

      Serial.print("Gateway IP :");                //SERIAL MONITOR PRINTING LINE//
      Serial.println(gateway_ip);                  //SERIAL MONITOR PRINTING LINE//

      Serial.print("Station BSSID :");             //SERIAL MONITOR PRINTING LINE//
      Serial.println(mac);                        //SERIAL MONITOR PRINTING LINE//

      Serial.print("Current Channel :");          //SERIAL MONITOR PRINTING LINE//
      Serial.println(ch);                         //SERIAL MONITOR PRINTING LINE//
      Serial.println("------------------------------------ \n \n");                                     //SERIAL MONITOR PRINTING LINE//


   
      //Starting the AP 
      WiFi.softAP("kie","123456789");  // Void softAP(SSID , PASSWORD , CHANNEL )

      //Config. the AP
      //You have the choise to not using this function and DHCP will config. the AP auto
      //This function disables the DHCP for the AP interface
      WiFi.softAPConfig(string_to_ip("192.168.1.5"),string_to_ip("192.168.1.1") ,string_to_ip("255.255.255.0")) ;//void softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet)

      //Get the ESP8266 internal AP interface info.
      //Note : there's two interfaces that supports wireless connection inside the ESP8266 one works as a STATION and the other wotks as AP
      //Every interface have it's unique MacAddress and if they works at the same time every one of'em will get a diffent ip
      IPAddress AP_ip = WiFi.softAPIP();         //IPAddress softAPIP( void )
      String AP_mac = WiFi.softAPmacAddress();  // String softAPmacAddress ( void )

      //Printing the AP info. to the Serial monitor 
      Serial.println("\n------------------------------------\n**** Acess point interface info. ****\n");     //SERIAL MONITOR PRINTING LINE//
      Serial.print("AP IP :");                                //SERIAL MONITOR PRINTING LINE//
      Serial.println(AP_ip);                                  //SERIAL MONITOR PRINTING LINE//
      Serial.print("AP BSSID :");                            //SERIAL MONITOR PRINTING LINE//
      Serial.println(AP_mac);                                //SERIAL MONITOR PRINTING LINE//
      //  AP Connection Setup/>   
      //---------- Mode 3 (AP_STA) ----------// 


#endif   //this line used only in advanced IDEs


}



void loop() 
{

  
    //ESP8266 Main Codes
    

}
