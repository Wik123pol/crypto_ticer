//--------------------------------------------------
void downloadAndSaveFile(String fileName, String  url)
{
	//  tft.setCursor(10, 10);
	 // tft.print("B3--");
  //---------png lub jpeg-------
  String myString = url;
  int index = myString.indexOf(".png?");
  if (index > 0)
  {
    fileName = "/" + fileName;
    // Serial.print("-------PNG--------");
  }
  if (index < 0)
  {
    fileName = "/" + fileName;
    // Serial.print("------JPEG--------");
  }
  //------if file name  exist return-----
  //-------------------------------------
  setClock();
  Serial.println(fileName );
  if ((WiFi.status() == WL_CONNECTED))
  {
  //-------------------------------------
  client.setCACert(test_root_ca);
  HTTPClient http;
  // Serial.println ("-------zapis obrazka--------");
  //--------------------------------------------
  http.begin(url);
  int httpCode = http.GET();
  delay(100);
  if (httpCode > 0) {
    File file = SPIFFS.open(fileName, FILE_WRITE);
    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      // get lenght of document (is -1 when Server sends no Content-Length header)
      int len = http.getSize();
      uint8_t buff[512] = { 0 };//128
      WiFiClient * stream = http.getStreamPtr();
      while (http.connected() && (len > 0 || len == -1)) {
        size_t size = stream->available();
        if (size) {
          int c = stream->readBytes(buff, ((size > sizeof(buff)) ? sizeof(buff) : size));
          file.write(buff, c);
          if (len > 0) {
            len -= c;
          }
        }
      }
      file.close();
    }
  }
  else {
	  Serial.print("======downloadAndSave====http error============");
	  Serial.print(httpCode);
	  http.end();
	  WiFi.disconnect();
	  WiFi.reconnect();
	  return;
  }
  http.end();
  }

}
//---------------------------------------------------------------------------------------
