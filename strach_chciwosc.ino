//https://api.alternative.me/fng/?limit=10&format=csv&date_format=us
//https://api.alternative.me/fng/?limit=10
//https://alternative.me/crypto/api/
//Fear and Greed index
///* certyfikat
const static char * ca_strach_chciwosc PROGMEM = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIFSTCCBDGgAwIBAgISBAqeCy58eK44Zl9GimTBPhA0MA0GCSqGSIb3DQEBCwUA\n" \
"MDIxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQswCQYDVQQD\n" \
"EwJSMzAeFw0yMjExMjcwMDM4MTJaFw0yMzAyMjUwMDM4MTFaMBkxFzAVBgNVBAMT\n" \
"DmFsdGVybmF0aXZlLm1lMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n" \
"rse/9uJ661etK4PsjWA0gKHDCw+oeM5dgPowUIpFBlt/9pT169GJgQWiJueoQ5kS\n" \
"z5e2/ReiBYWs3K8NvPocuy4onbohbs65MmDQEGGw5Gzzxrt5Tev7odSII/VI7I4V\n" \
"FFh/Xy5dfFr9D2RWv9PWuD9nidfrtcQYxRaAIWYMka3BgoKCupedQa7AS0oVOzhx\n" \
"2umTA3q+EPuroxnlKXHreM8UnwGYwBVGcE9/D9KZV80GmnTeXfQOJv8FrG4a+i1U\n" \
"l/Alm0bEGPjaUIGM/4wxQvBINr4WRT4z2qB6AfTnM6T61TvGliyY4aOSQYxP5HAP\n" \
"zZC9EJNOES/aq3d0RcxRowIDAQABo4ICcDCCAmwwDgYDVR0PAQH/BAQDAgWgMB0G\n" \
"A1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjAMBgNVHRMBAf8EAjAAMB0GA1Ud\n" \
"DgQWBBSdORtGxowvrkpHQcfBL6/krvTUpjAfBgNVHSMEGDAWgBQULrMXt1hWy65Q\n" \
"CUDmH6+dixTCxjBVBggrBgEFBQcBAQRJMEcwIQYIKwYBBQUHMAGGFWh0dHA6Ly9y\n" \
"My5vLmxlbmNyLm9yZzAiBggrBgEFBQcwAoYWaHR0cDovL3IzLmkubGVuY3Iub3Jn\n" \
"LzBBBgNVHREEOjA4gg5hbHRlcm5hdGl2ZS5tZYISYXBpLmFsdGVybmF0aXZlLm1l\n" \
"ghJ3d3cuYWx0ZXJuYXRpdmUubWUwTAYDVR0gBEUwQzAIBgZngQwBAgEwNwYLKwYB\n" \
"BAGC3xMBAQEwKDAmBggrBgEFBQcCARYaaHR0cDovL2Nwcy5sZXRzZW5jcnlwdC5v\n" \
"cmcwggEDBgorBgEEAdZ5AgQCBIH0BIHxAO8AdgB6MoxU2LcttiDqOOBSHumEFnAy\n" \
"E4VNO9IrwTpXo1LrUgAAAYS2vB65AAAEAwBHMEUCIAlx3YVnA4K+hk8LQlprRvEJ\n" \
"DXQ4h29pg2qBr3i1ZT8KAiEA0SOqOG8CWJjbii814Tt0neteuevz0E4b/WCU3l+g\n" \
"8bkAdQCt9776fP8QyIudPZwePhhqtGcpXc+xDCTKhYY069yCigAAAYS2vB7AAAAE\n" \
"AwBGMEQCIEP3NYid4Gml1vEVK6dw0jph19RPWAq/9xknfWz/OzhIAiBk3gpbsd1+\n" \
"4O9XrcCXShnCXz21QK2LP2/F3irob/CgezANBgkqhkiG9w0BAQsFAAOCAQEAceSF\n" \
"JtoUGDBrqnXgLqUqtMWTKa+l6pEihiYnYp9R9/YPlTOqcfQhZ8k3U2uG3gqwmsTf\n" \
"J1qytUyAopYgZq25p0HEmbbwvzTdWlh/tvod5n8/rb0rJd5EY3mFjVFQ3P7vMeyV\n" \
"ZHOjo/o8vt+yPsMtS2B6gJiIWbONEcBGWFJ86jXd7i7/LcoMp91xYFQ7D5B5oeDy\n" \
"atHJ8vqi+L0fxoATP3ICYMrYv/aHv2NtFrtFRb0jU8Y1a/1RyPCvlusz2AErp4NE\n" \
"f8/CcZFEYc/CvV48NpVCQLstRwnGu283+iI+BdxSfqQgB8tnayzDcaydjN8QyDtB\n" \
"gE0PCGjVBzImNzpbWA==\n" \
"-----END CERTIFICATE-----\n" ;


void Fear_and_Greed()
{
	// sprawdzenie polaczenia wifi
	if ((WiFi.status() == WL_CONNECTED))
	{
		
		tft.setCursor(10, 10);
		//tft.print("CENA");
		WiFiClientSecure client;
		client.setCACert(ca_strach_chciwosc);
		HTTPClient http;
		delay(200);
	//	Serial.println ("-------cena-ikona srednia itp-----");
	
	 // polaczenie z serwerem
	 //https://api.alternative.me/fng/?limit=1 jeden wynik
	 //https://api.alternative.me/fng/?limit=10&format=csv&date_format=us wykres
	 
	  http.begin ("https://api.alternative.me/fng/?limit=1");
	  int httpCode = http.GET();
	  delay(20);
	  if (httpCode > 0)
	  {
	
	  	 payload = http.getString();
		// Serial.print(payload);
		// deserialzacja doc jason
		 DynamicJsonDocument doc(500);
		 DeserializationError error = deserializeJson(doc, payload);
		if (error) 
		{
			return;
		}
		
        JsonObject object = doc.as<JsonObject>();
        Tytul = object["name"].as<String>();
        Skala = object["data"][0]["value"].as<String>();
        StrachChciwosc = object["data"][0]["value_classification"].as<String>();
		Serial.print(Tytul);
		Serial.print(Skala);
		Serial.print(StrachChciwosc);
	}
   http.end();
	}
	
	
}

void wyswietl_fear_greed()
{
	Fear_and_Greed();
	
	//tft.fillRoundRect(0,0,160,10,3, TFT_CHART);
	String strachchciwosc = " " + Skala + " " + StrachChciwosc+ " ";
	tft.setCursor(15,1);
	tft.setTextColor(TFT_YELLOW,TFT_hNAVY);
   //  tft.print(strachchciwosc);
   tft.drawString(strachchciwosc, 15, 1, 1);
   //  Baner_BILD();
	
}

void wyswietl_fear_greed_baner()
{
	Fear_and_Greed();
//	String strachchciwosc = Tytul + " " + Skala + " " + StrachChciwosc;
	Baner_BILD();
	
}
