//----------------------------------top 7 odczyt------------------------
//coins": [{"item":{"id":"dogechain","coin_id":26828,"name":"Dogechain","symbol":"DC","market_cap_rank":249,
int idx_top6 = 0;
void odczyt_top7()
{    

	 //setClock();
     Serial.println ("-------odczyt Top7-------");
	 //------------------------------------------
	 client.setCACert(test_root_ca);
     HTTPClient http;
     http.begin ("https://api.coingecko.com/api/v3/search/trending");
     int httpCode = http.GET();
     delay (100);
   if (httpCode > 0)
    {
    payload = http.getString();
    //Serial.print(payload);
    DynamicJsonDocument doc(6144);
    DeserializationError error = deserializeJson(doc, payload);
    if (error)
    {
      return;
    }
    String reportString = payload;
    JsonObject object = doc.as<JsonObject>();
    //--"item":{"id":"dogechain","coin_id":26828,"name":"Dogechain","symbol":"DC","market_cap_rank":249,-----------
    for (int idx = 0; idx <= 6;)
    {
      String  world = object["coins"][idx]["item"]["id"].as<String>();//shiba-inu
      String  symbol = object["coins"][idx]["item"]["symbol"].as<String>();//SHIB
      String  Urtl_png = object["coins"][idx]["item"]["thumb"].as<String>();// Adres urtl
      String  marc_cap = object["coins"][idx]["item"]["market_cap_rank"].as<String>();//marc_cap pozycja na liscie
      //----------------------------------------------------------
      Adresy_top7_png[idx] = Urtl_png;
      Name_png[idx] = symbol;//symbol ada
      Symbol[idx] = world;
      Marctop7_numer[idx] = marc_cap; //pozycjana liscie
     // Serial.print("-----Symbol----   ");
     // Serial.println(Symbol[idx]);
	 // Serial.print("-----html---   ");
	 // Serial.println(Urtl_png);
      // ----------------------------------------------
      idx = idx + 1;
    }
  }
   else {
	  // Serial.print("=========odczyt_top7()===http error======= ");
	  // Serial.print(httpCode);
	    http.end();
		  for (int idx = 0; idx <= 6;)
		 {
		    Name_png[idx]="";
			idx++;
		 }
		WiFi.disconnect();
		WiFi.reconnect();
		
	   return;
	   }
    http.end();
}
//------------------------------tablice z danymi--------------
void tablica_adresow_png()
{
  Serial.print("    Adresy_top7_png[idx]    ");
  for (int idx = 0; idx <= 6;)
  {
   
    //-----------------png lub jpeg------dodanie do nazwy  ------------
    String myString = Adresy_top7_png[idx];
	//-------------------png PNG--------------
	if ( myString.indexOf(".PNG?")>0|| myString.indexOf(".png?")> 0)
	{
		Name_png[idx] = Name_png[idx] + ".png";
	}
	//-----------------jprg-----------------
   if ( myString.indexOf(".jpeg?")>0|| myString.indexOf(".jpg?")>0)
    {
      Name_png[idx] = Name_png[idx] + ".jpeg";
    }
    //-----------------------------------------------
    downloadAndSaveFile(Name_png[idx], Adresy_top7_png[idx]);
    idx++;
  }

}
//---------------------------ceny top7--------------------------------

//Serial.println(Symbol[idx]);nazwy coin do urtl
void cenatop7()
{
	
 Serial.println ("-------cena_top7-------");
for (int idx = 0; idx <= 6;)
{
	nazwa = Symbol[idx];
	
	//---------------------------------------------------------------------------------------
	if ((WiFi.status() == WL_CONNECTED))
	{
		WiFiClientSecure client;
		client.setCACert(test_root_ca);
		HTTPClient http;
		delay(200);
		// HTTPClient http;
		//https://api.coingecko.com/api/v3/search/trending
		//https://api.coingecko.com/api/v3/simple/price?ids=bitcoin%2Cethereum&vs_currencies=eur%2Cgbp%2Cusd&include_24hr_change=true
		//------------------------------------------------------------------------------------
		http.begin ("https://api.coingecko.com/api/v3/simple/price?ids=" + nazwa + "&vs_currencies=usd&include_24hr_change=true");
		int httpCode = http.GET();
		delay(100);
		if (httpCode <= 0) {
			return;
		}
		//---------------------------------------------------------------------------------
		const size_t capacity = JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(6) + 150;
		DynamicJsonDocument doc(capacity);
		String payload = http.getString();
		const char* json = payload.c_str();
		//Serial.print(payload);
		//---------------------------------------------------------------------------------
		deserializeJson(doc, json);
		//nazwa z tablicy Symbol[0],Symbol[1],Symbol[2],Symbol[3],Symbol[4],Symbol[5],Symbol[6],
		// const char* wifi_pass = wifi_pass_start.c_str();
		// const char* nazwax=nazwa.c_str();
		//--------------------------------------------------------------------------------
		JsonObject nazwax = doc[nazwa];
		String bitcoin_usd = nazwax["usd"]; //cena
		String bitcoin_usd_24h_change = nazwax["usd_24h_change"]; // zmiana %
		//-----------------------------------------------------------------------------
	    cenaTop7[idx]=bitcoin_usd ;
	    zmiana24Top7[idx]=bitcoin_usd_24h_change;
		//Serial.println("-------------------------------");
		//Serial.print("USD: ");
		//Serial.println(bitcoin_usd );
		//Serial.print("USD 24hr %: ");
		//Serial.println(bitcoin_usd_24h_change);

		//--------------------------------------------------------------------------
		http.end();
	}
	idx = idx + 1;
}
}



