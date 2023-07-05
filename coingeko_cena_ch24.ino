//"binancecoin", "ravencoin", "ripple", "optimism","fracton-protocol","kava","cosmos",
//"concierge-io","the-sandbox","solana","decentraland"
//------------------------------tablice z danymi--------------------------------------
//String Id[7];//bitcoin
//String Symbol_coin[7];//btc
//String Ikona[7];//adres ikony thumb
//String Current_price[7];
//-----------------------------------------------------------------------------------------------
String name_coin[] = {"bitcoin", "ethereum","litecoin","cosmos","matic-network", "ripple"
, "optimism","fracton-protocol","kava"};//, "litecoin", "cosmos"}; //id coina
String nazwa = "ethereum";
//------------------------------------------------------
/*TaskHandle_t Task2; //WIFI HTTP SOCKET
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

//

*/
//---------------------------------------------------
void coingeko_coin_ikony()
{
	 if ((WiFi.status() == WL_CONNECTED))
	 {
		 
		 tft.setCursor(10, 10);
		 WiFiClientSecure client;
		 client.setCACert(test_root_ca);
		 HTTPClient http;
		 delay(200);
		// Serial.println ("-------cena-ikona srednia itp-----");
		 for (int idx = 0; idx <= 5;)
		 {
			 nazwa = name_coin[idx];
			 //------------------------------------------------------------------------------------
			 http.begin ("https://api.coingecko.com/api/v3/coins/markets?vs_currency=usd&ids="+nazwa);
			 int httpCode = http.GET();
			 delay(20);
			 if (httpCode <= 0)
			 {
				 return;
			 }
			 Serial.println ("\nStatuscode: " + String(httpCode));
			 delay (100);
			 String payload = http.getString();
			 //---------------------------------------------------------------------------------
			 StaticJsonDocument<2048> doc;
			 DeserializationError error = deserializeJson(doc, payload);
			 if (error) {
				 Serial.print(F("deserializeJson() failed: "));
				 Serial.println(error.f_str());
				 return;
			 }
			 //Serial.print(payload);
			 //---------------------------------------------------------------------------------
			 // deserializeJson(doc, json);
			 //--------------------------------------------------------------------------------
			 JsonObject root_0 = doc[0];
			 String root_0_id = root_0["id"].as<String>(); // "bitcoin"
			 String  root_0_symbol = root_0["symbol"].as<String>(); // "btc"
			 String root_0_name = root_0["name"].as<String>(); // "Bitcoin"
			 String root_0_image = root_0["image"].as<String>();
			 String root_0_current_price = root_0["current_price"].as<String>(); // 16844.53
			 int root_0_market_cap_rank = root_0["market_cap_rank"]; // 1
			 float root_0_high_24h = root_0["high_24h"]; // 17499.05
			 float root_0_low_24h = root_0["low_24h"]; // 16569.89
			 double root_0_price_change_24h = root_0["price_change_24h"]; // -587.6996303281012
			 String root_0_price_change_percentage_24h = root_0["price_change_percentage_24h"].as<String>(); // -3.37134
			 const char* root_0_last_updated = root_0["last_updated"]; // "2022-11-12T08:52:32.388Z"
			 
			 
			 payload="";
			 //-------------------------zapis danych do tablic----------------------------------------
			 //---------1-------
			 Serial.print("symbol ");
			 Serial.println(root_0_symbol);// const char*
			 //--------2--------
			 //--------3--------
			 //--------6-------
			 Serial.print("link_ikony  ");
			 Serial.println(root_0_image );//const char*
			 
			 Symbol_coin[idx]=root_0_symbol;//btc
			 Ikona[idx]=root_0_image;//adres ikony thumb
			 //--------------------------------------------------------------------------
			 http.end();
			 idx = idx + 1;
		 }
		 
	 }
}
//=============================================================================================
void coingeko_coin_cena()
{
	
	
	 if ((WiFi.status() == WL_CONNECTED))
	 {
		 
		// tft.setCursor(10, 10);
		// tft.print("CENA");
		 WiFiClientSecure client;
		 client.setCACert(test_root_ca);
		 HTTPClient http;
		 delay(200);
		// Serial.println ("-------cena-ikona srednia itp-----");
	 for (int idx = 0; idx <= 5;)
	 {
		 nazwa = name_coin[idx];
		 //------------------------------------------------------------------------------------
		 http.begin ("https://api.coingecko.com/api/v3/coins/markets?vs_currency=usd&ids="+nazwa);
		 int httpCode = http.GET();
		 delay(20);
		 if (httpCode <= 0) 
		 {
			 return;
		 }
		 Serial.println ("\nStatuscode: " + String(httpCode));
		 delay (100);
		  String payload = http.getString();
		 //---------------------------------------------------------------------------------
		 StaticJsonDocument<2048> doc;
         DeserializationError error = deserializeJson(doc, payload);
         if (error) {
			 Serial.print(F("deserializeJson() failed: "));
			 Serial.println(error.f_str());
			 return;
		 }
		 //Serial.print(payload);
		 //---------------------------------------------------------------------------------
		 // deserializeJson(doc, json);
		 //--------------------------------------------------------------------------------
		 JsonObject root_0 = doc[0];
		 String root_0_id = root_0["id"].as<String>(); // "bitcoin"
	     String  root_0_symbol = root_0["symbol"].as<String>(); // "btc"
		 String root_0_name = root_0["name"].as<String>(); // "Bitcoin"
		 String root_0_image = root_0["image"].as<String>();
		 String root_0_current_price = root_0["current_price"].as<String>(); // 16844.53
		 int root_0_market_cap_rank = root_0["market_cap_rank"]; // 1
		 float root_0_high_24h = root_0["high_24h"]; // 17499.05
		 float root_0_low_24h = root_0["low_24h"]; // 16569.89
		 double root_0_price_change_24h = root_0["price_change_24h"]; // -587.6996303281012
		 String root_0_price_change_percentage_24h = root_0["price_change_percentage_24h"].as<String>(); // -3.37134
		 const char* root_0_last_updated = root_0["last_updated"]; // "2022-11-12T08:52:32.388Z"
		 
		 
		 payload="";
		 //-------------------------zapis danych do tablic----------------------------------------
		 //---------1-------
		// Serial.print("symbol ");
		// Serial.println(root_0_symbol);// const char*
		 //--------2--------
		// Serial.print("price_change_24h  ");
		// Serial.println(root_0_price_change_24h );//float
		// Serial.print("price_change_24h %  ");
		// Serial.println(root_0_price_change_percentage_24h);//float
		 //--------3--------
		 Serial.print("high_24h  ");
		 Serial.println(root_0_high_24h );//float
		 //--------4--------
		 Serial.print("low_24h  ");
		 Serial.println(root_0_low_24h );//float
		 //--------5--------
		 Serial.print("current_price  ");
		 Serial.println(root_0_current_price);//float
		 //--------6-------
		// Serial.print("link_ikony  ");
	   //  Serial.println(root_0_image );//const char*
		 
		// String Id[idx]=;//bitcoin
		// Symbol_coin[idx]=root_0_symbol;//btc
		// Ikona[idx]=root_0_image;//adres ikony thumb
		 Current_price[idx]= root_0_current_price;
		 Price_change_percentage_24h[idx]= root_0_price_change_percentage_24h;
		  //--------------------------------------------------------------------------
		  http.end();
		  idx = idx + 1;
	   }
	  
	 }
	 
}

