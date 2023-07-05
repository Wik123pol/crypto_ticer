//Includes-------------------------------------------
// SCK--18 /SDA-23/A0-2/RESET-4/CS-17/
//#include "WiFi.h"
#include <WiFi.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
//--------------------------------------------------
#include <WiFiClientSecure.h>
#include <HTTPUpdate.h>
#include <WiFiMulti.h>
WiFiMulti WiFiMulti;
#include <WiFiManager.h>
//------------------xegar---------------------------
#include <NTPClient.h>
#include <WiFiUdp.h>
//#include "sntp.h"
WiFiUDP ntpUDP;
//europe.pool.ntp.org
NTPClient timeClient(ntpUDP, "1.in.pool.ntp.org", 5.5 * 36, 600);
//#include <time.h>
#include <TimeLib.h>
unsigned long currTime=0;
//unsigned long refresh=120000;
unsigned long refresh=60000;
//unsigned long refresh_strach_chciwosc=180000;
unsigned long refresh_top7=120000;
 struct tm timeinfo;
 int time_style=0;
//-----------system plikow---------------------------
//#include <Arduino.h>
#include <FS.h>
#include "SPIFFS.h"
#define FileSys SPIFFS
#define FORMAT_SPIFFS_IF_FAILED true
File pngfile;

//--------------dasne do png-------------------------
#include <PNGdec.h>
#include <JPEGDecoder.h>
PNG png;
#define MAX_IMAGE_WDITH 240 // Adjust for your images
//int16_t xpos = 0;
//int16_t ypos = 0;
int  xpos = 0;
int ypos = 0;
int x=0;
int y=0;
String Png_name="";//nazwa coina ADA ETH itp....
//---------------dabe jpeg-------------------------
#include <JPEGDecoder.h>
//---------------ekran tft---------------------------
#include "SPI.h"
#include <TFT_eSPI.h>              // Hardware-specific library
TFT_eSPI tft = TFT_eSPI();         // Invoke custom library
//---------------------tft sprites -----------------
TFT_eSprite img = TFT_eSprite(&tft);
// grabiki tla
//#include "coiny.h"//64x64
//#include "crypto2.h"
#include "btc2.h"
//#include "crypto164x128.h"
#include "crypto160X140.h"//179x140 pixels
//TFT_eSprite coinySprite= TFT_eSprite(&tft);
TFT_eSprite background= TFT_eSprite(&tft);
TFT_eSprite txtSprite= TFT_eSprite(&tft);

//------------------tft kolory-----------------------
#define TFT_GREYlight 0xBDF7
#define TFT_GREY 0x7BEF
#define TFT_hNAVY  0x0008
#define TFT_LNAVY  0x0003
#define TFT_HHNAVY  0x0003
#define TFT_CHART  0x0008
#define TFT_NAVY 0x0002 //0x915C 0x0003
#define TFT_RED   0xF800
#define TFT_YELLOW 0x03E0//DARKGREEN
#define UTFT_FORMAT
//------------fonty--------------------------
//#include "NotoSansBold15.h"
//#include "NotoSansBold36.h"
//#include <Fonts/FreeSerif9pt7b.h>
//#include <Fonts/FreeMonoBoldOblique12pt7b.h>
//#include "Free_Fonts.h" ;
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36
//---------wifi pasword and ssid--------------------
char  chPassword[] = "5bc9ef5af8";
char  chSSID[] = "FOR-997T";
char  chBuffer[128];
//---------------------baner bild-----eSprite----------------

//------------------------------------
#define IWIDTH  158
#define IHEIGHT 30
#define WAIT 0
String textBaner = ""; //CIAG ZNAKOW DO WYSWIETLENIA (STRING COIN+CENA+ZMIANA)
String textBaner1 = "";


