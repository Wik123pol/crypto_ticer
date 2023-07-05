void Baner_BILD()
{
	// int T_baner=
	// Budowaniw_textu();
	textBaner= textBaner1;
	tft.setCursor(5, 70);
	img.createSprite(IWIDTH, IHEIGHT);
	//img.fillSprite(TFT_BLACK); // Optional here as we fill the sprite later anyway
	for (int pos = IWIDTH; pos > 0; pos--)
	{
		build_banner(textBaner , pos);
		img.pushSprite(0, 50);
		delay(20);
	}
	img.deleteSprite();
	
}
//-------------------bilrd baner-----------

void build_banner(String msg, int xpos)
{
	int h = IHEIGHT;
	while (h--)
	img.fillSprite(TFT_hNAVY);

	// Now print text on top of the graphics
	img.setTextSize(1);           // Font size scaling is x1
	img.setTextFont(2);           // Font 4 selected
	img.setTextColor(TFT_GREY);  // Black text, no background colour
	img.setTextWrap(false);       // Turn of wrap so we can print past end of sprite

	// Need to print twice so text appears to wrap around at left and right edges
	img.setCursor(xpos, 0);  // Print text at xpos
	img.print(msg);

	img.setCursor(xpos - IWIDTH, 2); // Print text at xpos - sprite width
	img.print(msg);
}