void Ikony_adresy()
{
	  Serial.print("    ikony   ");
	  // tft.setCursor(10, 10);
	  // tft.print("  ");
	  // tft.print("B2");
	     
	  for (int idx = 0; idx <= 5;)
	  {
		 // Serial.print("-------Adres-------");
		 // Serial.println(Ikona[idx]);
		  //-----------------png lub jpeg------dodanie do nazwy  ------------
		  String myString =  Ikona[idx];
		  myString.replace("large", "thumb");
		 // Serial.println(myString);
		  //-------------------png PNG--------------
		  if ( myString.indexOf(".PNG?")>0|| myString.indexOf(".png?")> 0)
		  {
			  Symbol_coin[idx]= Symbol_coin[idx] + ".png";
		  }
		  //-----------------jprg-----------------
		  if ( myString.indexOf(".jpeg?")>0|| myString.indexOf(".jpg?")>0)
		  {
			  Symbol_coin[idx] = Symbol_coin[idx]+ ".jpeg";
		  }
		  //--------------------------------------
		  //-----------------------------------------
		  // Serial.print("-------fil Name--------");
		  // Serial.println(Name_png[idx]);
		  //tft.print(Name_png[idx]);
		  //-----------------------------------------------
		  downloadAndSaveFile(Symbol_coin[idx], myString);

		  // int x=22;
		  // int y=6+y;
		  //  String nazwa_png=Name_png[idx];
		  // Tft_Print_Png_Jpeg(nazwa_png,x,y);
		  idx=idx+1;
	  }
}
//------------------------------------
void ekran_6pozycji()
{
	//tft.fillScreen(TFT_hNAVY );
	// Serial.print("=======print_top7()========");
	//tft.setCursor(10, 10);
	
	//tft.fillRoundRect(2,2,75,38,3, TFT_HHNAVY); tft.fillRoundRect(80,2,76,38,3, TFT_HHNAVY);
	//tft.fillRoundRect(2,44,75,38,3, TFT_HHNAVY);tft.fillRoundRect(80,44,76,38,3, TFT_HHNAVY);
	//tft.fillRoundRect(2,86,75,38,3, TFT_HHNAVY);tft.fillRoundRect(80,86,76,38,3, TFT_HHNAVY);
	
}
void print_main_coin()
{

	//==========================================================================
	y = 5;
	x=20;
	for (int idx = 0; idx <= 5;)
	{
		//--usuwa .png .jpeg myString.remove(index);
		String Symbol = Symbol_coin[idx];
		Symbol.replace(".png", " ");
		Symbol.replace(".jpeg", " ");
		String nazwa_png = Symbol_coin[idx];
		//Serial.print("nazwa_pliku  ");
		//Serial.println(Name_png[idx]);
		
		if(idx==0)
		{
			x=62;
			y=16;//7
			tft.fillRoundRect(2,10,75,38,3, TFT_HHNAVY); 
			
		}
		if (idx==1)
		{
			x=140;
			y=16;//7
			tft.fillRoundRect(80,10,76,38,3, TFT_HHNAVY);
		}
		//--------------------------
		if (idx==2)
		{
			x=62;
			y=56;//50
           tft.fillRoundRect(2,50,75,38,3, TFT_HHNAVY);
		}
		if (idx==3)
		{
			x=140;
			y=56;//50
			tft.fillRoundRect(80,50,76,38,3, TFT_HHNAVY);
			
		}
		//--------------------------
		if (idx==4)
		{
			x=62;
			y=95;
			tft.fillRoundRect(2,89,75,38,3, TFT_HHNAVY);
		}
		if (idx==5)
		{
			x=140;
			y=95;
			tft.fillRoundRect(80,89,76,38,3, TFT_HHNAVY);
		}

		tft.setTextColor(TFT_YELLOW, TFT_HHNAVY);
		tft.setCursor(x-50, y-3);
		// tft.drawRoundRect(x-54,y-5,x+6,y+36,5,TFT_WHITE);
		// tft.fillRoundRect(270-(i*20), 70+(i*20), 60, 60, 3, col);
		tft.print(Symbol);
		
		//-----------------------------
		tft.setTextColor(TFT_GREY, TFT_HHNAVY);
		tft.setCursor(x-58, y+8);
		tft.print("$ ");
		tft.setCursor(x-58, y+19);
		tft.print("% ");
		
		
		tft.setCursor(x-50, y+8);
		String myString = Current_price[idx];
		String sub = myString.substring(0, 6);
		tft.setTextColor(TFT_GREYlight, TFT_HHNAVY);
		tft.print(sub);
		
		tft.setCursor(x-50, y+19);
		String myString1 =Price_change_percentage_24h[idx];
		 int change24=myString1.toInt();
		 if(change24>0)
		 {
			 tft.setTextColor(TFT_GREEN, TFT_HHNAVY);//green
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
		
		//------------------------------
		Tft_Print_Png_Jpeg(Symbol_coin[idx], x-10, y);
		idx=idx+1;
		delay(500);
	}
}
