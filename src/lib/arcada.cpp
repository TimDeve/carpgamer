#include <Adafruit_Arcada.h>

#include "arcada.h"

Adafruit_Arcada arcada;

GFXcanvas16 *canvas;

void InitArcada()
{
  if (!arcada.arcadaBegin())
  {
    Serial.print("Failed to start Arcada");
    while (true)
      ;
  }
}

void InitDisplay()
{
  arcada.displayBegin();
}

void SetBacklight(uint8_t brightness)
{
  arcada.setBacklight(brightness);
}

void FillScreen(uint16_t color)
{
  arcada.display->fillScreen(color);
}

void DrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
  arcada.display->drawRect(x, y, w, h, color);
}

void CanvasInit(int w, int h)
{
  if (!arcada.createFrameBuffer(w, h))
  {
    arcada.haltBox("Failed to allocate framebuffer");
  }
  canvas = arcada.getCanvas();
}

void CanvasFillScreen(uint16_t color)
{
  canvas->fillScreen(color);
}

void CanvasDrawFilledRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
  canvas->fillRect(x, y, w, h, color);
}

void CanvasDrawFilledCirc(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
  canvas->fillCircle(x0, y0, r, color);
}

void CanvasBlit(int x, int y)
{
  arcada.blitFrameBuffer(x, y);
}

uint32_t ReadButtons()
{
  return arcada.readButtons();
}

uint32_t JustPressedButtons()
{
  return arcada.justPressedButtons();
}

uint32_t JustReleasedButtons()
{
  return arcada.justReleasedButtons();
}

bool WasButtonAPressed(uint8_t buttons)
{
  return buttons & ARCADA_BUTTONMASK_A;
}

bool WasButtonBPressed(uint8_t buttons)
{
  return buttons & ARCADA_BUTTONMASK_B;
}

bool WasButtonStartPressed(uint8_t buttons)
{
  return buttons & ARCADA_BUTTONMASK_START;
}

bool WasButtonSelectPressed(uint8_t buttons)
{
  return buttons & ARCADA_BUTTONMASK_SELECT;
}

bool WasButtonUpPressed(uint8_t buttons)
{
  return buttons & ARCADA_BUTTONMASK_UP;
}

bool WasButtonRightPressed(uint8_t buttons)
{
  return buttons & ARCADA_BUTTONMASK_RIGHT;
}

bool WasButtonDownPressed(uint8_t buttons)
{
  return buttons & ARCADA_BUTTONMASK_DOWN;
}

bool WasButtonLeftPressed(uint8_t buttons)
{
  return buttons & ARCADA_BUTTONMASK_LEFT;
}

int16_t ReadJoystickX()
{
  return arcada.readJoystickX();
}

int16_t ReadJoystickY()
{
  return arcada.readJoystickY();
}
