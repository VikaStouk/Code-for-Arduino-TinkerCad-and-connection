// C++ code
//
#ifndef GraphicsLib_h
#define GraphicsLib_h

#ifndef R_G_B
#define R_G_B(r,g,b) ((r&0xF8)<<8|(g&0xFC)<<3|(b&0xF8)>>3) //RGB565: 5red | 6green| 5 blue
#endif

class GraphicsLib
{
public:
    //    GraphicsLib(uint_least16_t w, uint_least16_t h) { width=w; height=h; };

    int_least16_t getWidth(void) { return width; };
    int_least16_t getHeight(void) { return height; };

    virtual void fillScreen(uint_least16_t color) = 0;

    virtual void drawPixel(int_least16_t x0, int_least16_t y0, uint_least16_t color) = 0;

    virtual void drawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1, uint_least16_t color) = 0;

    virtual void drawRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) = 0;

    virtual void fillRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) = 0;

    virtual void drawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) = 0;

    virtual void fillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) = 0;

    virtual int_least16_t drawChar(int_least16_t x, int_least16_t y, char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) = 0;

    virtual int_least16_t drawChar(int_least16_t x, int_least16_t y, unsigned char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) = 0;

    virtual int_least16_t drawText(int_least16_t x, int_least16_t y, const char* s, uint_least16_t color, uint_least16_t bg, uint_least8_t size) = 0;

private:
    int_least16_t width, height; //screen size
};

#endif //GraphicsLib_h
//////////////////////////////////////////////////////////////


class graphLib : GraphicsLib
{
public:
    //graphLib(uint_least16_t w, uint_least16_t h) {width = w; height = h; };

    int_least16_t getWidth(void) { return width; };
    int_least16_t getHeight(void) { return height; };

    void fillScreen(uint_least16_t color) override {
        String srv_cmd = "1 " + rgb16_to_24(color);
        Serial.println(srv_cmd);
    }
    void drawPixel(int_least16_t x0, int_least16_t y0, uint_least16_t color) override {
        String srv_cmd = "2 ";
        srv_cmd = srv_cmd + x0 + " " + y0 + " " + rgb16_to_24(color);
        Serial.println(srv_cmd);
    }
    void drawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1, uint_least16_t color)override {
        String srv_cmd = "3 ";
        srv_cmd = srv_cmd + x0 + " " + y0 + " " + x1 + " " + y1 + " " + rgb16_to_24(color);
        Serial.println(srv_cmd);
    }
    void drawRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color)override {
        String srv_cmd = "4 ";
        srv_cmd = srv_cmd + x0 + " " + y0 + " " + w + " " + h + " " + rgb16_to_24(color);
        Serial.println(srv_cmd);
    }
    void fillRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color)override {
        String srv_cmd = "5 ";
        srv_cmd = srv_cmd + x0 + " " + y0 + " " + w + " " + h + " " + rgb16_to_24(color);
        Serial.println(srv_cmd);
    }
    void drawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color)override {
        String srv_cmd = "6 ";
        srv_cmd = srv_cmd + x0 + " " + y0 + " " + r_x + " " + r_y + " " + rgb16_to_24(color);
        Serial.println(srv_cmd);
    }
    void fillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color)override {
        String srv_cmd = "7 ";
        srv_cmd = srv_cmd + x0 + " " + y0 + " " + r_x + " " + r_y + " " + rgb16_to_24(color);
        Serial.println(srv_cmd);
    }
    int_least16_t drawChar(int_least16_t x, int_least16_t y, char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size)override {
        return 0;
    }
    int_least16_t drawChar(int_least16_t x, int_least16_t y, unsigned char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size)override {
        return 0;
    }

    int_least16_t drawText(int_least16_t x, int_least16_t y, const char* s, uint_least16_t color, uint_least16_t bg, uint_least8_t size)override {
        String srv_cmd = "10 ";
        srv_cmd = srv_cmd + x + " " + y + " " + s + " Arial " + size + " " + rgb16_to_24(color);
        Serial.println(srv_cmd);
    }



private:
    int_least16_t width = 1000, height = 600; //screen size

    String rgb16_to_24(uint_least16_t color) {
        String s = "";
        uint_least16_t colR = (color & 0xF800) >> 8;
        uint_least16_t colG = (color & 0x07E0) >> 3;
        uint_least16_t colB = (color & 0x001F) << 3;
        s = s + colR + " " + colG + " " + colB;
        return s;
    }
};

/////////////////////////////////////////////////////////

graphLib glib;// = graphLib(1000, 600);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    for (byte i = 2; i < 10; i++)
    {
        pinMode(i, INPUT_PULLUP);
    }

}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500); // Wait for 1000 millisecond(s)
    digitalWrite(LED_BUILTIN, LOW);
    delay(500); // Wait for 1000 millisecond(s)

    if (digitalRead(2) == 0)
        glib.fillScreen(R_G_B(0, 0, 0));

    if (digitalRead(3) == 0)
        glib.drawPixel(255, 255, 255);

    if (digitalRead(4) == 0)
        glib.drawLine(60, 60, 120, 120, R_G_B(0, 255, 0));

    if (digitalRead(5) == 0)
        glib.drawRect(120, 60, 120, 120, R_G_B(255, 0, 0));

    if (digitalRead(6) == 0)
        glib.fillRect(180, 200, 100, 150, R_G_B(0, 0, 255));

    if (digitalRead(7) == 0)
        glib.drawEllipse(250, 100, 150, 100, R_G_B(255, 255, 0));

    if (digitalRead(8) == 0)
        glib.fillEllipse(300, 200, 100, 150, R_G_B(0, 255, 255));

}