#include <GSM.h>
#include <LedControl.h>

#include <GSM3CircularBuffer.h>
#include <GSM3IO.h>
#include <GSM3MobileAccessProvider.h>
#include <GSM3MobileCellManagement.h>
#include <GSM3MobileClientProvider.h>
#include <GSM3MobileClientService.h>
#include <GSM3MobileDataNetworkProvider.h>
#include <GSM3MobileMockupProvider.h>
#include <GSM3MobileNetworkProvider.h>
#include <GSM3MobileNetworkRegistry.h>
#include <GSM3MobileServerProvider.h>
#include <GSM3MobileServerService.h>
#include <GSM3MobileSMSProvider.h>
#include <GSM3MobileVoiceProvider.h>
#include <GSM3ShieldV1.h>
#include <GSM3ShieldV1AccessProvider.h>
#include <GSM3ShieldV1BandManagement.h>
#include <GSM3ShieldV1BaseProvider.h>
#include <GSM3ShieldV1CellManagement.h>
#include <GSM3ShieldV1ClientProvider.h>
#include <GSM3ShieldV1DataNetworkProvider.h>
#include <GSM3ShieldV1DirectModemProvider.h>
#include <GSM3ShieldV1ModemCore.h>
#include <GSM3ShieldV1ModemVerification.h>
#include <GSM3ShieldV1MultiClientProvider.h>
#include <GSM3ShieldV1MultiServerProvider.h>
#include <GSM3ShieldV1PinManagement.h>
#include <GSM3ShieldV1ScanNetworks.h>
#include <GSM3ShieldV1ServerProvider.h>
#include <GSM3ShieldV1SMSProvider.h>
#include <GSM3ShieldV1VoiceProvider.h>
#include <GSM3SMSService.h>
#include <GSM3SoftSerial.h>
#include <GSM3VoiceCallService.h>

char data; // variable contenant le caractère lu
int DIN =12 ;
int CS = 11;
int CLK = 10;
LedControl lc (DIN,CLK,CS,1);
byte v_s[]= {B00000000,B01000010,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000};
byte v_r[]= {B11111111,B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000};
byte n_r[]= {B11111111,B00000000,B01000010,B01100010,B01010010,B01001010,B01000110,B01000010};
byte n_s[]= {B00000000,B00000000,B01000010,B01100010,B01010010,B01001010,B01000110,B01000010};
int position=0;

int  Marios_ideas [8] [54] ={
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0},
 {0,1,1,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0},
  {0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},
  {0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0, 1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0}
  };

void setup() 
{ 
Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
lc.shutdown(0,false);
lc.setIntensity(0,8);
lc.clearDisplay(0);
}

void loop() {
/*
 // Allume la LED
      digitalWrite(PIN_LED,HIGH);
 // Attend 1 seconde    
      delay(1000);
// Eteint la LED
      digitalWrite(PIN_LED,LOW);
 // Attend 1 seconde     
      delay(1000); 
*/

/* for (int j=0;j<8;j++){
    for (int i=0;i<8;i++){
   lc.setLed(0,i,j,Marios_ideas[j][(i+position)-abs((i+position)/54)*54]);
   }
  }
 delay(2000);
  position=position+1; 
*/



if (Serial.available())
 {     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='0') 
    {
     
      Serial.write('0');
      for(int i =0 ; i<=7 ;i++)
          {
            lc.setRow(0,i,v_r[i]);
          }  
       
        
     } 

      if(data=='1') //si le caractère lu est égale à 1
    {
      for(int i =0 ; i<=7 ;i++)
          {
             lc.setRow(0,i,v_s[i]);
          }
        
         
     } 

      if(data=='2') //si le caractère lu est égale à 1
    {
      for(int i =0 ; i<=7 ;i++)
          {
            lc.setRow(0,i,n_r[i]);
          }
     
        
     } 

 if(data=='3') //si le caractère lu est égale à 1
    {
      for(int i =0 ; i<=7 ;i++)
          {
             lc.setRow(0,i,n_s[i]);
          }
      
     } 

}


}
