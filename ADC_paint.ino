#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX/Adafruit_GFX.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET );

int pinX = A0; 
int pinY = A1;
int reset = 9;
int tft_outX_old = 64;
int tft_outY_old = 32;
//int tft_outX, tft_outY;


void setup() 
{

	display.begin( SSD1306_SWITCHCAPVCC, 0x3C);
	display.clearDisplay();
	pinMode(pinX, INPUT);
	pinMode(pinY, INPUT);
	pinMode(reset, INPUT_PULLUP);

}

void loop(void) 
{
	int joyX = analogRead(pinX);
	int joyY = analogRead(pinY);

	int res = digitalRead(reset);
		if (res == LOW)
		{
			display.clearDisplay();
			//display.display();
		}

	//int tft_outX_old = map(joyX, 0, 1023, 127, 0);
	//int tft_outY_old = map(joyY, 0, 1023, 0, 63);

	int tft_outX = map(joyX, 0, 1023, 127, 0);
	int tft_outY = map(joyY, 0, 1023, 0, 63);

	display.drawLine(tft_outX_old, tft_outY_old, tft_outX, tft_outY, WHITE);
	display.display();

	tft_outX_old = tft_outX;
	tft_outY_old = tft_outY;
	
	//display.drawPixel(tft_outX, tft_outY, WHITE);
	
	//tft.drawPixel(tft_outX, tft_outY, ILI9340_RED);
	//delay(50);
}