//---------------------------wyswietl top 7----------------------------
int ile = 0;
void print_top7()
{
	tft.fillRoundRect(2,10,75,38,3, TFT_HHNAVY); tft.fillRoundRect(80,10,76,38,3, TFT_HHNAVY);
    tft.fillRoundRect(2,50,75,38,3, TFT_HHNAVY);tft.fillRoundRect(80,50,76,38,3, TFT_HHNAVY);
    tft.fillRoundRect(2,89,75,38,3, TFT_HHNAVY);tft.fillRoundRect(80,89,76,38,3, TFT_HHNAVY);
	//==========================================================================
  y = 5;
  x=20;
  for (int idx = 0; idx <= 6;)
  {
    //--usuwa .png .jpeg myString.remove(index);
    String Symbol = Name_png[idx];
    Symbol.replace(".png", " ");
    Symbol.replace(".jpeg", " ");
    String nazwa_png = Name_png[idx];
    //Serial.print("nazwa_pliku  ");
    //Serial.println(Name_png[idx]);
	
    if(idx==0)
	{
		x=62;
		y=16;//7
	
	}
	if (idx==1)
	 {
		 x=140;
		 y=16;//7
		
	 }
	 //--------------------------
	if (idx==2)
	 {
		x=62;
		y=56;//50

	 }
	 if (idx==3)
	 {
		x=140;
	    y=56;//50
	
     }
	//--------------------------
     if (idx==4)
     	{
	     x=62;
	     y=95;//95
	
     	}
     if (idx==5)
     	{
	     x=140;
	     y=95;
		
     	}

    tft.setTextColor(TFT_YELLOW, TFT_HHNAVY);
	tft.setCursor(x-50, y-3);
	tft.print(Symbol);
	
	//-----------------------------
	 tft.setTextColor(TFT_GREY, TFT_HHNAVY);
	 tft.setCursor(x-58, y+8);
	 tft.print("$ ");
	 tft.setCursor(x-58, y+19);
	 tft.print("% ");
	 
	 
	 tft.setCursor(x-50, y+8);
	 String myString = cenaTop7[idx];
	 String sub = myString.substring(0, 6);
	 tft.setTextColor(TFT_GREYlight, TFT_HHNAVY);
	 // if(myString1.indexOf('-')==TRUE)
	 // {
	//	  tft.setTextColor(TFT_RED, TFT_HHNAVY);
	//  }
	  tft.print(sub);
	  tft.setTextColor(TFT_GREYlight, TFT_HHNAVY);
	  tft.setCursor(x-50, y+19);
	  String myString1 = zmiana24Top7[idx];
	  //------------------ZMIANA KOLORU ----------------------
	  int change24=myString1.toInt();
	  if(change24>0)
	  {
		  tft.setTextColor(TFT_GREEN, TFT_HHNAVY); //green
	  }
	  if(change24<0)
	   {
		 tft.setTextColor(TFT_RED, TFT_HHNAVY);
	   }
	    if(change24=0)
	    {
		    tft.setTextColor(TFT_GREY, TFT_HHNAVY);
	    }
	  String sub1 = myString1.substring(0, 4);
	  tft.print(sub1);
	  tft.setTextColor(TFT_YELLOW, TFT_HHNAVY);
	//------------------------------
    Tft_Print_Png_Jpeg(nazwa_png, x-10, y);
    idx++;
   delay(500);
  }
}

/*
#define TFT_GREYlight 0xBDF7
#define TFT_GREY 0x7BEF
#define TFT_hNAVY  0x0007
#define TFT_LNAVY  0x0003
#define TFT_CHART  0x0008
#define TFT_NAVY 0x0002 //0x915C 0x0003
#define TFT_RED   0xF800
#define TFT_YELLOW 0x03E0//DARKGREEN
*/
