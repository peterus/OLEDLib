#include <Arduino.h>
#include <unity.h>
#include <SSD1306.h>

SSD1306 * display;

void setUp()
{
#ifdef OLED_RST
	pinMode(OLED_RST, OUTPUT);
	digitalWrite(OLED_RST, HIGH);
	delay(1);
	digitalWrite(OLED_RST, LOW);
	delay(10);
	digitalWrite(OLED_RST, HIGH);
#endif
	Wire.begin(OLED_SDA, OLED_SCL);
	display = new SSD1306(&Wire, 0x3C);
	display->setBrightness(1);
}

void test_empty()
{
	Bitmap bitmap(display);
	display->display(&bitmap);
}

void test_draw_line()
{
	Bitmap bitmap(display);
	bitmap.drawLine(0, 0, display->getWidth() / 2, display->getHeight() / 2);
	bitmap.drawHorizontalLine(display->getWidth() / 4, display->getHeight() / 2, display->getWidth() / 2);
	bitmap.drawVerticalLine(display->getWidth() / 2, display->getHeight() / 4, display->getHeight() / 2);
	display->display(&bitmap);
}

void test_draw_rect()
{
	Bitmap bitmap(display);
	bitmap.drawRect(0, 0, display->getWidth() / 2, display->getHeight() / 2);
	bitmap.fillRect(display->getWidth() / 2, 0, display->getWidth() / 2, display->getHeight() / 2);
	display->display(&bitmap);
}

void test_draw_circle()
{
	Bitmap bitmap(display);
	bitmap.drawCircle(display->getWidth() / 4, display->getHeight() / 4, display->getHeight() / 4);
	bitmap.fillCircle(display->getWidth() / 4 * 3, display->getHeight() / 4 * 3, display->getHeight() / 4);
	bitmap.drawCircleQuads(display->getWidth() / 4, display->getHeight() / 4 * 3, display->getHeight() / 4, 0b00000110);
	bitmap.drawCircleQuads(display->getWidth() / 4 * 3, display->getHeight() / 4, display->getHeight() / 4, 0b00001001);
	display->display(&bitmap);
}

void test_draw_progress_bar()
{
	Bitmap bitmap(display);
	bitmap.drawProgressBar(0, 0, display->getWidth() / 2, display->getHeight() / 2, 0);
	bitmap.drawProgressBar(display->getWidth() / 2, 0, display->getWidth() / 2, display->getHeight() / 2, 25);
	bitmap.drawProgressBar(0, display->getHeight() / 2, display->getWidth() / 2, display->getHeight() / 2, 50);
	bitmap.drawProgressBar(display->getWidth() / 2, display->getHeight() / 2, display->getWidth() / 2, display->getHeight() / 2, 75);
	display->display(&bitmap);
}

void test_draw_char()
{
	Bitmap bitmap(display);
	int next_x = 0;
	next_x = bitmap.drawChar(0, 0, 'A');
	next_x = bitmap.drawChar(next_x, 0, 'B');
	next_x = bitmap.drawChar(next_x, 0, 'C');
	next_x = bitmap.drawChar(next_x, 0, 'D');
	next_x = bitmap.drawChar(next_x, 0, 'E');
	next_x = bitmap.drawChar(next_x, 0, 'F');
	next_x = bitmap.drawChar(next_x, 0, 'G');
	bitmap.drawString(0, 20, "ABCDEFG");
	char buffer[20];
	bitmap.drawStringf(0, 40, buffer, "ABC%c%c%s", 'D', 'E', "FG");
	display->display(&bitmap);
}

void test_draw_bitmap()
{
	//Bitmap bitis(20, 20);
	//bitis.drawLine(0, 0, 19, 19);
	//bitis.drawLine(0, 20, 20, 0);
	Bitmap bitmap(display);
	bitmap.setPixel(display->getWidth() - 1, display->getHeight() - 1);
	//bitmap.drawBitmap(0, 0, bitis);
	//bitmap.drawBitmap(25, 25, bitis);
	//bitmap.drawBitmap(100, 0, bitis);
	display->display(&bitmap);
}

void setup()
{
	UNITY_BEGIN();
	//RUN_TEST(test_draw_line);
	//delay(1000);
	//RUN_TEST(test_empty);
	//delay(1000);
	RUN_TEST(test_draw_line);
	delay(1000);
	RUN_TEST(test_draw_rect);
	delay(1000);
	RUN_TEST(test_draw_circle);
	delay(1000);
	RUN_TEST(test_draw_progress_bar);
	delay(1000);
	RUN_TEST(test_draw_char);
	delay(1000);
	//RUN_TEST(test_draw_bitmap);
	//delay(1000);
	UNITY_END();
}

void loop()
{
}
