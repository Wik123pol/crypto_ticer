

void odczyt_png()
{
  xpos = 30;
  ypos = 30;
  Png_name = "SHIB.png";

  // Scan LittleFS and load any *.png files
  File root = SPIFFS.open("/", "r");
  while (File file = root.openNextFile())
  {
    String strname = file.name(); //"MASK.png";// file.name();
    strname = "/" + strname;
    Serial.println(strname);
    Serial.println(file.name());
	//--------------------------png------------------------------
    if (!file.isDirectory() && strname.endsWith(".png"))
    {
      int16_t rc = png.open(strname.c_str(), pngOpen, pngClose, pngRead, pngSeek, pngDraw);
      if (rc == PNG_SUCCESS)
      {
        tft.startWrite();
        rc = png.decode(NULL, 0);
        png.close();
        tft.endWrite();
      }
    }
    //----------------------------jpeg---------------------------
    if (!file.isDirectory() && strname.endsWith(".jpeg"))
    {
      // bool decoded = JpegDec.decodeSdFile(file);  // Pass the SD file handle to the decoder,
      bool decoded = JpegDec.decodeSdFile(file);  // or pass the filename (String or character array)

      if (decoded) {
        // print information about the image to the serial port
        //jpegInfo();
        // render the image onto the screen at given coordinates
        jpegRender(xpos, ypos);
      }

    }
    //---------------------------
    //delay(800);
  }

}

//---------------jeden plik--------------------------
//listDir(SPIFFS, "/", 0);
//readFile(SPIFFS, "/MASK.png");

//     symbolB.toLowerCase();
//     String sciezka_do_pliku = "/" + symbolB + ".raw";
//     char buf[50];
//     sciezka_do_pliku.toCharArray(buf, 50);
//     drawRaw(buf, 120, 10, 32, 32);//70 80

void Tft_Print_Png_Jpeg(String sciezka_do_pliku, int x, int y)
{
  sciezka_do_pliku = "/" + sciezka_do_pliku;
  xpos = x;
  ypos = y;
  // String sciezka_do_pliku = "/DOGE.png";
  char buf[50];
  sciezka_do_pliku.toCharArray(buf, 50);
  File file = SPIFFS.open(buf, "r");
  if (!file.isDirectory() && sciezka_do_pliku .endsWith(".png"))
  {
    //  Serial.write(file.read());
    int16_t rc = png.open(sciezka_do_pliku .c_str(), pngOpen, pngClose, pngRead, pngSeek, pngDraw);
    if (rc == PNG_SUCCESS)
    {
      tft.startWrite();
      rc = png.decode(NULL, 0);
      png.close();
      tft.endWrite();
    }
  }
  //----------------------------jpeg---------------------------
  if (!file.isDirectory() && sciezka_do_pliku.endsWith(".jpeg"))
  {
    // bool decoded = JpegDec.decodeSdFile(file);  // Pass the SD file handle to the decoder,
    bool decoded = JpegDec.decodeSdFile(file);  // or pass the filename (String or character array)

    if (decoded) {
      // print information about the image to the serial port
      //jpegInfo();
      // render the image onto the screen at given coordinates
      jpegRender(xpos, ypos);
    }

  }
  //-------------------------------------------------------------
  file.close();
  //delay(5000);
}



//-----------------------------------------------------------
//------------------pngwyswietla pliki png ------------------
void pngDraw(PNGDRAW *pDraw) {
  uint16_t lineBuffer[MAX_IMAGE_WDITH];
  png.getLineAsRGB565(pDraw, lineBuffer, PNG_RGB565_BIG_ENDIAN, 0xffffffff);
  tft.pushImage(xpos, ypos + pDraw->y, pDraw->iWidth, 1, lineBuffer);
}
////////////////////////////////////////////////////
///------------------png suport------------------////

void * pngOpen(const char *filename, int32_t *size) {
  // Serial.printf("Attempting to open %s\n", filename);
  pngfile = SPIFFS.open(filename, "r");
  *size = pngfile.size();
  return &pngfile;
}

void pngClose(void *handle) {
  File pngfile = *((File*)handle);
  if (pngfile) pngfile.close();
}

int32_t pngRead(PNGFILE *page, uint8_t *buffer, int32_t length) {
  if (!pngfile) return 0;
  page = page; // Avoid warning
  return pngfile.read(buffer, length);
}

int32_t pngSeek(PNGFILE *page, int32_t position) {
  if (!pngfile) return 0;
  page = page; // Avoid warning
  return pngfile.seek(position);
}

//----------------------------------------------------------------
