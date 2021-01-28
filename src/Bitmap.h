#ifndef BITMAP_H_
#define BITMAP_H_

#include <Arduino.h>
#include <memory>

/*#define WIDTH_POS 0
#define HEIGHT_POS 1
#define FIRST_CHAR_POS 2
#define CHAR_NUM_POS 3

enum OLEDDISPLAY_TEXT_ALIGNMENT
{
	TEXT_ALIGN_LEFT = 0,
	TEXT_ALIGN_RIGHT = 1,
	TEXT_ALIGN_CENTER = 2,
	TEXT_ALIGN_CENTER_BOTH = 3
};*/

class OLEDDisplay;

class Bitmap
{
public:
	Bitmap(uint width, uint height);
	Bitmap(OLEDDisplay * display);
	virtual ~Bitmap();

	uint getWidth() const;
	uint getHeight() const;

	void setPixel(int x, int y);
	void clearPixel(int x, int y);
	bool getPixel(int x, int y) const;
	void clear();

	void drawLine(int x0, int y0, int x1, int y1);
	void drawHorizontalLine(int x, int y, int length);
	void drawVerticalLine(int x, int y, int length);

	void drawRect(int x, int y, int width, int height);
	void fillRect(int x, int y, int width, int height);

	void drawCircle(int x0, int y0, int radius);
	void fillCircle(int x0, int y0, int radius);
	void drawCircleQuads(int x0, int y0, int radius, int quads);

	void drawProgressBar(int x, int y, int width, int height, int progress);

	int drawChar(int x, int y, char c);
	void drawString(int x, int y, String text);
	void drawStringf(int x, int y, char * buffer, String format, ... );

	void drawBitmap(int x, int y, const Bitmap & bitmap);

private:
	const uint _width;
	const uint _height;

	//std::shared_ptr<uint8_t> _buffer;
	uint8_t * _buffer;
	//uint8_t ** _buffer;

	void allocateBuffer();

	friend class SSD1306;
};

#endif
