//////////////////////////////////////////////////////////
void Baner_crypto()
{
	tft.setSwapBytes(true);
	//background.pushImage(0,0,192,128,btc2);
	//background.pushSprite(0,0);
	tft.pushImage(0, 0,192,128,btc2);
	 tft.setSwapBytes(false);
}
void ekran_startowy_laczenie()
{
	tft.setSwapBytes(true);
	tft.pushImage(0,0,179,140 ,crypto160X140);
	//background.pushImage(0,0,179,140 ,crypto160X140);
	//background.pushSprite(0,0);
	 tft.setSwapBytes(false);
    tft.setTextSize(1);
	tft.setCursor(50, 30);
	tft.print("connecting  ");
	tft.setCursor(20, 50);
	tft.print("to a wifi network");
	
	
  // setClock();
  // tft.setCursor(125,1);
  // tft.print(&timeinfo,  "%H:%M");
   delay(1000);

   
}


void ekran_startowy_polaczony()
{
	tft.setSwapBytes(true);
	// background.pushImage(0,0,179,140 ,crypto160X140);
	// background.pushSprite(0,0);
	 tft.pushImage(0, 0,192,128,btc2);
	 tft.setSwapBytes(false);
	for(int idx=0;idx<5;idx++)
	{

	tft.setCursor(50, 60);
	tft.print(WiFi.SSID());
	tft.setCursor(50, 80);
	tft.print(WiFi.localIP());
	 time_style=1;
     setClock();
	 delay(200);
	}
	 
	// ekran_startowy_polaczony();
}