//--------------------Strach hciwosc------------------
String Tytul="";
String Skala="";
String StrachChciwosc="";
//--------------------top7---------------------------
String payload = "{}";
String Adresy_top7_png[8];//urtl
String Name_png[8];//ada
String Symbol[8];//cardano
String Marctop7_numer[8];
String cenaTop7[7];
String zmiana24Top7[7];
//--------------------------dane podanych coinow-----
String Id[7];//bitcoin
String Symbol_coin[7];//btc
String Ikona[7];//adres ikony thumb
String Current_price[7];
String Price_change_percentage_24h[7];
//----------------------------certyfikat coingeko ---------
TaskHandle_t Task2; //WIFI HTTP SOCKET
WiFiClientSecure client;
const static char * test_root_ca PROGMEM = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIFGjCCBMCgAwIBAgIQCVw9G1O9WlEB9NDcTJv0AjAKBggqhkjOPQQDAjBKMQsw\n" \
"CQYDVQQGEwJVUzEZMBcGA1UEChMQQ2xvdWRmbGFyZSwgSW5jLjEgMB4GA1UEAxMX\n" \
"Q2xvdWRmbGFyZSBJbmMgRUNDIENBLTMwHhcNMjIwNzIwMDAwMDAwWhcNMjMwNzIw\n" \
"MjM1OTU5WjBtMQswCQYDVQQGEwJVUzETMBEGA1UECBMKQ2FsaWZvcm5pYTEWMBQG\n" \
"A1UEBxMNU2FuIEZyYW5jaXNjbzEZMBcGA1UEChMQQ2xvdWRmbGFyZSwgSW5jLjEW\n" \
"MBQGA1UEAxMNY29pbmdlY2tvLmNvbTBZMBMGByqGSM49AgEGCCqGSM49AwEHA0IA\n" \
"BClhuDrHA/l3MsxJrqKErZYN2rq0UROcB2T7J3bpNHHvj4YhQslpZRvNMsb75kDA\n" \
"umMkjz7gaEZ1ouVfSnPdzQWjggNjMIIDXzAfBgNVHSMEGDAWgBSlzjfq67B1DpRn\n" \
"iLRF+tkkEIeWHzAdBgNVHQ4EFgQUAfG+PIw2i3GE/sj/IqChzIbpBtQwKQYDVR0R\n" \
"BCIwIIIPKi5jb2luZ2Vja28uY29tgg1jb2luZ2Vja28uY29tMA4GA1UdDwEB/wQE\n" \
"AwIHgDAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwewYDVR0fBHQwcjA3\n" \
"oDWgM4YxaHR0cDovL2NybDMuZGlnaWNlcnQuY29tL0Nsb3VkZmxhcmVJbmNFQ0ND\n" \
"QS0zLmNybDA3oDWgM4YxaHR0cDovL2NybDQuZGlnaWNlcnQuY29tL0Nsb3VkZmxh\n" \
"cmVJbmNFQ0NDQS0zLmNybDA+BgNVHSAENzA1MDMGBmeBDAECAjApMCcGCCsGAQUF\n" \
"BwIBFhtodHRwOi8vd3d3LmRpZ2ljZXJ0LmNvbS9DUFMwdgYIKwYBBQUHAQEEajBo\n" \
"MCQGCCsGAQUFBzABhhhodHRwOi8vb2NzcC5kaWdpY2VydC5jb20wQAYIKwYBBQUH\n" \
"MAKGNGh0dHA6Ly9jYWNlcnRzLmRpZ2ljZXJ0LmNvbS9DbG91ZGZsYXJlSW5jRUND\n" \
"Q0EtMy5jcnQwDAYDVR0TAQH/BAIwADCCAX4GCisGAQQB1nkCBAIEggFuBIIBagFo\n" \
"AHUA6D7Q2j71BjUy51covIlryQPTy9ERa+zraeF3fW0GvW4AAAGCGTf04wAABAMA\n" \
"RjBEAiARsGfBoYllDXmGY5zi8cR3dNQ0lvmhMh0HPeu1i3cDMwIgF86DFg8JU4TK\n" \
"p/axJSFHibwmY7XIw6G+eaBl2KVGlRgAdwA1zxkbv7FsV78PrUxtQsu7ticgJlHq\n" \
"P+Eq76gDwzvWTAAAAYIZN/UVAAAEAwBIMEYCIQCQZLdcn9rrE0wvJvBs31exwK3o\n" \
"v4WqfhTO+ejNAJhfyQIhAJcPAHK5cL9sOdjltPrn7vIvP+a+O9uA3IA3/FuzU9gR\n" \
"AHYAtz77JN+cTbp18jnFulj0bF38Qs96nzXEnh0JgSXttJkAAAGCGTf1CQAABAMA\n" \
"RzBFAiAZNpPcqVNcj9C+P7p018fN6G30E7/5Q4oc2v495jXj9QIhAJveDOihcrJT\n" \
"FuHahspPog0b/wvBgAP8RId363RmFvHiMAoGCCqGSM49BAMCA0gAMEUCIHUyTeMm\n" \
"v1cGDnGqXLqZ8xWU8eO9eLqdBlYtVtt8P7EkAiEA73En14Wxhfw1+Y2YFBVHasG8\n" \
"24W+BeQN3thONsx82Zs=\n" \
"-----END CERTIFICATE-----\n" ;
//---------------------------------------------
void setup()
{
  Serial.begin (115200);
  Serial.print("Connecting to Wifi");
  //--------------tft setup------------------
  tft.begin();
  tft.init();
  tft.setRotation(1);
  //--------------trzcionki napisy incjacja-------
  tft.fillScreen(TFT_hNAVY);
  tft.setTextColor(TFT_YELLOW,TFT_hNAVY);
  tft.setSwapBytes(true);
  Baner_crypto();
  //------------fs init------------------
    delay(1000);
    if (!FileSys.begin()) {
	    Serial.println("LittleFS initialisation failed!");
	    while (1) yield(); // Stay here twiddling thumbs waiting
    }
	
	//---------------------------------------
	  //background.createSprite(179,140);
	  //background.setSwapBytes(true);
	  // txtSprite.setTextColor(TFT_BLUE,TFT_BLACK);
	 //  background.pushImage(0,0,192,128,btc2);
	  Baner_crypto();
	  ekran_startowy_laczenie();
	
  //---------------wifi-------------------
  //    http://192.168.4.1/
  WiFiManager wm;
  bool res;
  res = wm.autoConnect("Crypto_Ticer");
  if(!res) {
	  Serial.println("Failed to connect");
	  // ESP.restart();
  }
  else {
	  //if you get here you have connected to the WiFi
	  Serial.println("connected...yeey :)");
  }
   int WifiRSSI = WiFi.RSSI();
/////////////////////////////////////
  ekran_startowy_polaczony();
 // tft.fillScreen(TFT_hNAVY);
 // Serial.print("Connected to ");
 // Serial.println(chSSID);
 // Serial.print("IP address: ");
 // Serial.println(WiFi.localIP());
 // Serial.print("RSSI==: ");
 // Serial.println(WifiRSSI);
   tft.setSwapBytes(false);
  time_style=0;
  setClock();
  wyswietl_fear_greed();
  //-----------odczyt ikon-------------------
   coingeko_coin_ikony();
   Ikony_adresy();
   coingeko_coin_cena();
   tft.fillScreen(TFT_hNAVY);
   print_main_coin();

  //--------------------------------------------------------------
}
//////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------
void loop()
{
 // background.pushImage(0,0,192,128,btc2);
 // background.pushSprite(0,0);
  //---------------------------------------------------------
  
   tft.setCursor(2, 1);
   tft.print("*");
   
  //  if(millis()>refresh_strach_chciwosc)//18
   //   {
    //  setClock();
   //   wyswietl_fear_greed();
     // currTime=millis();
   //  }
  
     if(millis()==currTime+refresh)//6
     {
		tft.setSwapBytes(true); 
	  background.pushImage(0,0,179,140 ,crypto160X140);
	   background.pushSprite(0,0);
	    tft.setSwapBytes(false);
	  setClock();
      coingeko_coin_cena();
	  print_main_coin();
     }
     if(millis()>currTime+refresh_top7)//22
     {
		 tft.setSwapBytes(true);
     background.pushImage(0,0,192,128,btc2);
    background.pushSprite(0,0);
	 tft.setSwapBytes(false);
	  setClock();
	  odczyt_top7();
      cenatop7();
      tablica_adresow_png();//png_downloda imagine
	  print_top7();
	  wyswietl_fear_greed();
	  currTime=millis();
   }
  
   delay(400);
   tft.setCursor(2, 1);
   tft.print(" ");
   delay(400);
   
  
}
//--------------------set time-------------------
void setClock() 
{
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");  // UTC

  Serial.println(F("Waiting for NTP time sync: "));
  time_t now = time(nullptr);
  while (now < 8 * 3600 * 2) {
    yield();
    delay(500);
    Serial.print(F("."));
    now = time(nullptr);
  }

 // Serial.println(F(""));
  //tft.fillRoundRect(0,0,160,10,3, TFT_hNAVY);
  tft.setTextColor(TFT_YELLOW, TFT_hNAVY);
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  
  if(time_style>=1)
  {
	  tft.setTextSize(2);
	  tft.setCursor(40,10);
	  tft.setTextColor(TFT_GREY, TFT_hNAVY);
	  tft.print(&timeinfo,  "%H:%M:%S");  
	  tft.setTextSize(1);
	  tft.setCursor(40,30);
	  tft.setTextColor(TFT_YELLOW, TFT_hNAVY);
	  tft.print(&timeinfo,  "%B %d %Y");
  }
  else
  {
   tft.setTextSize(1);  
   tft.setCursor(95,1);
   tft.print("Clock");
   tft.setCursor(125,1);
   tft.print(&timeinfo,  "%H:%M");
  }
   
   Serial.print("time_style=");
   Serial.println(time_style);
   Serial.print(&timeinfo, "%B %d %Y %H:%M");


}

//---------------------------------------------------------------------
void wyswietl_czas()
{

	
}
